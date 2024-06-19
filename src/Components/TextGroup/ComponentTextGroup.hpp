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
            /**
             * @brief TextGroup class
             */
            class TextGroup: public AComponent {
                public:
                    /**
                     * @brief Construct a new Text Group object
                     *
                     * @param pos
                     * @param width
                     * @param gap
                     *
                     * @warning This function should be called in the raylib context
                     */
                    TextGroup(std::pair<int, int> pos, int width, int gap);

                    /**
                     * @brief Draw the TextGroup
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the TextGroup
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the TextGroup
                     *
                     * @param x X position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the TextGroup
                     *
                     * @param y Y position
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Add a text to the TextGroup
                     *
                     * @param name Name of the text
                     * @param text Text to add
                     * @param gap Gap between the texts
                     * @param color Color of the text
                     */
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
