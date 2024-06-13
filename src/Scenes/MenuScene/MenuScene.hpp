/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Menu
*/

#ifndef SCENE_MENU_HPP_
    #define SCENE_MENU_HPP_

    #include <memory>
    #include <vector>
    #include <string>
    #include <tuple>

    #include "AScene.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentImage.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Menu : public AScene {
                public:
                    Menu(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Menu() = default;

                    void start() override;
                    void destroy() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                    void update(bool isGameReady);

                protected:
                private:
                    bool _isGameReady;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string>> _buttons;
                    std::unique_ptr<Zappy::GUI::Component::Image> _logo;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_MENU_HPP_ */
