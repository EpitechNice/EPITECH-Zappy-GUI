/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Option
*/

#include "OptionScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            void Option::start()
            {
            }

            void Option::event()
            {
            }

            void Option::draw3D()
            {
            }

            void Option::draw2D()
            {
                DrawText("Option", 10, 10, 20, GREEN);

                DrawText("1. Menu", 10, 30, 20, GREEN);
                DrawText("2. Game", 10, 50, 20, GREEN);
            }

            std::string Option::nextScene()
            {
                if (IsKeyReleased(KEY_ONE))
                    return "menu";
                if (IsKeyReleased(KEY_TWO))
                    return "game";
                return "option";
            }
        }
    }
}