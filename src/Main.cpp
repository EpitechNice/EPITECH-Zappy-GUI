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

void threadFunction(std::shared_ptr<Zappy::Server::Server> server)
{
    server->run();
}

//TODO : use Thread custom class
int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        Zappy::GUI::Parsing parsing(argc, argv);
        std::shared_ptr<Zappy::Server::Server> server = std::make_shared<Zappy::Server::Server>(parsing.getMachine(), parsing.getPort());
        server->setRessources(Zappy::GUI::Ressources::Ref::get()->ressources);
        // create namepipe in and out
        // server.setInOut(in, out);
        std::shared_ptr<Zappy::Server::SharedMemory> sharedMemory = server->getSharedMemory();
        sharedMemory->addCommand("msz\r\n");
        sharedMemory->addCommand("bct 11 3\r\n");
        sharedMemory->addCommand("bct 2 1\r\n");
        sharedMemory->addCommand("bct 2 2\r\n");
        sharedMemory->addCommand("mct\r\n");
        Zappy::Server::Thread serverThread;
        serverThread.start([server]() { threadFunction(server); });
        Zappy::GUI::SceneManager sceneManager;
        sceneManager.run();
        server->shutdown();
        serverThread.join();
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
