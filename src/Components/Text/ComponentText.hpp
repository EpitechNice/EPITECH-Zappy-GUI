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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Text {
                public:
                    Text(std::pair<float, float> pos, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");
                    ~Text();

                    void destroy();

                    void setPos(std::pair<float, float> pos);
                    void setText(std::string text);
                    void setColor(Color color);

                    std::pair<float, float> getSize() const;

                    void draw();

                protected:
                private:
                    std::pair<float, float> _pos;
                    std::string _text;
                    int _fontSize;
                    Color _color;
                    Font _font;
                    bool _isDestroyed;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_HPP_ */
