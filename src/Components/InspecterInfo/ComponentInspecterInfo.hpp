/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterInfo
*/

#ifndef COMPONENT_INSPECTER_INFO_HPP_
    #define COMPONENT_INSPECTER_INFO_HPP_

    #include <memory>
    #include <vector>
    #include <iostream>

    #include "Players.hpp"
    #include "Eggs.hpp"
    #include "Ref.hpp"
    #include "ComponentTextBox.hpp"
    #include "ComponentCircle.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class representing the info in the inspecter
             */
            class InspecterInfo: public AComponent {
                public:
                    /**
                     * @brief Construct a new Inspecter Info object
                     *
                     * @param pos The position of the info
                     * @param size The size of the info
                     */
                    InspecterInfo(std::pair<int, int> pos, std::pair<int, int> size);

                    /**
                     * @brief Draw the info
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the info
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the position on X axis of the info
                     *
                     * @param x The new x position of the info
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Set the informaton of the player
                     *
                     * @param player The player to display
                     */
                    void setInfoPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    /**
                     * @brief Set the informaton of the egg
                     *
                     * @param egg The egg to display
                     */
                    void setInfoEgg(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _noPlayerSelected;
                    std::shared_ptr<Zappy::GUI::Ressources::Players> _player;
                    std::shared_ptr<Zappy::GUI::Ressources::Eggs> _egg;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _team;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _name;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _food;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _linemate;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _deraumere;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _sibur;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _mendiane;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _phiras;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _thystame;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_INFO_HPP_ */
