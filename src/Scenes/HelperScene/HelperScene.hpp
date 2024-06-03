/*
** EPITECH PROJECT, 2024
** gui
** File description:
** HelperScene
*/

#ifndef SCENE_HELPERSCENE_HPP_
    #define SCENE_HELPERSCENE_HPP_

    #include <memory>
    #include <chrono>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class HelperScene : public AScene {
                public:
                    HelperScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text);
                    HelperScene() = default;

                    void start() override;
                    void destroy() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::unique_ptr<Zappy::GUI::Component::Button> _backButton;
                    std::unique_ptr<Zappy::GUI::Component::Text> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_HELPERSCENE_HPP_ */
