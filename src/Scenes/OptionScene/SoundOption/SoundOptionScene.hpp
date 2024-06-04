/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#ifndef SCENE_SOUNDOPTION_HPP_
    #define SCENE_SOUNDOPTION_HPP_

    #include <memory>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentText.hpp"
    #include "SliderVolume.hpp"
    #include "Render.hpp"
    #include "../Sfml/SoundManager/SoundManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class SoundOption : public AScene {
                public:
                    SoundOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~SoundOption() = default;

                    void start() override;
                    void destroy() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    static constexpr std::pair<float, float> SMALL_BUTTON_SIZE = std::make_pair(-20.0f, -10.0f);
                    static constexpr std::pair<float, float> BIG_BUTTON_SIZE = std::make_pair(-30.0f, -15.0f);

                    bool handleButtonClicked(const std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> &button);
                    void adjustButtonPositions(const std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> &clickedButton);
                    void adjustSliderVolume(std::unique_ptr<Zappy::GUI::Component::SliderVolume> &slider, bool isButtonOn);
                    void adjustSoundVolume(const std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> &button, bool isButtonOn);

                    std::string nextScene() override;

                protected:
                private:
                    bool _music;
                    bool _effetSonore;
                    bool _SliderIsActif;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::unique_ptr<Zappy::GUI::Component::Button> _backButton;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _buttons;
                    std::vector<std::unique_ptr<Zappy::GUI::Component::Text>> _text;
                    std::vector<std::unique_ptr<Zappy::GUI::Component::SliderVolume>> _volumeSlider;
                    Zappy::GUI::Component::SliderVolume* _activeSlider;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_SOUNDOPTION_HPP_ */
