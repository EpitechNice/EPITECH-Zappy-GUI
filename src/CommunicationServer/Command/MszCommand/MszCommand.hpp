/*
** EPITECH PROJECT, 2024
** gui
** File description:
** MszCommand
*/

#ifndef SCENE_MSZCOMMAND_HPP_
    #define SCENE_MSZCOMMAND_HPP_

#include "ICommand.hpp"

namespace Zappy {
    namespace GUI {
        class MszCommand : public ICommand {
        public:
            MszCommand(const std::string& info);
            ~MszCommand() override;

            void parseCommand(const std::string& info) override;
            void execCommand() override;

        private:
            int _heightWorld;
            int _widthWorld;
        };
    }
}

#endif /* !SCENE_MSZCOMMAND_HPP_ */
