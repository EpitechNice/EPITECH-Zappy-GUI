/*
** EPITECH PROJECT, 2024
** gui
** File description:
** DisplayCreditScene
*/

#ifndef SCENE_CREDIT3SCENE_HPP_
    #define SCENE_CREDIT3SCENE_HPP_

    #include <memory>
    #include <chrono>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class CreditScene : public AScene {
                public:
                    CreditScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text, int sceneNbr);
                    CreditScene() = default;

                    void start() override;
                    void destroy() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    int _sceneNbr;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::unique_ptr<Zappy::GUI::Component::Button> _backButton;
                    std::unique_ptr<Zappy::GUI::Component::Text> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_CREDIT3SCENE_HPP_ */
