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
    #include "Render.hpp"
    #include "SoundManager.hpp"
    #include "ComponentVolumeSection.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class SoundOption : public AScene {
                public:
                    SoundOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~SoundOption() = default;

                    void destroy() override;
                    void update() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::unique_ptr<Zappy::GUI::Component::VolumeSection> _music;
                    std::unique_ptr<Zappy::GUI::Component::VolumeSection> _sound;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_SOUNDOPTION_HPP_ */
