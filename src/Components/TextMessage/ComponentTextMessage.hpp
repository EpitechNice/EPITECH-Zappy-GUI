/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextMessage
*/

#ifndef COMPONENT_TEXT_MESSAGE_HPP_
    #define COMPONENT_TEXT_MESSAGE_HPP_

    #include <raylib.h>
    #include <string>
    #include <memory>

    #include "ComponentTextBox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextMessage {
                public:
                    TextMessage(std::pair<int, int> pos, int width, std::string name, std::string text, int gap, Color color);
                    ~TextMessage();

                    void destroy();

                    void setPosX(int x);
                    void setPosY(int y);
                    void setPos(std::pair<int, int> pos);

                    std::pair<float, float> getSize() const;

                    void draw();

                protected:
                private:
                    bool _isDestroyed;
                    int _gap;

                    std::unique_ptr<TextBox> _name;
                    std::unique_ptr<TextBox> _text;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_MESSAGE_HPP_ */
