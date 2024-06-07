/*
** EPITECH PROJECT, 2024
** gui
** File description:
** BctCommand
*/

#ifndef SCENE_BCTCOMMAND_HPP_
    #define SCENE_BCTCOMMAND_HPP_

#include "ICommand.hpp"

namespace Zappy {
    namespace GUI {
        class BctCommand : public ICommand {
        public:
            BctCommand(const std::string& info);
            ~BctCommand() override;

            void parseCommand(const std::string& info) override;
            void execCommand() override;
        };
    }
}

#endif /* SCENE_BCTCOMMAND_HPP_ */
