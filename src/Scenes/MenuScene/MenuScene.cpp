/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Menu
*/

#include "MenuScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            void Menu::start()
            {
            }

            void Menu::event()
            {
            }

            void Menu::draw3D()
            {
            }

            void Menu::draw2D()
            {
                DrawText("Menu scene", 10, 10, 20, BLACK);

                DrawText("1. Play", 10, 40, 20, BLACK);
                DrawText("2. Option", 10, 70, 20, BLACK);
            }

            std::string Menu::nextScene()
            {
                if (IsKeyReleased(KEY_ONE))
                    return "game";
                if (IsKeyReleased(KEY_TWO))
                    return "option";
                return "menu";
            }
        }
    }
}