/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButton
*/

#ifndef COMPONENT_BUTTON_HPP_
    #define COMPONENT_BUTTON_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentCircle.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "../Sfml/SoundManager/SoundManager.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Button class
             */
            class Button: public AComponent {
                public:
                    /**
                     * @brief Button state
                     *
                     * @note `NONE` is used to initialize the state
                     * @note `DEFAULT` is the default state
                     * @note `HOVER` is the state when the mouse is over the button
                     * @note `CLICKED` is the state when the button is clicked
                     * @note `DISABLED` is the state when the button is disabled
                     */
                    typedef enum {
                        NONE = -1,
                        DEFAULT,
                        HOVER,
                        CLICKED,
                        DISABLED
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
                    Button(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);

                    /**
                     * @brief Draw the button
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the button
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the button
                     *
                     * @param x The x position
                     */
                    void setPosX(float x) override;

                    /**
                     * @brief Modify the position of the button
                     *
                     * @param x The x position
                     */
                    void modPosX(float x) override;

                    /**
                     * @brief Set the position of the button
                     *
                     * @param Y The y position
                     */
                    void setPosY(float Y) override;

                    /**
                     * @brief Modify the position of the button
                     *
                     * @param Y The y position
                     */
                    void modPosY(float y) override;

                    /**
                     * @brief Set the size of the button
                     *
                     * @param x The x size
                     */
                    void setSizeX(float x) override;

                    /**
                     * @brief Set the size of the button
                     *
                     * @param y The y size
                     */
                    void setSizeY(float y) override;

                    /**
                     * @brief Set the color of the button
                     *
                     * @param color The color of the button
                     */
                    void setColor(Color color) override;

                    /**
                     * @brief Check if the button is hovered
                     *
                     * @return `bool` True if the button is hovered, `false` otherwise
                     */
                    bool isHover() const;

                    /**
                     * @brief Check if the button is clicked
                     *
                     * @return `bool` True if the button is clicked, `false` otherwise
                     */
                    bool isClickedWihoutSong() const;

                    /**
                     * @brief Check if the button is clicked
                     *
                     * @param textButton The text of the button
                     *
                     * @return `bool` True if the button is clicked, `false` otherwise
                     */
                    bool isClicked() const;

                    /**
                     * @brief Check if the button is clicked
                     *
                     * @param textButton The text of the button
                     *
                     * @return `bool` True if the button is clicked, `false` otherwise
                     */
                    bool isClicked(std::string textButton);

                    /**
                     * @brief Set the text of the button
                     *
                     * @param text The text of the button
                     */
                    void setText(std::string text);

                    /**
                     * @brief Get the text of the button
                     *
                     * @return `std::string` The text of the button
                     */
                    std::string getText() const;

                    /**
                     * @brief Set the state of the button
                     *
                     * @param state The state of the button
                     */
                    void setState(State state);

                protected:
                private:
                    float _initialSizeX;
                    float _initialSizeY;

                    std::pair<float, float> _textPos;
                    State _state;
                    int _pressEffect = 6;
                    int _hoverEffect = 2;
                    float _refPressEffect;
                    float _refHoverEffect;
                    bool _bubble;
                    time_t _lastClick;

                    std::unique_ptr<RoundedRectangle> _blackStroke;
                    std::unique_ptr<RoundedRectangle> _upEffect;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<RoundedRectangle> _topButton;
                    std::unique_ptr<RoundedRectangle> _reflexioneffect;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Text> _textStroke;

                    void _updateState();
                    void _modState(State oldState);
                    void _changeSize(float sizeX, float sizeY);
            };
        }
    }
}

#endif /* !COMPONENT_BUTTON_HPP_ */
