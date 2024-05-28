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
                _chatbox = std::make_unique<Zappy::GUI::Component::Chatbox>();
            }

            void Game::destroy()
            {
                _skybox->destroy();
                _borderbox->destroy();
                _chatbox->destroy();
            }

            void Game::start()
            {
                EnableCursor();
                _cursor = true;
            }

            void Game::update()
            {
                _skybox->update(_render);
                _borderbox->update(_render);
                _chatbox->update();

                if (IsKeyReleased(KEY_C)) {
                    if (_cursor) {
                        DisableCursor();
                        _cursor = false;
                    } else {
                        EnableCursor();
                        _cursor = true;
                    }
                }
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
                _chatbox->draw();
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