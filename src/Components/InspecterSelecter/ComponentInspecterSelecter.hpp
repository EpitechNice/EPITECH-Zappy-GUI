/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** InspecterSelecter
*/

#ifndef COMPONENT_INSPECTER_SELECTER_HPP_
    #define COMPONENT_INSPECTER_SELECTER_HPP_

    #include <iostream>
    #include <memory>
    #include <raylib.h>

    #include "Players.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "ComponentCircle.hpp"
    #include "AComponent.hpp"
    #include "Ref.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class representing the selecter in the inspecter
             */
            class InspecterSelecter: public AComponent {
                public:
                    /**
                     * @brief Construct a new Inspecter Selecter object
                     *
                     * @param pos The position of the selecter
                     * @param width The width of the selecter
                     * @param player The player to display
                     */
                    InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    /**
                     * @brief Construct a new Inspecter Selecter object
                     *
                     * @param pos The position of the selecter
                     * @param width The width of the selecter
                     * @param egg The egg to display
                     */
                    InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                    /**
                     * @brief Draw the selecter
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the selecter
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Modify the position of the selecter
                     *
                     * @param x The x position to add
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Modify the position of the selecter
                     *
                     * @param y The y position to add
                     */
                    void modPosY(float y) override;

                    /**
                     * @brief Set the position of the selecter
                     *
                     * @param x The new x position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the selecter
                     *
                     * @param y The new y position
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Update the selecter
                     */
                    void update();

                    /**
                     * @brief Set the selected state of the selecter
                     *
                     * @param selected The new selected state
                     */
                    void setSelected(bool selected);

                    /**
                     * @brief Check if the selecter is clicked
                     *
                     * @return true if the selecter is clicked
                     * @return false if the selecter is not clicked
                     */
                    bool isClicked() const;

                    /**
                     * @brief Check if the selecter is selected
                     *
                     * @return true if the selecter is selected
                     * @return false if the selecter is not selected
                     */
                    bool isPlayer() const;

                    /**
                     * @brief Get the Player object
                     *
                     * @return `std::shared_ptr<Zappy::GUI::Ressources::Players>` The player
                     */
                    std::shared_ptr<Zappy::GUI::Ressources::Players> getPlayer() const;

                    /**
                     * @brief Get the Egg object
                     *
                     * @return `std::shared_ptr<Zappy::GUI::Ressources::Eggs>` The egg
                     */
                    std::shared_ptr<Zappy::GUI::Ressources::Eggs> getEgg() const;

                protected:
                private:
                    typedef enum {
                        NONE,
                        HOVER,
                        CLICKED,
                        SELECTED,
                    } State;

                    std::shared_ptr<Zappy::GUI::Ressources::Players> _player;
                    std::shared_ptr<Zappy::GUI::Ressources::Eggs> _egg;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Circle> _team;
                    State _state = NONE;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_SELECTER_HPP_ */
