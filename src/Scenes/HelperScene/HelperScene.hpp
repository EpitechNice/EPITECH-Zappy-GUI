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
    #include "ComponentTextBox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class HelperScene : public AScene {
                public:
                    HelperScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text);
                    HelperScene() = default;

                    void destroy() override;
                    void update() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::TextBox>, std::string> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_HELPERSCENE_HPP_ */
