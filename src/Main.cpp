/*
** EPITECH PROJECT, 2024
** Zappy GUI
** File description:
** Main
*/

#include <iostream>
#include <thread>

#include "Parsing.hpp"
#include "SceneManager.hpp"
#include "Server.hpp"
#include "Thread.hpp"
#include "Ref.hpp"

void inThreadFunction(std::shared_ptr<Zappy::Server::Server> server)
{
    server->runIn();
}

void outThreadFunction(std::shared_ptr<Zappy::Server::Server> server)
{
    server->runOut();
}

//TODO : use Thread custom class
int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        Zappy::GUI::Parsing parsing(argc, argv);
        std::shared_ptr<Zappy::Server::Server> server = std::make_shared<Zappy::Server::Server>(parsing.getMachine(), parsing.getPort());
        server->setRessources(Zappy::GUI::Ressources::Ref::get()->ressources);
        std::shared_ptr<Zappy::Server::SharedMemory> sharedMemory = server->getSharedMemory();
        Zappy::Server::Thread responseThread;
        responseThread.start([server]() { inThreadFunction(server); });
        std::this_thread::sleep_for(std::chrono::milliseconds(10));  // wait for connection
        Zappy::Server::Thread commandThread;
        commandThread.start([server]() { outThreadFunction(server); });
        Zappy::GUI::SceneManager sceneManager;
        sharedMemory->addCommand("bct 1 3\r\n");
        // sharedMemory->addCommand("bct 2 1\r\n");
        // sharedMemory->addCommand("bct 2 2\r\n");
        sharedMemory->addCommand("mct\r\n");
        // sharedMemory->addCommand("ppo\r\n");
        sceneManager.run();
        server->shutdown();
        responseThread.join();
        commandThread.join();
    } catch (const Zappy::GUI::Parsing::ParsingError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << ">> Use -help for help." << std::endl;
        return 84;
    } catch (const Zappy::GUI::Parsing::Help &e) {
        e.what();
        return 0;
    } catch (const Exceptions::ConnectionServerFail &e) {
        std::cerr << "Server connection error: " << e.what() << std::endl;
        return 84;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
