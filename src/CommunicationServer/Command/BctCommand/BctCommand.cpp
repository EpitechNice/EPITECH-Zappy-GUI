/*
** EPITECH PROJECT, 2024
** gui
** File description:
** BctCommand.cpp
*/

#include "BctCommand.hpp"

namespace Zappy {
    namespace GUI {
        BctCommand::BctCommand(const std::string& info)
        {
            parseCommand(info);
        }

        BctCommand::~BctCommand() {
            // Destructor
        }

        void BctCommand::parseCommand(const std::string& info)
        {
            // Parsing logic
            execCommand();
        }

        void BctCommand::execCommand()
        {
            std::cout << "info bct:" << std::endl;
        }
    }
}
