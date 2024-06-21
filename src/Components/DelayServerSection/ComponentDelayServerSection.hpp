/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentDelayServerSection
*/

#ifndef COMPONENT_DELAYSERVER_SECTION_HPP_
    #define COMPONENT_DELAYSERVER_SECTION_HPP_

    #include <raylib.h>
    #include <memory>

    #include "AComponent.hpp"
    #include "ComponentSliderVolume.hpp"
    #include "ComponentText.hpp"
    #include "SoundManager.hpp"
    #include "ComponentButton.hpp"
    #include "Ref.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Class representing the delay server section
             */
            class DelayServerSection : public AComponent {
                public:
                    /**
                     * @brief Construct a new Delay Server Section object
                     *
                     * @param pos Position of the section
                     * @param size Size of the section
                     */
                    DelayServerSection(std::pair<float, float> pos, std::pair<float, float> size);

                    /**
                     * @brief Draw the section
                     */
                    void draw() override;

                    /**
                     * @brief Resize the section
                     */
                    void resize() override;

                    /**
                     * @brief Update the section
                     */
                    void update();

                    /**
                     * @brief Set the delay
                     */
                    void setDelay(float delay);

                private:
                    std::unique_ptr<SliderVolume> _slider;
            };
        }
    }
}

#endif /* !COMPONENT_DELAYSERVER_SECTION_HPP_ */
