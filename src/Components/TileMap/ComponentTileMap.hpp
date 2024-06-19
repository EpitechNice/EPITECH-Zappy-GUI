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
    #include "Ref.hpp"
    #include "ComponentInspecter.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief TileMap class
             */
            class TileMap: public AComponent {
                public:
                    /**
                     * @brief Construct a new Tile Map object
                     *
                     * @param pos The position of the tile map
                     * @param size The size of the tile map
                     * @param tileSize The size of the tile
                     * @param ressources A pointer to the ressources drawer
                     */
                    TileMap(Vector3 pos, std::pair<int, int> size, int tileSize, std::shared_ptr<Ressources> ressources);

                    /**
                     * @brief Draw the tile map
                     */
                    void draw() override;

                    /**
                     * @brief Update the tile map
                     */
                    void update(std::shared_ptr<Raylib::Render> render, std::shared_ptr<Inspecter> inspecter);

                    /**
                     * @brief Set the tiles object
                     *
                     * @return `tiles` The tiles object
                     */
                    std::vector<std::vector<std::shared_ptr<Tile>>> tiles();

                    /**
                     * @brief Disable the highlight of the highlighted tile
                     */
                    void unhighlight();

                    /**
                     * @brief Check if a tile is selected
                     *
                     * @return `true` If a tile is selected, `false` otherwise
                     */
                    bool hasSelected() const;

                    /**
                     * @brief Get the coordinates of the selected tile
                     *
                     * @return `std::pair<int, int>` The coordinates of the selected tile
                     */
                    std::pair<int, int> getSelected() const;

                protected:
                private:
                    int _tileSize;
                    std::vector<std::vector<std::shared_ptr<Tile>>> _tiles;
                    std::pair<int, int> _highLight = {-1, -1};
                    std::pair<int, int> _select;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_MAP_HPP_ */
