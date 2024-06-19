/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroupDragagable
*/

#ifndef COMPONENT_INSPECTER_SELECTER_GROUP_DRAGGABLE_HPP_
    #define COMPONENT_INSPECTER_SELECTER_GROUP_DRAGGABLE_HPP_

    #include <raylib.h>
    #include <memory>
    #include <vector>

    #include "ComponentInspecterSelecterGroup.hpp"
    #include "ComponentInspecterInfo.hpp"
    #include "Players.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class representing the draggable group of selecters in the inspecter
             */
            class InspecterSelecterGroupDraggable: public AComponent {
                public:
                    /**
                     * @brief Construct a new Inspecter Selecter Group Draggable object
                     *
                     * @param pos The position of the group
                     * @param size The size of the group
                     */
                    InspecterSelecterGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size);

                    /**
                     * @brief Draw the group
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the group
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the group
                     *
                     * @param x The new x position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Modify the position of the group
                     *
                     * @param x The x position to add
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Update the group
                     *
                     * @param info The info to update the group with
                     */
                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    /**
                     * @brief Reset the group
                     *
                     * @param info The info to reset the group with
                     */
                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    /**
                     * @brief Add a selecter to the group
                     *
                     * @param player The player to add
                     */
                    void addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    /**
                     * @brief Add a selecter to the group
                     *
                     * @param egg The egg to add
                     */
                    void addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                protected:
                private:
                    bool _isDragged;
                    std::pair<int, int> _dragOffset;
                    std::unique_ptr<InspecterSelecterGroup> _selecterGroup;

                    void _updateSelectersPos();
                    void _setDragOffset();
                    void _endDrag();
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_DRAGGABLE_HPP_ */
