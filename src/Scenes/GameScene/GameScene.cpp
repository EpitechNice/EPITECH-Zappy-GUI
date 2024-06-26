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
                _north = nullptr;
                _east = nullptr;
                _south = nullptr;
                _west = nullptr;
                _chatbox = std::make_unique<Zappy::GUI::Component::Chatbox>();
                _inspecter = std::make_shared<Zappy::GUI::Component::Inspecter>();
                _isReady = false;

                _crossPointer = std::make_pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>>(
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 1, GetScreenHeight() / 2 - 10), std::make_pair(2, 20), (Color){240, 0, 0, 100}),
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 1), std::make_pair(20, 2), (Color){240, 0, 0, 100})
                );

                int width = GetScreenWidth();

                _north  = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(0, 20), "- N -", 40, WHITE);
                _east   = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(0, 20), "- E -", 40, WHITE);
                _south  = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(0, 20), "- S -", 40, WHITE);
                _west   = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(0, 20), "- W -", 40, WHITE);
                _north  ->setPosX(width / 2 - _north->getSizeX() / 2);
                _east   ->setPosX(width / 2 - _east->getSizeX() / 2);
                _south  ->setPosX(width / 2 - _south->getSizeX() / 2);
                _west   ->setPosX(width / 2 - _west->getSizeX() / 2);
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
                _inspecter->update(_tileMap->getSelected(), _render->view());
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

                Zappy::GUI::Raylib::View::Direction facing = _render->view()->getFacingDirection();

                switch (facing) {
                    case Zappy::GUI::Raylib::View::Direction::NORTH:
                        _north->draw();
                        break;
                    case Zappy::GUI::Raylib::View::Direction::EAST:
                        _east->draw();
                        break;
                    case Zappy::GUI::Raylib::View::Direction::SOUTH:
                        _south->draw();
                        break;
                    case Zappy::GUI::Raylib::View::Direction::WEST:
                        _west->draw();
                        break;
                }
            }

            std::string Game::nextScene()
            {
                if (IsKeyReleased(KEY_TAB)){
                    Sfml::SoundManager::getInstance().setMusique(Zappy::GUI::Path::get()->path() + "Musique/ClashofTekMainMusic.wav");
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

                _skybox = std::make_unique<Zappy::GUI::Component::Skybox>(true, tileSize * size.first * 10);
                _borderbox = std::make_unique<Zappy::GUI::Component::Skybox>(false, tileSize * size.first * 3);
                _ressources = std::make_shared<Zappy::GUI::Component::Ressources>((Vector3){(float)tileSize, (float)tileSize, (float)tileSize});
                _tileMap = std::make_unique<Zappy::GUI::Component::TileMap>((Vector3){(float)-((tileSize * size.first) / 2), 0, (float)-((tileSize * size.second) / 2)}, size, tileSize, _ressources);

                Zappy::GUI::RelativePlayerPosition::get()->setTileSize(tileSize);
                Zappy::GUI::RelativePlayerPosition::get()->setStart((Vector3){_tileMap->getPosX(), _tileMap->getPosY(), _tileMap->getPosZ()});
            }

            void Game::resize()
            {
                if (_skybox != nullptr) _skybox->resize();
                if (_borderbox != nullptr) _borderbox->resize();
                if (_ressources != nullptr) _ressources->resize();
                if (_tileMap != nullptr) _tileMap->resize();
                _north->resize();
                _east->resize();
                _south->resize();
                _west->resize();
                _north->setPosX(GetScreenWidth() / 2 - _north->getSizeX() / 2);
                _east->setPosX(GetScreenWidth() / 2 - _east->getSizeX() / 2);
                _south->setPosX(GetScreenWidth() / 2 - _south->getSizeX() / 2);
                _west->setPosX(GetScreenWidth() / 2 - _west->getSizeX() / 2);
                _chatbox->resize();
                _inspecter->resize();
                _crossPointer.first->resize();
                _crossPointer.second->resize();
            }
        }
    }
}