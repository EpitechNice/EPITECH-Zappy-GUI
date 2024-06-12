/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Credit
*/

#ifndef SCENE_CREDITSCENE_HPP_
    #define SCENE_CREDITSCENE_HPP_

    #include <memory>
    #include <chrono>
    #include <vector>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Credit : public AScene {
                public:
                    Credit(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Credit() = default;

                    void destroy() override;
                    void update() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string>> _generalButtons;
                    std::vector<std::pair<float, float>> _buttonsPositions;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_CREDITSCENE_HPP_ */
