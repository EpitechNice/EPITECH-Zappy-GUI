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
                int x_generalButton = _render->getWidth() / 2;
                int y_generalButton = 0;
                int i_generalButton = 0;
                int height = _render->getHeight() / 1.5;
                std::vector<std::pair<std::string, std::string>> buttons = {
                    {"SOUND", "soundSetting"},
                    {"RESOLUTION", "resolutionSetting"},
                };
                std::vector<std::string> buttons_langue = {
                    "ANGLAIS",
                    "FRANCAIS",
                    "ESPAGNOL",
                    "MANDARIN",
                };
                for (auto &button : buttons) {
                    auto button_width = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), button.first, 30, GREEN)->getSize().first;
                    y_generalButton = (height / (buttons.size() + 1)) * (i_generalButton + 1) - 30;
                    x_generalButton -= button_width / 2;
                    _generalButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_generalButton, y_generalButton), std::make_pair(-20, -10), button.first, 30, GREEN), button.second));
                    x_generalButton += button_width / 2;
                    i_generalButton++;
                }
                _text.push_back(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(x_generalButton * 0.9 , y_generalButton * 1.5), "LANGUE :", 30, WHITE));
                int x_langueButton = x_generalButton / 2;
                int y_langueButton = y_generalButton * 1.5 + 50;
                int i_langueButton = 20;
                for (auto &button : buttons_langue) {
                    y_langueButton = y_langueButton;
                    x_langueButton += i_langueButton;
                    if (!_langueButtons.empty())
                        x_langueButton += _langueButtons.back().first->getSize().first;
                    if (button == "FRANCAIS")
                        _langueButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_langueButton, y_langueButton), std::make_pair(-20, -10), button, 18, BLUE), button));
                    else
                        _langueButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_langueButton, y_langueButton), std::make_pair(-20, -10), button, 18, GREEN), button));
                }
            }

            void Option::destroy()
            {
                for (auto &text : _text)
                    text->destroy();
                for (auto &button : _generalButtons)
                    button.first->destroy();
                for (auto &button : _langueButtons)
                    button.first->destroy();
                _generalButtons.clear();
                _backButton->destroy();
                _background->destroy();
            }

            void Option::start()
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
                for (auto &button : _generalButtons)
                    button.first->draw();
                for (auto &button : _langueButtons)
                    button.first->draw();
                for (auto &text : _text)
                    text->draw();
            }

            std::string Option::nextScene()
            {
                for (auto &button : _generalButtons) {
                    if (button.first->isClicked())
                        return button.second;
                    if (_backButton->isClicked())
                        return "menu";
                }
                for (auto &button : _langueButtons) {
                    if (button.first->isClicked()) {
                        if (button.second == "FRANCAIS")
                            _render->setLangue(FRANCAIS);
                        else if (button.second == "ANGLAIS")
                            _render->setLangue(ANGLAIS);
                        else if (button.second == "ESPAGNOL")
                            _render->setLangue(ESPAGNOL);
                        else if (button.second == "MANDARIN")
                            _render->setLangue(MANDARIN);
                        for (auto &otherButton : _langueButtons) {
                            if (otherButton.first != button.first)
                                otherButton.first->changeColor(GREEN);
                        }
                        button.first->changeColor(BLUE);
                    }
                }
                return "option";
            }
        }
    }
}