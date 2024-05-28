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
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _generalButtons;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_CREDITSCENE_HPP_ */
