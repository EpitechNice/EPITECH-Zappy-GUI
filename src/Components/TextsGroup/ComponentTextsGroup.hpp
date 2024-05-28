/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextsGroup
*/

#ifndef COMPONENT_TEXTS_GROUP_HPP_
    #define COMPONENT_TEXTS_GROUP_HPP_

    #include <raylib.h>
    #include <vector>

    #include "ComponentText.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class TextsGroup {
                public:
                    TextsGroup();
                    ~TextsGroup();

                    void destroy();

                    void draw();

                    void addText(std::string name, std::string text);

                protected:
                private:
                    std::vector<Text> _texts;
            };
        }
    }
}

#endif /* !COMPONENT_TEXTS_GROUP_HPP_ */
