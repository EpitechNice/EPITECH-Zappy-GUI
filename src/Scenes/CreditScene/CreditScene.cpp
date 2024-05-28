/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Credit
*/

#include "CreditScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            Credit::Credit(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                int x_generalButton = GetScreenWidth() / 2;
                int y_generalButton = 0;
                int i_generalButton = 0;
                int height = GetScreenHeight();
                std::vector<std::pair<std::string, std::string>> buttons = {
                    {"Credit1", "credit1"},
                    {"Credit2", "credit2"},
                    {"Credit3", "credit3"},
                };
                for (auto &button : buttons) {
                    auto button_width = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), button.first, 30, GREEN)->getSize().first;
                    y_generalButton = (height / (buttons.size() + 1)) * (i_generalButton + 1) - 30;
                    x_generalButton -= button_width / 2;
                    _generalButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_generalButton, y_generalButton), std::make_pair(-20, -10), button.first, 30, GREEN), button.second));
                    x_generalButton += button_width / 2;
                    i_generalButton++;
                }
            }

            void Credit::destroy()
            {
                for (auto &button : _generalButtons)
                    button.first->destroy();
                _generalButtons.clear();
                _backButton->destroy();
                _background->destroy();
            }

            void Credit::start()
            {
            }

            void Credit::event()
            {
            }

            void Credit::draw3D()
            {
            }

            void Credit::draw2D()
            {
                _background->draw();
                _backButton->draw();
                for (auto &button : _generalButtons)
                    button.first->draw();
            }

            std::string Credit::nextScene()
            {
                for (auto &button : _generalButtons) {
                    if (button.first->isClicked())
                        return button.second;
                    if (_backButton->isClicked())
                        return "menu";
                }
                return "credits";
            }
        }
    }
}