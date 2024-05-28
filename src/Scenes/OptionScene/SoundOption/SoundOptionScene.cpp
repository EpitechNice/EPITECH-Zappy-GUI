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
                _volumeEffetSonore = 0.5f;
                _volumeMusique = 0.5f;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                std::vector<std::pair<std::string, std::string>> buttons = {
                    {"on", "true"},
                    {"off", "false"},
                };
                std::vector<std::pair<std::string, std::string>> text = {
                    {"Effet Sonor :", "Effet sonor"},
                    {"Volume :", "slider1"},
                    {"Musique :", "Musique"},
                    {"Volume :", "slider2"},
                };
                int buttonHeight = 30;
                int y = 0;
                int height = _render->getHeight();
                int buttonSpacing = 60;
                int buttonWidth = 60;
                for (size_t i = 0; i < text.size(); ++i) {
                    y = (height / (text.size() + 1)) * (i + 1) - 30;
                    _text.push_back(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(_render->getWidth() / 4, y), text[i].first, 30, WHITE));
                    int buttonX = _render->getWidth() / 2 + buttonSpacing;
                    int buttonY = y - buttonHeight / 2;
                    if (text[i].first != "Volume :"){
                        for (const auto& button : buttons) {
                            if (button.first == "off")
                                _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, RED), button.second));
                            else
                                _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                            buttonX += buttonWidth + buttonSpacing;
                        }
                    } else {
                        _volumeSlider.emplace_back(std::make_unique<Zappy::GUI::Component::SliderVolume>(std::make_pair(_render->getWidth() / 1.92, y * 1.025), 300, 20, text[i].second));
                    }
                }
            }

            void SoundOption::destroy()
            {
                for (auto &text : _text)
                    text->destroy();
                for (auto &button : _buttons)
                    button.first->destroy();
                _buttons.clear();
                for (auto& slider : _volumeSlider)
                    slider->destroy();
                _volumeSlider.clear();
                _backButton->destroy();
                _background->destroy();
            }


            void SoundOption::start()
            {
            }

            void SoundOption::event()
            {
                for (auto& slider : _volumeSlider) {
                    Rectangle cursorRect = {
                        slider->getPos().first,
                        slider->getPos().second,
                        slider->getWidth(),
                        slider->getHeight()
                    };
                    if (CheckCollisionPointRec(GetMousePosition(), cursorRect)) {
                        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                            slider->updateValue();
                            if (slider->getName() == "slider1")
                                _volumeMusique = slider->getValue();
                            else if (slider->getName() == "slider2")
                                _volumeEffetSonore = slider->getValue();
                        }
                    }
                }
            }

            void SoundOption::draw3D()
            {
            }

            void SoundOption::draw2D()
            {
                _background->draw();
                _backButton->draw();
                for (auto& slider : _volumeSlider)
                    slider->draw();
                for (auto &text : _text)
                    text->draw();
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