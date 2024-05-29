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
                const std::pair<float, float> SMALL_BUTTON_SIZE = std::make_pair(-20, -10);
                const std::pair<float, float> BIG_BUTTON_SIZE = std::make_pair(-30, -15);
                _render = render;
                _music = true;
                _effetSonore = true;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
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
                        if (text[i].second == "Effet sonor"){
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "on", buttonHeight, GREEN), "cluster1"));
                            buttonX += buttonWidth + buttonSpacing;
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY * 1.07), SMALL_BUTTON_SIZE, "off", buttonHeight, RED), "cluster1"));
                        }
                        if (text[i].second == "Musique"){
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "on", buttonHeight, GREEN), "cluster2"));
                            buttonX += buttonWidth + buttonSpacing;
                            _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY * 1.015), SMALL_BUTTON_SIZE, "off", buttonHeight, RED), "cluster2"));
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
                                _render->setVolumeMusique(slider->getValue());
                            else if (slider->getName() == "slider2")
                                _render->setEffetSonore(slider->getValue());
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
                const std::pair<float, float> SMALL_BUTTON_SIZE = std::make_pair(-20, -10);
                const std::pair<float, float> BIG_BUTTON_SIZE = std::make_pair(-30, -15);

                for (auto &button : _buttons) {
                    if (button.first->isClicked()){
                        std::string buttonText = button.first->getText();
                        if (button.second == "cluster1" || button.second == "cluster2") {
                            bool musicState = (buttonText == "on");
                            if (button.second == "cluster1"){
                                _music = musicState;
                            } else{
                                _effetSonore = musicState;
                            }
                            for (auto &otherButton : _buttons) {
                                if (otherButton.second == button.second && otherButton.first->getText() != button.first->getText()){
                                    std::pair<float, float> newPosSmallButton;
                                    float yPos = (button.second == "cluster1") ? (_render->getHeight() / 5.9 - 30 / 2) : (_render->getHeight() / 1.8 - 30 / 2);
                                    float xPos = (button.first->getText() == "on") ? (_render->getWidth() / 2 + 180) : (_render->getWidth() / 2 + 60);
                                    newPosSmallButton = std::make_pair(xPos, yPos);
                                    otherButton.first->changePos(newPosSmallButton);
                                    otherButton.first->changeSize(SMALL_BUTTON_SIZE);
                                    otherButton.first->_modState(Zappy::GUI::Component::Button::CLICKED);
                                }
                            }
                            button.first->changeSize(BIG_BUTTON_SIZE);
                            return "soundSetting";
                        }
                    }
                }
                if (_backButton->isClicked()) {
                    return "option";
                }
                return "soundSetting";
            }
        }
    }
}