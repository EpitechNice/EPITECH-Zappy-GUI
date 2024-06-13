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
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextMessage: public AComponent {
                public:
                    TextMessage(std::pair<int, int> pos, int width, std::string name, std::string text, int gap, Color color);

                    void draw() override;

                    void setPosX(float x) override;
                    void setPosY(float y) override;
                    void modPosX(float x) override;
                    void modPosY(float y) override;

                    float getSizeX() const override;
                    float getSizeY() const override;

                protected:
                private:
                    int _gap;

                    std::unique_ptr<TextBox> _name;
                    std::unique_ptr<TextBox> _text;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_MESSAGE_HPP_ */
