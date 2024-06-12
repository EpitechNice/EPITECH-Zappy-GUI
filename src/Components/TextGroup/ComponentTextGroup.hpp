/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextsGroup
*/

#ifndef COMPONENT_TEXT_GROUP_HPP_
    #define COMPONENT_TEXT_GROUP_HPP_

    #include <raylib.h>
    #include <vector>
    #include <string>
    #include <memory>
    #include <iostream>

    #include "ComponentTextMessage.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextGroup: public AComponent {
                public:
                    TextGroup(std::pair<int, int> pos, int width, int gap);

                    void destroy() override;
                    void draw() override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;

                    void addText(std::string name, std::string text, int gap, Color color);

                protected:
                private:
                    int _gap;
                    std::vector<std::unique_ptr<TextMessage>> _texts;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_GROUP_HPP_ */
