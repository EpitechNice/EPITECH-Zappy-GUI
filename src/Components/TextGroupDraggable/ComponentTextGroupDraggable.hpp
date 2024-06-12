/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextGroupDraggable
*/

#ifndef COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_
    #define COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_

    #include <raylib.h>
    #include <memory>

    #include "ComponentTextGroup.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextGroupDraggable: public AComponent {
                public:
                    TextGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size, int gap);

                    void destroy() override;
                    void draw() override;
                    void setPosX(float x) override;

                    void update();
                    void addText(std::string name, std::string text, int gap, Color color);

                protected:
                private:
                    int _gap;
                    bool _isDragged;
                    std::pair<int, int> _dragOffset;
                    std::unique_ptr<TextGroup> _textGroup;

                    void _updateTextsPos();
                    void _setDragOffset();
                    void _endDrag();
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_ */
