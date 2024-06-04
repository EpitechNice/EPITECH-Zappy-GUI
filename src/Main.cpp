/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Main
*/

#include <iostream>

#include "Parsing.hpp"
#include "SceneManager.hpp"

int main(int argc, char **argv)
{
    try {
        srand(time(NULL));
        Zappy::GUI::Parsing parsing(argc, argv);
        std::cout << "Port: " << parsing.getPort() << std::endl;
        std::cout << "Machine: " << parsing.getMachine() << std::endl;
        Zappy::GUI::SceneManager sceneManager;
        sceneManager.run();
    } catch (const Zappy::GUI::Parsing::ParsingError &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        std::cerr << ">> Use -help for help." << std::endl;
        return 84;
    } catch (const Zappy::GUI::Parsing::Help &e) {
        e.what();
        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 84;
    }
    return 0;
}
