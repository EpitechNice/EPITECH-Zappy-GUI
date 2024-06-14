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
            {
                _posX = pos.x;
                _posY = pos.y;
                _posZ = pos.z;
                _sizeX = size.first;
                _sizeY = size.second;
                _tileSize = tileSize;
                _highLight = std::make_pair(-1, -1);
                _select = std::make_pair(-1, -1);

                for (int x = 0; x < _sizeX; x++) {
                    std::vector<std::shared_ptr<Tile>> line;
                    for (int z = 0; z < _sizeY; z++) {
                        Color grassColor = { 112, 224, 0, 255 };
                        if (((int)x % 2 == 0 && (int)z % 2 == 0) || ((int)x % 2 != 0 && (int)z % 2 != 0))
                            grassColor = { 60, 186, 2, 255 };
                        line.push_back(std::make_shared<Tile>((Vector3){(float)(_posX + x * _tileSize), (float)_posY, (float)(_posZ + z * _tileSize)}, (Vector3){(float)_tileSize, (float)_tileSize, (float)_tileSize}, grassColor, ressources, Zappy::GUI::Ressources::Ref::get()->ressources->tileRessources[x][z]));
                    }
                    _tiles.push_back(line);
                }
            }

            void TileMap::draw()
            {
                for (auto &line: _tiles)
                    for (auto &tile : line)
                        tile->draw();
            }

            void TileMap::update(std::shared_ptr<Raylib::Render> render, std::shared_ptr<Inspecter> inspecter)
            {
                Zappy::GUI::Ressources::Ref::get()->ressources->setPlayerOnMap();
                Zappy::GUI::Ressources::Ref::get()->ressources->setEggOnMap();
                std::pair<int, int> highLight = { -1, -1 };
                Vector2 point = GetMousePosition();
                if (render->view()->isMouseFollowing())
                    point = {(float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 2)};
                Ray ray = GetMouseRay(point, render->view()->getCamera());

                for (int x = 0; x < _sizeX; x++) {
                    for (int z = 0; z < _sizeY; z++) {
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
                    if (_select.first != -1 && _select.second != -1)
                        inspecter->open();
                    else
                        inspecter->close();
                }
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

            bool TileMap::hasSelected() const
            {
                return _select.first != -1 && _select.second != -1;
            }

            std::pair<int, int> TileMap::getSelected() const
            {
                return _select;
            }
        }
    }
}