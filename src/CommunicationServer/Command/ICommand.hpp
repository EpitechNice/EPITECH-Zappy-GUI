/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ICommand
*/

#ifndef SCENE_ICOMMAND_HPP_
    #define SCENE_ICOMMAND_HPP_

#include <string>
#include <iostream>
#include <sstream>

namespace Zappy {
    namespace GUI {
        class ICommand {
        public:
            virtual ~ICommand() = default;
            virtual void parseCommand(const std::string& info) = 0;
            virtual void execCommand() = 0;
        };
    }
}

#endif /* SCENE_ICOMMAND_HPP_ */
