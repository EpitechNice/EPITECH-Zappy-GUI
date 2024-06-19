/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ResolutionOption
*/

#ifndef SCENE_RESOLUTIONOTIONSCENE_HPP_
    #define SCENE_RESOLUTIONOTIONSCENE_HPP_

    #include <memory>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentText.hpp"
    #include "SceneManager.hpp"
    #include "ComponentDelayServerSection.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class ResolutionOption : public AScene {
                public:
                    ResolutionOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~ResolutionOption() = default;

                    void destroy() override;
                    void update() override;
                    void draw2D() override;
                    void resize() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _resolutionButtons;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _fpsButtons;
                    std::unique_ptr<Zappy::GUI::Component::DelayServerSection> _delaySlider;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Text>, std::string>> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
                    bool _wannaResize = false;
            };
        }
    }
}

#endif /* !SCENE_RESOLUTIONOTIONSCENE_HPP_ */
