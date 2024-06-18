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
                    void resize() override;

                    void setStroke(float strokeSize, Color strokeColor);

                protected:
                private:
                    float _strokeSize = -1;
                    Color _strokeColor;

                    float _refStrokeSize;
            };
        }
    }
}

#endif /* !COMPONENT_RECTANGLE_HPP_ */
