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
            class InspecterSelecterGroupDraggable: public AComponent {
                public:
                    InspecterSelecterGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size);

                    void draw() override;
                    void setPosX(float x) override;
                    void modPosX(float x) override;

                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);
                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);
                    void addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

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
