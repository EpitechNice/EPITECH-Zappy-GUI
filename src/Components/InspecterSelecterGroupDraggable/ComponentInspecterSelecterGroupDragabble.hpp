/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroupDragabble
*/

#ifndef COMPONENT_INSPECTER_SELECTER_GROUP_DRAGABBLE_HPP_
    #define COMPONENT_INSPECTER_SELECTER_GROUP_DRAGABBLE_HPP_

    #include <raylib.h>
    #include <memory>
    #include <vector>

    #include "ComponentInspecterSelecterGroup.hpp"
    #include "ComponentInspecterInfo.hpp"
    #include "Players.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecterGroupDraggable {
                public:
                    InspecterSelecterGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size);
                    ~InspecterSelecterGroupDraggable();

                    void destroy();

                    void draw();

                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    void addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    void setPosX(int x);
                    void modPosX(int x);

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    bool _isDragged;
                    std::pair<int, int> _dragOffset;
                    bool _isDestroyed;
                    std::unique_ptr<InspecterSelecterGroup> _selecterGroup;

                    void _updateSelectersPos();
                    void _setDragOffset();
                    void _endDrag();
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_DRAGABBLE_HPP_ */
