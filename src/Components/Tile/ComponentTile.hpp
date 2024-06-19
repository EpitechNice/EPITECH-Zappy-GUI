/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentTile
*/

#ifndef COMPONENT_TILE_HPP_
    #define COMPONENT_TILE_HPP_

    #include <raylib.h>
    #include <memory>
    #include <iostream>

    #include "ComponentCube.hpp"
    #include "ColorManager.hpp"
    #include "ComponentModel3D.hpp"
    #include "ComponentRessources.hpp"
    #include "TileRessources.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Tile class
             */
            class Tile: public AComponent {
                public:
                    /**
                     * @brief Construct a new Tile object
                     *
                     * @param pos The position of the tile
                     * @param size The size of the tile
                     * @param color The color of the grass of the tile
                     * @param ressourcesDrawer A pointer to the ressources drawer
                     * @param ressources A pointer to the tile ressources
                     */
                    Tile(Vector3 pos, Vector3 size, Color color, std::shared_ptr<Ressources> ressourcesDrawer, std::shared_ptr<Zappy::GUI::Ressources::TileRessources> ressources);

                    /**
                     * @brief Draw the tile
                     */
                    void draw() override;

                    /**
                     * @brief Get the Top Box object
                     *
                     * @return `BoundingBox` The top box of the tile
                     */
                    BoundingBox getTopBox() const;

                    /**
                     * @brief Set the highlight of the tile
                     *
                     * @param highlight The highlight value
                     */
                    void highlight(bool highlight);

                    /**
                     * @brief Set the select of the tile
                     *
                     * @param select The select value
                     */
                    void select(bool select);

                protected:
                private:
                    std::shared_ptr<Ressources> _ressourcesDrawer;
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> _ressources;
                    bool _highlight;
                    bool _select;
                    Vector3 _grassPos;
                    Vector3 _grassSize;
                    Vector3 _dirtPos;
                    Vector3 _dirtSize;

                    std::unique_ptr<Cube> _grass;
                    std::unique_ptr<Cube> _dirt;
                    std::unique_ptr<Cube> _wire;
                    float _selectEffect;
            };
        }
    }
}

#endif /* !COMPONENT_TILE_HPP_ */
