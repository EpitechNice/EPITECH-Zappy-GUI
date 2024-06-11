/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextBox
*/

#ifndef COMPONENT_TEXT_BOX_HPP_
    #define COMPONENT_TEXT_BOX_HPP_

    #include <raylib.h>
    #include <string>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextBox: public AComponent {
                public:
                    TextBox(std::pair<int, int> pos, int width, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");

                    void destroy() override;
                    void draw() override;

                    void setText(std::string text);

                protected:
                private:
                    int _width;
                    std::string _text;
                    int _fontSize;
                    Font _font;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_BOX_HPP_ */
