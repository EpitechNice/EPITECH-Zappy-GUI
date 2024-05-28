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

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Option : public AScene {
                public:
                    typedef enum {
                        FRANCAIS,
                        ANGLAIS,
                        ESPAGNOL,
                        MANDARIN,
                    } Langue;

                    Option(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Option() = default;

                    void start() override;
                    void destroy() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    Langue _langue;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::unique_ptr<Zappy::GUI::Component::Button> _backButton;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _generalButtons;
                    std::vector<std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string>> _langueButtons;
                    std::vector<std::unique_ptr<Zappy::GUI::Component::Text>> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
            };
        }
    }
}

#endif /* !SCENE_OPTION_HPP_ */
