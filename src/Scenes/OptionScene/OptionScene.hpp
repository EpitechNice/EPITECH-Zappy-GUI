/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Option
*/

#ifndef SCENE_OPTION_HPP_
    #define SCENE_OPTION_HPP_

    #include <memory>
    #include <chrono>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "I18nHelper.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Option : public AScene {
                public:
                    Option(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Option() = default;

                    void start() override;
                    void destroy() override;
                    void update() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string>> _generalButtons;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, Zappy::GUI::I18n::SupportedLocale, std::string>> _languageButtons;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Text>, std::string>> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_OPTION_HPP_ */
