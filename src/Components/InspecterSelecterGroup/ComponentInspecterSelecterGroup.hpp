/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroup
*/

#ifndef COMPONENT_INSPECTER_SELECTER_GROUP_HPP_
    #define COMPONENT_INSPECTER_SELECTER_GROUP_HPP_

    #include <vector>

    #include "ComponentInspecterSelecter.hpp"
    #include "ComponentInspecterInfo.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class of the InspecterSelecterGroup
             */
            class InspecterSelecterGroup: public AComponent {
                public:
                    /**
                     * @brief Construct a new InspecterSelecterGroup object
                     *
                     * @param pos
                     * @param width
                     */
                    InspecterSelecterGroup(std::pair<int, int> pos, int width);

                    /**
                     * @brief draw the InspecterSelecterGroup
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the InspecterSelecterGroup
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Modify the position of the InspecterSelecterGroup
                     *
                     * @param x The x position to add
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Set the position of the InspecterSelecterGroup
                     *
                     * @param x The new x position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the InspecterSelecterGroup
                     *
                     * @param y The new y position
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Update the InspecterSelecterGroup
                     *
                     * @param info The info to update
                     */
                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    /**
                     * @brief Reset the InspecterSelecterGroup
                     *
                     * @param info The info to reset with
                     */
                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    /**
                     * @brief Add a player to the InspecterSelecterGroup
                     *
                     * @param player The player to add
                     */
                    void addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    /**
                     * @brief Add an egg to the InspecterSelecterGroup
                     *
                     * @param egg The egg to add
                     */
                    void addEgg(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                protected:
                private:
                    std::vector<std::shared_ptr<InspecterSelecter>> _selecters;
                    int _selected = -1;
                    float _gap = 20;
            };
        }
    }

}


#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_HPP_ */
