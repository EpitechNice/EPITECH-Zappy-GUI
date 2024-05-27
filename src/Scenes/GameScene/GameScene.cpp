/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Game
*/

#include "GameScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            void Game::start()
            {
            }

            void Game::event()
            {
            }

            void Game::draw3D()
            {
            }

            void Game::draw2D()
            {
                DrawText("Game", 10, 10, 20, RED);

                DrawText("Press 1 to go to Menu", 10, 30, 20, RED);
                DrawText("Press 2 to go to Option", 10, 50, 20, RED);
            }

            std::string Game::nextScene()
            {
                if (IsKeyReleased(KEY_ONE))
                    return "menu";
                if (IsKeyReleased(KEY_TWO))
                    return "option";
                return "game";
            }
        }
    }
}