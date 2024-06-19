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
            /**
             * @brief TextMessage class
             */
            class TextMessage: public AComponent {
                public:
                    /**
                     * @brief Construct a new TextMessage object
                     *
                     * @param pos Position of the TextMessage
                     * @param width Width of the TextMessage
                     * @param name Name of the TextMessage
                     * @param text Text of the TextMessage
                     * @param gap Gap between the name and the text
                     * @param color Color of the TextMessage
                     *
                     * @warning This function should be called in the raylib context
                     */
                    TextMessage(std::pair<int, int> pos, int width, std::string name, std::string text, int gap, Color color);

                    /**
                     * @brief Draw the TextMessage
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the TextMessage
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the TextMessage
                     *
                     * @param x X position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the TextMessage
                     *
                     * @param y Y position
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Modify the position of the TextMessage
                     *
                     * @param x X position
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Modify the position of the TextMessage
                     *
                     * @param y Y position
                     */
                    void modPosY(float y) override;

                    /**
                     * @brief Get the size on the X axis of the TextMessage
                     *
                     * @return `float` Size of the TextMessage
                     */
                    float getSizeX() const override;

                    /**
                     * @brief Get the size on the Y axis of the TextMessage
                     *
                     * @return `float` Size of the TextMessage
                     */
                    float getSizeY() const override;

                protected:
                private:
                    int _gap;
                    float _refGap;

                    std::unique_ptr<TextBox> _name;
                    std::unique_ptr<TextBox> _text;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_MESSAGE_HPP_ */
