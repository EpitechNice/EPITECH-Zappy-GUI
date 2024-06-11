/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentText
*/

#ifndef COMPONENT_TEXT_HPP_
    #define COMPONENT_TEXT_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <iostream>

    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Text: public AComponent {
                public:
                    Text(std::pair<float, float> pos, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");

                    void destroy() override;
                    void draw() override;

                    void setText(std::string text);
                    std::string getText() const;

                protected:
                private:
                    std::string _text;
                    int _fontSize;
                    Font _font;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_HPP_ */
