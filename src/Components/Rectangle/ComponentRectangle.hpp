/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentRectangle
*/

#ifndef COMPONENT_RECTANGLE_HPP_
    #define COMPONENT_RECTANGLE_HPP_

    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <memory>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Rectangle {
                public:
                    Rectangle(std::pair<int, int> pos, std::pair<int, int> size, Color color);
                    ~Rectangle() = default;

                    void draw();

                    void setStroke(int strokeSize, Color strokeColor);
                    void unsetStroke();

                    void setPosX(int x);

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    Color _color;

                    int _strokeSize;
                    Color _strokeColor;
            };
        }
    }
}

#endif /* !COMPONENT_RECTANGLE_HPP_ */
