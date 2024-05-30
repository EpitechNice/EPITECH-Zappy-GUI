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
                _tileMap = std::make_unique<Zappy::GUI::Component::TileMap>((Vector3){0, 0, 0}, std::make_pair(20, 40));
            }

            void Game::destroy()
            {
                _skybox->destroy();
                _borderbox->destroy();
                _chatbox->destroy();
            }

            void Game::start()
            {
                DisableCursor();
                _render->view()->setMouseFollowing(true);
                _cursor = false;
                _render->view()->enableCamera();
            }

            void Game::update()
            {
                _skybox->update(_render);
                _borderbox->update(_render);
                _chatbox->update();

                if (IsKeyReleased(KEY_C)) {
                    if (_cursor) {
                        DisableCursor();
                        _render->view()->setMouseFollowing(true);
                        _cursor = false;
                    } else {
                        EnableCursor();
                        _render->view()->setMouseFollowing(false);
                        _cursor = true;
                    }
                }
                if (_cursor)
                    _tileMap->update();
            }

            void Game::event()
            {
            }

            void Game::draw3D()
            {
                _skybox->draw();
                _borderbox->draw();
                _tileMap->draw();
            }

            void Game::draw2D()
            {
                _chatbox->draw();

                auto pos = _render->view()->getPosition();
                auto target = _render->view()->getTarget();
                std::string posStr = "Pos [" + std::to_string(pos.x) + ", " + std::to_string(pos.y) + ", " + std::to_string(pos.z) + "]";
                std::string targetStr = "Target [" + std::to_string(target.x) + ", " + std::to_string(target.y) + ", " + std::to_string(target.z) + "]";
                DrawText(posStr.c_str(), 15, 15, 15, WHITE);
                DrawText(targetStr.c_str(), 15, 30, 15, WHITE);
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