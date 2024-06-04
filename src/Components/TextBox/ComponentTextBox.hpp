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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextBox {
                public:
                    TextBox(std::pair<int, int> pos, int size, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");
                    ~TextBox();

                    void destroy();

                    void setPosX(int x);
                    void setPosY(int y);
                    void setPos(std::pair<int, int> pos);

                    void setText(std::string text);

                    std::pair<float, float> getSize() const;

                    void draw();

                protected:
                private:
                    std::pair<int, int> _pos;
                    int _size;
                    std::string _text;
                    int _fontSize;
                    Color _color;
                    Font _font;
                    bool _isDestroyed;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_BOX_HPP_ */
