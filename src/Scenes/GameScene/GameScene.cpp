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
                : _render(render)
            {
                _render = render;
                _skybox = nullptr;
                _borderbox = nullptr;
                _tileMap = nullptr;
                _chatbox = std::make_unique<Zappy::GUI::Component::Chatbox>();
                _inspecter = std::make_shared<Zappy::GUI::Component::Inspecter>();

                _crossPointer = std::make_pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>>(
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 1, GetScreenHeight() / 2 - 10), std::make_pair(2, 20), (Color){240, 0, 0, 100}),
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 1), std::make_pair(20, 2), (Color){240, 0, 0, 100})
                );
            }

            void Game::destroy()
            {
                if (_ressources != nullptr) _ressources->destroy();
                if (_borderbox != nullptr) _borderbox->destroy();
                if (_skybox != nullptr) _skybox->destroy();
            }

            void Game::start()
            {
                DisableCursor();
                _render->view()->setMouseFollowing(true);
                _cursor = false;
                _render->view()->enableCamera();
                _tileMap->unhighlight();
            }

            void Game::update()
            {
                _skybox->update(_render);
                _borderbox->update(_render);
                _chatbox->update();
                _inspecter->update(_tileMap->getSelected());
                if (_chatbox->mouseIsOn() || _inspecter->mouseIsOn())
                    _tileMap->unhighlight();
                else
                    _tileMap->update(_render, _inspecter);

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

            void Game::draw3D()
            {
                _skybox->draw();
                _borderbox->draw();
                _tileMap->draw();
            }

            void Game::draw2D()
            {
                _chatbox->draw();
                _inspecter->draw();

                if (!_cursor) {
                    _crossPointer.first->draw();
                    _crossPointer.second->draw();
                }

            }

            std::string Game::nextScene()
            {
                if (IsKeyReleased(KEY_TAB)){
                    Sfml::SoundManager::getInstance().setMusique("assets/Musique/ClashofTekMainMusic.wav");
                    Sfml::SoundManager::getInstance().playgeneralSound();
                    return "menu";
                }
                return "game";
            }

            bool Game::isReady()
            {
                if (_isReady) return true;

                std::pair<int, int> mapSize = Zappy::GUI::Ressources::Ref::get()->ressources->getMapDimensions();
                if (mapSize.first <= 0 || mapSize.second <= 0) return false;
                createMap(mapSize);
                _isReady = true;
                return true;
            }

            void Game::createMap(std::pair<int, int> size)
            {
                int tileSize = 5;

                _skybox = std::make_unique<Zappy::GUI::Component::Skybox>("purple", tileSize * size.first * 10);
                _borderbox = std::make_unique<Zappy::GUI::Component::Skybox>((Color){0, 0, 0, 0}, tileSize * size.first * 3);
                _ressources = std::make_shared<Zappy::GUI::Component::Ressources>((Vector3){(float)tileSize, (float)tileSize, (float)tileSize});
                _tileMap = std::make_unique<Zappy::GUI::Component::TileMap>((Vector3){(float)-((tileSize * size.first) / 2), 0, (float)-((tileSize * size.second) / 2)}, size, tileSize, _ressources);
            }
        }
    }
}