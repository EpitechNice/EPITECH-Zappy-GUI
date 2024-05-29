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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextGroup {
                public:
                    TextGroup(std::pair<int, int> pos, int width, int gap);
                    ~TextGroup();

                    void destroy();

                    void draw();

                    void addText(std::string name, std::string text, int gap, Color color);

                    void setPosX(int x);

                protected:
                private:
                    std::pair<int, int> _pos;
                    int _width;
                    int _height;
                    int _gap;
                    bool _isDestroyed;
                    std::vector<std::unique_ptr<TextMessage>> _texts;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_GROUP_HPP_ */
