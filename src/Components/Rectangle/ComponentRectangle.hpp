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

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Rectangle : public AComponent {
                public:
                    Rectangle(std::pair<int, int> pos, std::pair<int, int> size, Color color);

                    void draw() override;

                    void setStroke(int strokeSize, Color strokeColor);

                protected:
                private:
                    int _strokeSize;
                    Color _strokeColor;
            };
        }
    }
}

#endif /* !COMPONENT_RECTANGLE_HPP_ */
