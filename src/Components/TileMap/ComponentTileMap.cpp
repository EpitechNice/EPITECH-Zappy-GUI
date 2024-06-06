/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentTileMap
*/

#include "ComponentTileMap.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            TileMap::TileMap(Vector3 pos, std::pair<int, int> size, int tileSize, std::shared_ptr<Ressources> ressources)
                : _pos(pos), _size(size), _tileSize(tileSize), _isDestroyed(false)
            {
                for (int x = 0; x < size.first; x++) {
                    std::vector<std::shared_ptr<Tile>> line;
                    std::vector<std::shared_ptr<Zappy::GUI::Ressources::TileRessources>> ressourcesLine;
                    for (int z = 0; z < size.second; z++) {
                        Color grassColor = { 112, 224, 0, 255 };
                        if (((int)x % 2 == 0 && (int)z % 2 == 0) || ((int)x % 2 != 0 && (int)z % 2 != 0))
                            grassColor = { 60, 186, 2, 255 };
                        ressourcesLine.push_back(std::make_shared<Zappy::GUI::Ressources::TileRessources>());
                        line.push_back(std::make_shared<Tile>((Vector3){(float)(pos.x + x * _tileSize), (float)pos.y, (float)(pos.z + z * _tileSize)}, (Vector3){(float)_tileSize, (float)_tileSize, (float)_tileSize}, grassColor, ressources, ressourcesLine.back()));


                        // TODO: Delete this
                        ressourcesLine.back()->setFood(rand() % 3);
                        ressourcesLine.back()->setEgg(rand() % 3);
                        ressourcesLine.back()->setLinemate(rand() % 3);
                        ressourcesLine.back()->setDeraumere(rand() % 3);
                        ressourcesLine.back()->setSibur(rand() % 3);
                        ressourcesLine.back()->setMendiane(rand() % 3);
                        ressourcesLine.back()->setPhiras(rand() % 3);
                        ressourcesLine.back()->setThystame(rand() % 3);
                    }
                    _tiles.push_back(line);
                    _ressources.push_back(ressourcesLine);
                }
                _highLight = std::make_pair(-1, -1);
                _select = std::make_pair(-1, -1);

                // TODO: Delete this
                std::vector<std::shared_ptr<Zappy::GUI::Ressources::Players>> players;
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(1, 0, 0, BLUE));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(2, 0, 0, RED));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(3, 1, 0, GREEN));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(4, 0, 1, YELLOW));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(5, 1, 1, PURPLE));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(6, 1, 1, ORANGE));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(7, 1, 1, PINK));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(8, 4, 3, BROWN));
                players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(9, 1, 0, BEIGE));
                for (auto &player : players)
                    _ressources[player->getX()][player->getY()]->addPlayer(player);
            }

            TileMap::~TileMap()
            {
                destroy();
            }

            void TileMap::destroy()
            {
                if (_isDestroyed)
                    return;
                for (auto &line: _tiles)
                    for (auto &tile : line)
                        tile->destroy();
                _tiles.clear();
                _isDestroyed = true;
            }

            void TileMap::update(std::shared_ptr<Raylib::Render> render)
            {
                std::pair<int, int> highLight = { -1, -1 };
                Vector2 point = GetMousePosition();
                if (render->view()->isMouseFollowing())
                    point = {(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)};
                Ray ray = GetMouseRay(point, render->view()->getCamera());

                for (int x = 0; x < _size.first; x++) {
                    for (int z = 0; z < _size.second; z++) {
                        BoundingBox box = _tiles[x][z]->getTopBox();
                        RayCollision tmp = GetRayCollisionBox(ray, box);
                        if (tmp.hit) {
                            highLight = { x, z };
                        }
                    }
                }
                if (highLight != _highLight) {
                    if (_highLight.first != -1 && _highLight.second != -1)
                        _tiles[_highLight.first][_highLight.second]->highlight(false);
                    if (highLight.first != -1 && highLight.second != -1)
                        _tiles[highLight.first][highLight.second]->highlight(true);
                    _highLight = highLight;
                }
                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    if (_select.first != -1 && _select.second != -1)
                        _tiles[_select.first][_select.second]->select(false);
                    if (highLight.first != -1 && highLight.second != -1) {
                        _tiles[highLight.first][highLight.second]->highlight(false);
                        _tiles[highLight.first][highLight.second]->select(true);
                    }
                    _select = highLight;
                }
            }

            void TileMap::draw()
            {
                for (auto &line: _tiles)
                    for (auto &tile : line)
                        tile->draw();
            }

            std::vector<std::vector<std::shared_ptr<Tile>>> TileMap::tiles()
            {
                return _tiles;
            }

            void TileMap::unhighlight()
            {
                if (_highLight.first != -1 && _highLight.second != -1) {
                    _tiles[_highLight.first][_highLight.second]->highlight(false);
                    _highLight = std::make_pair(-1, -1);
                }
            }
        }
    }
}