/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterInfo
*/

#ifndef COMPONENT_INSPECTER_INFO_TILE_HPP_
    #define COMPONENT_INSPECTER_INFO_TILE_HPP_

    #include <memory>
    #include <vector>
    #include <iostream>

    #include "Players.hpp"
    #include "Ref.hpp"
    #include "ComponentTextBox.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class representing the inspecter info tile
             */
            class InspecterInfoTile: public AComponent {
                public:
                    /**
                     * @brief Construct a new Inspecter Info Tile object
                     *
                     * @param pos The position of the tile
                     * @param size The size of the tile
                     */
                    InspecterInfoTile(std::pair<int, int> pos, std::pair<int, int> size);

                    /**
                     * @brief Draw the tile
                     */
                    void draw() override;

                    /**
                     * @brief Resize the tile
                     */
                    void resize() override;

                    /**
                     * @brief Modify the position of the tile
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Set the position of the tile
                     */
                    void setInfo(std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tile);

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _noTileSelected;
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> _tile;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _name;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _food;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _linemate;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _deraumere;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _sibur;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _mendiane;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _phiras;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _thystame;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _egg;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _players;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_INFO_TILE_HPP_ */
