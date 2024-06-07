/*
** EPITECH PROJECT, 2024
** gui
** File description:
** MszCommand.cpp
*/

#include "MszCommand.hpp"

namespace Zappy {
    namespace GUI {
MszCommand::MszCommand(const std::string& info) : _heightWorld(0), _widthWorld(0) {
            parseCommand(info);
        }

        MszCommand::~MszCommand() {
            // Destructor implementation if necessary
        }

        void MszCommand::parseCommand(const std::string& info) {
            std::istringstream iss(info);
            if (!(iss >> _heightWorld >> _widthWorld)) {
                std::cerr << "Error parsing size into integers" << std::endl;
            }
            execCommand();
        }

        void MszCommand::execCommand() {
            std::cout << "info msz: " << _heightWorld << " " << _widthWorld << std::endl;
        }
    }
}