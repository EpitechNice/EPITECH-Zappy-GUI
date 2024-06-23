/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentVolumeSection
*/

#ifndef COMPONENT_VOLUME_SECTION_HPP_
    #define COMPONENT_VOLUME_SECTION_HPP_

    #include <raylib.h>
    #include <memory>

    #include "AComponent.hpp"
    #include "ComponentSliderVolume.hpp"
    #include "ComponentText.hpp"
    #include "SoundManager.hpp"
    #include "ComponentButton.hpp"
    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief VolumeSection class
             */
            class VolumeSection : public AComponent {
                public:
                    /**
                     * @brief Construct a new VolumeSection object
                     *
                     * @param pos Position of the volume section
                     * @param size Size of the volume section
                     * @param text Text of the volume section
                     * @param callback Callback of the volume section (call a method from SoundManager)
                     */
                    VolumeSection(std::pair<float, float> pos, std::pair<float, float> size, std::string text, void (Zappy::GUI::Sfml::SoundManager::*callback)(float));

                    /**
                     * @brief Draw the volume section
                     */
                    void draw() override;

                    /**
                     * @brief Resize the volume section
                     */
                    void resize() override;

                    /**
                     * @brief Update the volume section
                     */
                    void update();

                    /**
                     * @brief Set the text of the volume section
                     *
                     * @param text Text to set
                     */
                    void setText(std::string text);

                private:
                    void (Zappy::GUI::Sfml::SoundManager::*_callback)(float);
                    std::unique_ptr<SliderVolume> _slider;
                    std::unique_ptr<Component::Text> _text;
                    std::unique_ptr<Component::Button> _on;
                    std::unique_ptr<Component::Button> _off;
            };
        }
    }
}

#endif /* !COMPONENT_VOLUME_SECTION_HPP_ */
