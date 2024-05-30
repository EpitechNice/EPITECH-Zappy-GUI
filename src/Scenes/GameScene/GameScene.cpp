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

                _crossPointer = std::make_pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>>(
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 1, GetScreenHeight() / 2 - 10), std::make_pair(2, 20), (Color){240, 0, 0, 100}),
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 1), std::make_pair(20, 2), (Color){240, 0, 0, 100})
                );
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
                _tileMap->update(_render);

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

                if (!_cursor) {
                    _crossPointer.first->draw();
                    _crossPointer.second->draw();
                }
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