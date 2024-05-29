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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextGroupDraggable {
                public:
                    TextGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size, int gap);
                    ~TextGroupDraggable();

                    void destroy();

                    void draw();

                    void update();

                    void addText(std::string name, std::string text, int gap, Color color);

                    void setPosX(int x);

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    int _gap;
                    bool _isDragged;
                    std::pair<int, int> _dragOffset;
                    bool _isDestroyed;
                    std::unique_ptr<TextGroup> _textGroup;

                    void _updateTextsPos();
                    void _setDragOffset();
                    void _endDrag();
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_GROUP_DRAGGABLE_HPP_ */
