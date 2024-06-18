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

    #include "AComponent.hpp"
    #include "FontManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief TextBox component
             *
             * @note Same as Text component but with a maximum width
             */
            class TextBox: public AComponent {
                public:
                    /**
                     * @brief Construct a new TextBox object
                     *
                     * @param pos Position of the TextBox
                     * @param width Width of the TextBox
                     * @param text Text of the TextBox
                     * @param fontSize Font size of the TextBox
                     * @param color Color of the TextBox
                     * @param font Font of the TextBox
                     *
                     * @warning The font will be loaded using the FontManager. So it must be in the 'assets/fonts/' folder.
                     * @warning This function should be called in the raylib context
                     */
                    TextBox(std::pair<int, int> pos, int width, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");

                    /**
                     * @brief Draw the text
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the text
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the text of the TextBox
                     *
                     * @param text Text to set
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void setText(std::string text);

                protected:
                private:
                    std::string _text;
                    std::string _fontName;
                    int _fontSize;
                    Font _font;

                    float _refFontSize;
            };
        }
    }
}

#endif /* !COMPONENT_TEXT_BOX_HPP_ */
