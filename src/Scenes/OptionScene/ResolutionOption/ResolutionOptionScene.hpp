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

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class ResolutionOption : public AScene {
                public:
                    typedef enum {
                        Resolution_2960x1440,
                        Resolution_1920x1080,
                        Resolution_1334x750,
                    } Resolution;

                    typedef enum {
                        FPS_30,
                        FPS_60,
                        FPS_120,
                    } Fps;

                    ResolutionOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~ResolutionOption() = default;

                    void start() override;
                    void destroy() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    Resolution _resolution;
                    Fps _fps;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::unique_ptr<Zappy::GUI::Component::Button> _backButton;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _resolutionButtons;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _fpsButtons;
                    std::vector<std::unique_ptr<Zappy::GUI::Component::Text>> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_RESOLUTIONOTIONSCENE_HPP_ */
