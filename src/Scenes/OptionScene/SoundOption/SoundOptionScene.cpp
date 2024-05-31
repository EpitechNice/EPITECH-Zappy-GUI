/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#include "SoundOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        Scene::SoundOption::SoundOption(std::shared_ptr<Raylib::Render> render)
        {
            _render = render;
            _music = true;
            _effetSonore = true;
            _background = std::make_unique<Component::Background2D>("assets/img/map_forest_scenery.png");
            _backButton = std::make_unique<Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
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
                _text.push_back(std::make_unique<Component::Text>(std::make_pair(_render->getWidth() / 4, y), text[i].first, 30, WHITE));
                int buttonX = _render->getWidth() / 2 + buttonSpacing;
                int buttonY = y - buttonHeight / 2;
                if (text[i].first != "Volume :"){
                    if (text[i].second == "Effet sonor"){
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "on", buttonHeight, GREEN), "slider1"));
                        buttonX += buttonWidth + buttonSpacing;
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY * 1.07), SMALL_BUTTON_SIZE, "off", buttonHeight, RED), "slider1"));
                    }
                    if (text[i].second == "Musique"){
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "on", buttonHeight, GREEN), "slider2"));
                        buttonX += buttonWidth + buttonSpacing;
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY * 1.015), SMALL_BUTTON_SIZE, "off", buttonHeight, RED), "slider2"));
                    }
                } else {
                    _volumeSlider.emplace_back(std::make_unique<Component::SliderVolume>(std::make_pair(_render->getWidth() / 1.92, y * 1.025), 300, 20, text[i].second));
                }
            }
        }

        void Scene::SoundOption::destroy()
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

        void Scene::SoundOption::start()
        {
        }

        void Scene::SoundOption::event()
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
                        if (slider->getName() == "slider1" && _music){
                            slider->updateValue();
                            Sfml::SoundManager::getInstance().setVolumeGeneralMusique(slider->getValue());
                        } else if (slider->getName() == "slider2" && _effetSonore){
                            slider->updateValue();
                            Sfml::SoundManager::getInstance().setVolumeEffetSonore(slider->getValue());
                        }
                    }
                }
            }
        }

        void Scene::SoundOption::draw3D()
        {
        }

        void Scene::SoundOption::draw2D()
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

        bool Scene::SoundOption::handleButtonClicked(const std::pair<std::unique_ptr<Component::Button>, std::string> &button)
        {
            std::string buttonText = button.first->getText();
            if (button.second == "slider1" || button.second == "slider2") {
                bool musicState = (buttonText == "on");
                (button.second == "slider1") ? _music = musicState : _effetSonore = musicState;
                adjustButtonPositions(button);
                adjustSoundVolume(button, musicState);
                return true;
            }
            return false;
        }

        void Scene::SoundOption::adjustButtonPositions(const std::pair<std::unique_ptr<Component::Button>, std::string> &clickedButton)
        {
            for (auto &otherButton : _buttons) {
                if (otherButton.second == clickedButton.second && otherButton.first->getText() != clickedButton.first->getText()) {
                    std::pair<float, float> newPosSmallButton;
                    float yPos = (clickedButton.second == "slider1") ? (_render->getHeight() / 5.9 - 30 / 2) : (_render->getHeight() / 1.8 - 30 / 2);
                    float xPos = (clickedButton.first->getText() == "on") ? (_render->getWidth() / 2 + 180) : (_render->getWidth() / 2 + 60);
                    for (auto &slider : _volumeSlider) {
                        if (clickedButton.second == slider->getName())
                            adjustSliderVolume(slider, clickedButton.first->getText() == "on");
                    }
                    newPosSmallButton = std::make_pair(xPos, yPos);
                    otherButton.first->changePos(newPosSmallButton);
                    otherButton.first->changeSize(SMALL_BUTTON_SIZE);
                    otherButton.first->_modState(Component::Button::CLICKED);
                }
            }
            clickedButton.first->changeSize(BIG_BUTTON_SIZE);
        }

        void Scene::SoundOption::adjustSliderVolume(std::unique_ptr<Component::SliderVolume> &slider, bool isButtonOn)
        {
            if (isButtonOn) {
                if (slider->getName() == "slider1")
                    Sfml::SoundManager::getInstance().setVolumeGeneralMusique(slider->getValue());
                else
                    Sfml::SoundManager::getInstance().setVolumeEffetSonore(slider->getValue());
                slider->setStatut(slider->getValue());
            } else {
                if (slider->getName() == "slider1")
                    Sfml::SoundManager::getInstance().setVolumeGeneralMusique(0.0f);
                else
                    Sfml::SoundManager::getInstance().setVolumeEffetSonore(0.0f);
                slider->setStatut(0.0f);
            }
        }

        void Scene::SoundOption::adjustSoundVolume(const std::pair<std::unique_ptr<Component::Button>, std::string> &button, bool isButtonOn)
        {
            for (auto &slider : _volumeSlider) {
                if (button.second == slider->getName())
                    adjustSliderVolume(slider, isButtonOn);
            }
        }

        std::string Scene::SoundOption::nextScene()
        {
            for (auto &button : _buttons) {
                if (button.second == "slider2" && button.first->isClickedWihoutSong())
                    handleButtonClicked(button);
            }
            for (auto &button : _buttons) {
                if (button.first->isClicked())
                    handleButtonClicked(button);
            }
            if (_backButton->isClicked())
                return "option";
            return "soundSetting";
        }
    }
}