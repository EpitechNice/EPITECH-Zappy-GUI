/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSliderVolume
*/

#ifndef COMPONENT_SLIDER_VOLUME_HPP_
    #define COMPONENT_SLIDER_VOLUME_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentText.hpp"
    #include "ComponentRectangle.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief SliderVolume class
             */
            class SliderVolume: public AComponent {
                public:
                    /**
                     * @brief Construct a new SliderVolume object
                     *
                     * @param pos Position of the slider
                     * @param width Width of the slider
                     * @param height Height of the slider
                     */
                    SliderVolume(std::pair<float, float> pos, float width, float height);

                    /**
                     * @brief Draw the slider
                     *
                     * @warning This function have to be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the slider
                     */
                    void resize() override;

                    /**
                     * @brief Update the slider
                     */
                    void update();

                    /**
                     * @brief Set the active state of the slider
                     *
                     * @param active The active state of the slider
                     */
                    void setActive(bool active);

                    /**
                     * @brief Set the value of the slider
                     *
                     * @param value The value of the slider
                     */
                    void setValue(float value);

                    /**
                     * @brief Get the active state of the slider
                     *
                     * @return `true` if the slider is active, `false` otherwise
                     */
                    bool getActive() const;

                    /**
                     * @brief Get the value of the slider
                     *
                     * @return `float` The value of the slider
                     */
                    float getValue() const;

                private:
                    bool _isDrag;
                    bool _active;
                    std::unique_ptr<Component::Rectangle> _background;
                    std::unique_ptr<Component::Rectangle> _value;
            };
        }
    }
}

#endif /* !COMPONENT_SLIDER_VOLUME_HPP_ */
