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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class VolumeSection : public AComponent {
                public:
                    VolumeSection(std::pair<float, float> pos, std::pair<float, float> size, std::string text, void (Zappy::GUI::Sfml::SoundManager::*callback)(float));

                    void draw() override;

                    void update();
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
