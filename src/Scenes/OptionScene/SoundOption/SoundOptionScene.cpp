/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#include "SoundOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            SoundOption::SoundOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_classic_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                std::vector<std::pair<std::string, std::string>> buttons = {
                    {"on", "true"},
                    {"off", "false"},
                };
                std::vector<std::string> text = {
                    "Effet Sonor :",
                    "Musique :",
                };
                int buttonHeight = 30;
                int y = 0;
                int height = GetScreenHeight();
                int buttonSpacing = 60;
                int buttonWidth = 60;
                for (size_t i = 0; i < text.size(); ++i) {
                    y = (height / (text.size() + 1)) * (i + 1) - 30;
                    _text.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(GetScreenWidth() / 4, y), text[i], 30, WHITE), text[i]));
                    int buttonX = GetScreenWidth() / 2 + buttonSpacing;
                    int buttonY = y - buttonHeight / 2;
                    for (const auto& button : buttons) {
                        if (button.first == "off")
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, RED), button.second));
                        else
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                        buttonX += buttonWidth + buttonSpacing;
                    }
                }
            }

            void SoundOption::destroy()
            {
                for (auto &text : _text)
                    text.first->destroy();
                for (auto &button : _buttons)
                    button.first->destroy();
                _buttons.clear();
                _backButton->destroy();
                _background->destroy();
            }


            void SoundOption::start()
            {
            }

            void SoundOption::event()
            {
            }

            void SoundOption::draw3D()
            {
            }

            void SoundOption::draw2D()
            {
                _background->draw();
                _backButton->draw();
                for (auto &text : _text)
                    text.first->draw();
                for (auto &button : _buttons)
                    button.first->draw();
            }

            std::string SoundOption::nextScene()
            {
                for (auto &button : _buttons) {
                    if (button.first->isClicked())
                        return button.second;
                    if (_backButton->isClicked())
                        return "option";
                }
                return "soundSetting";
            }
        }
    }
}