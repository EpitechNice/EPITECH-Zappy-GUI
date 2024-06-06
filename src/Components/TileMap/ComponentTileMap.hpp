/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentTileMap
*/

#ifndef COMPONENT_TILE_MAP_HPP_
    #define COMPONENT_TILE_MAP_HPP_

    #include <memory>
    #include <vector>

    #include "ComponentTile.hpp"
    #include "Render.hpp"
    #include "ComponentRessources.hpp"
    #include "TileRessources.hpp"
    #include "Ressources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TileMap {
                public:
                    TileMap(Vector3 pos, std::pair<int, int> size, int tileSize, std::shared_ptr<Ressources> ressources);
                    ~TileMap();

                    void destroy();

                    void update(std::shared_ptr<Raylib::Render> render);

                    void draw();

                    std::vector<std::vector<std::shared_ptr<Tile>>> tiles();

                    void unhighlight();

                protected:
                private:
                    Vector3 _pos;
                    std::pair<int, int> _size;
                    int _tileSize;
                    std::vector<std::vector<std::shared_ptr<Tile>>> _tiles;
                    std::pair<int, int> _highLight;
                    std::pair<int, int> _select;
                    bool _isDestroyed;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_MAP_HPP_ */
