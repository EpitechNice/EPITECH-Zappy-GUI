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
            TileMap::TileMap(Vector3 pos, std::pair<int, int> size)
                : _pos(pos), _size(size)
            {
                for (int x = 0; x < size.first; x++) {
                    std::vector<std::shared_ptr<Tile>> line;
                    for (int z = 0; z < size.second; z++) {
                        Color grassColor = { 112, 224, 0, 255 };
                        if (((int)x % 2 == 0 && (int)z % 2 == 0) || ((int)x % 2 != 0 && (int)z % 2 != 0))
                            grassColor = { 60, 186, 2, 255 };
                        line.push_back(std::make_shared<Tile>((Vector3){(float)(pos.x + x), (float)pos.y, (float)(pos.z + z)}, grassColor));
                    }
                    _tiles.push_back(line);
                }
            }

            void TileMap::update()
            {
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
        }
    }
}