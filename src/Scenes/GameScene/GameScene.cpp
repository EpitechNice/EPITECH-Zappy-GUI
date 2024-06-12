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
            Game::Game(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::shared_ptr<Zappy::GUI::ServerCommunication> serverCommunication)
                : _mapSize(10, 10), _serverCommunication(serverCommunication), _render(render)
            {
                _serverCommunication->setMapSizeCallback([this](int width, int height) {
                    this->setMapSize(width, height);
                });

                _serverCommunication->addCommand("msz\r\n");
                int tileSize = 5;

                // TODO: Delete this
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(1, 0, 0, BLUE));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(2, 0, 0, RED));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(3, 1, 0, GREEN));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(4, 0, 1, YELLOW));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(5, 1, 1, PURPLE));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(6, 1, 1, ORANGE));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(7, 1, 1, PINK));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(8, 4, 3, BROWN));
                Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(9, 1, 0, BEIGE));

                _render = render;
                _skybox = std::make_unique<Zappy::GUI::Component::Skybox>("purple");
                _borderbox = std::make_unique<Zappy::GUI::Component::Skybox>((Color){0, 0, 0, 0}, tileSize * _mapSize.first * 2);
                _chatbox = std::make_unique<Zappy::GUI::Component::Chatbox>();
                _inspecter = std::make_shared<Zappy::GUI::Component::Inspecter>();
                _ressources = std::make_shared<Zappy::GUI::Component::Ressources>((Vector3){5, 5, 5});

                _tileMap = std::make_unique<Zappy::GUI::Component::TileMap>((Vector3){0, 0, 0}, _mapSize, tileSize, _ressources);

                _crossPointer = std::make_pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>>(
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 1, GetScreenHeight() / 2 - 10), std::make_pair(2, 20), (Color){240, 0, 0, 100}),
                    std::make_unique<Zappy::GUI::Component::Rectangle>(std::make_pair(GetScreenWidth() / 2 - 10, GetScreenHeight() / 2 - 1), std::make_pair(20, 2), (Color){240, 0, 0, 100})
                );
                serverCommunication->addCommand("bct 2 1\r\n");
                int id = Zappy::GUI::Ressources::Ressources::get()->players[1]->getId();
                std::string command = "ppo " + std::to_string(id) + "\r\n";
                serverCommunication->addCommand(command);
                // serverCommunication->addCommand("plv #1\r\n");
                // serverCommunication->addCommand("mct\r\n");
            }

            void Game::setMapSize(int width, int height)
            {
                _mapSize = { width, height };
            }

            void Game::destroy()
            {
                _ressources->destroy();
                _borderbox->destroy();
                _skybox->destroy();
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
        }
    }
}