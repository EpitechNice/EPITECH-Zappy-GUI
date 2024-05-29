/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Option
*/

#include "OptionScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            Option::Option(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
            }

            void Option::destroy()
            {
                _backButton->destroy();
                _background->destroy();
            }


            void Option::start()
            {
                EnableCursor();
            }

            void Option::update()
            {
            }

            void Option::event()
            {
            }

            void Option::draw3D()
            {
            }

            void Option::draw2D()
            {
                _background->draw();
                _backButton->draw();
            }

            std::string Option::nextScene()
            {
                if (_backButton->isClicked())
                    return "menu";
                return "option";
            }
        }
    }
}