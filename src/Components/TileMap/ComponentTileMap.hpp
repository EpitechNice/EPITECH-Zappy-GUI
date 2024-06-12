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
    #include "ComponentInspecter.hpp"
    #include "AComponent.hpp"
    #include "CommunicationServer.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TileMap: public AComponent {
                public:
                    TileMap(Vector3 pos, std::pair<int, int> size, int tileSize, std::shared_ptr<Ressources> ressources, std::shared_ptr<Zappy::GUI::ServerCommunication> serverCommunication);

                    void draw() override;

                    void update(std::shared_ptr<Raylib::Render> render, std::shared_ptr<Inspecter> inspecter);
                    std::vector<std::vector<std::shared_ptr<Tile>>> tiles();
                    void unhighlight();
                    bool hasSelected() const;
                    std::pair<int, int> getSelected() const;

                protected:
                private:
                    int _tileSize;
                    std::vector<std::vector<std::shared_ptr<Tile>>> _tiles;
                    std::pair<int, int> _highLight;
                    std::pair<int, int> _select;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_MAP_HPP_ */
