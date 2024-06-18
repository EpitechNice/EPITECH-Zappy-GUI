/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButton
*/

#ifndef COMPONENT_BUTTON_CLASSIC_HPP_
    #define COMPONENT_BUTTON_CLASSIC_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentCircle.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Button class
             */
            class ButtonClassic: public AComponent {
                public:
                    /**
                     * @brief Button state
                     *
                     * @note `NONE` is used to initialize the state
                     * @note `DEFAULT` is the default state
                     * @note `HOVER` is the state when the mouse is over the button
                     * @note `CLICKED` is the state when the button is clicked
                     */
                    typedef enum {
                        NONE = -1,
                        DEFAULT,
                        HOVER,
                        CLICKED
                    } State;

                    /**
                     * @brief Button constructor
                     *
                     * @param pos Position of the button
                     * @param size Size of the button
                     * @param text Text of the button
                     * @param textSize Text size of the button
                     * @param color Color of the button
                     *
                     * @warning This function should be called in the raylib context
                     */
                    ButtonClassic(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);

                    /**
                     * @brief Draw the button
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the button
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the button
                     *
                     * @param x X position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Set the position of the button
                     *
                     * @param y Y position
                     */
                    void setPosY(float y) override;

                    /**
                     * @brief Modify the position of the button
                     *
                     * @param x X position
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Modify the position of the button
                     *
                     * @param y Y position
                     */
                    void modPosY(float y) override;

                    /**
                     * @brief Set the color of the button
                     *
                     * @param color Color of the button
                     */
                    void setColor(Color color) override;

                    /**
                     * @brief Check if the button is clicked
                     *
                     * @return `true` if the button is clicked, `false` otherwise
                     */
                    bool isClicked() const;

                    /**
                     * @brief Enable the text stroke
                     */
                    void enableTextStroke();

                    /**
                     * @brief Disable the text stroke
                     */
                    void disableTextStroke();

                    /**
                     * @brief Enable the button state
                     */
                    void enableState();

                    /**
                     * @brief Disable the button state
                     */
                    void disableState();

                protected:
                private:
                    State _state;
                    bool _textStrokeVisible;
                    bool _stateEnabled;
                    time_t _lastClick;

                    std::unique_ptr<RoundedRectangle> _button;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Text> _textStroke;

                    void _updateState();
                    void _modState(State oldState);
            };
        }
    }
}

#endif /* !COMPONENT_BUTTON_CLASSIC_HPP_ */
