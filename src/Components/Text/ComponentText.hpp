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

    #include "AComponent.hpp"
    #include "FontManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Text component
             */
            class Text: public AComponent {
                public:
                    /**
                     * @brief Construct a new Text object
                     *
                     * @param pos The position of the text
                     * @param text The text to display
                     * @param fontSize The size of the text
                     * @param color The color of the text
                     * @param font The font of the text
                     *
                     * @warning The font will be loaded using the FontManager. So it must be in the 'assets/fonts/' folder.
                     */
                    Text(std::pair<float, float> pos, std::string text, int fontSize, Color color, std::string font = "supercell.ttf");

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
                     * @brief Set the text
                     *
                     * @param text The text to set
                     */
                    void setText(std::string text);

                    /**
                     * @brief Get the text
                     *
                     * @return `std::string` The text
                     */
                    std::string getText() const;

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

#endif /* !COMPONENT_TEXT_HPP_ */
