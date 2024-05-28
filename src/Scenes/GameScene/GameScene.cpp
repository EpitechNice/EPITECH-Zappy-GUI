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
            Game::Game(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                _render = render;
                _skybox = std::make_unique<Zappy::GUI::Component::Skybox>("purple");
                _borderbox = std::make_unique<Zappy::GUI::Component::Skybox>((Color){0, 0, 0, 0}, 100);
            }

            void Game::destroy()
            {
                _skybox->destroy();
            }

            void Game::start()
            {
            }

            void Game::update()
            {
                _borderbox->update(_render);
            }

            void Game::event()
            {
            }

            void Game::draw3D()
            {
                _skybox->draw();
                _borderbox->draw();
                for (float x = 0; x < 20; x++) {
                    for (float z = 0; z < 20; z++) {
                        Vector3 grass = { x, 0, z };
                        Vector3 dirt = { x, -0.5f, z };
                        Color grassColor = { 112, 224, 0, 255 };
                        if (((int)x % 2 == 0 && (int)z % 2 == 0) || ((int)x % 2 != 0 && (int)z % 2 != 0))
                            grassColor = { 60, 186, 2, 255 };
                        DrawCube(grass, 1.0f, 0.4f, 1.0f, grassColor);
                        DrawCube(dirt, 1.0f, 0.6f, 1.0f, BROWN);
                    }
                }
            }

            void Game::draw2D()
            {
                DrawText("Press tab to go to Menu", 10, 10, 10, RED);

                Vector3 pos = _render->view()->getPosition();

                DrawText("Camera:", 10, 30, 10, RED);
                DrawText(("X: " + std::to_string(pos.x)).c_str(), 10, 50, 10, RED);
                DrawText(("Y: " + std::to_string(pos.y)).c_str(), 10, 70, 10, RED);
                DrawText(("Z: " + std::to_string(pos.z)).c_str(), 10, 90, 10, RED);

                Vector3 target = _render->view()->getTarget();
                DrawText("Target:", 10, 110, 10, RED);
                DrawText(("X: " + std::to_string(target.x)).c_str(), 10, 130, 10, RED);
                DrawText(("Y: " + std::to_string(target.y)).c_str(), 10, 150, 10, RED);
                DrawText(("Z: " + std::to_string(target.z)).c_str(), 10, 170, 10, RED);
            }

            std::string Game::nextScene()
            {
                if (IsKeyReleased(KEY_TAB))
                    return "menu";
                return "game";
            }
        }
    }
}