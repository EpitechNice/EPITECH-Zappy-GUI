/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#include "SoundOptionScene.hpp"

namespace Zappy {
    namespace GUI {
//TODO : Fix music/sound effect issue (the two are interchanged)
        Scene::SoundOption::SoundOption(std::shared_ptr<Raylib::Render> render)
        {
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

            _render = render;
            _music = true;
            _effetSonore = true;
            _background = std::make_unique<Component::Background2D>("assets/img/map_forest_scenery.png");
            _backButton = std::make_pair(std::make_unique<Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
            std::vector<std::tuple<std::string, std::string, std::string>> text = {
                {i18nHelper->getTranslation("[menu.settings.sound.music_title]"), "soundEffect", "[menu.settings.sound.music_title]"},
                {i18nHelper->getTranslation("[menu.settings.sound.volume_title]"), "slider1", "[menu.settings.sound.volume_title]"},
                {i18nHelper->getTranslation("[menu.settings.sound.sound_effect_title]"), "music", "[menu.settings.sound.sound_effect_title]"},
                {i18nHelper->getTranslation("[menu.settings.sound.volume_title]"), "slider2", "[menu.settings.sound.volume_title]"},
            };
            _lang = i18nHelper->getCurrentLocale();
            int buttonHeight = 30;
            int y = 0;
            int height = _render->getHeight();
            int buttonSpacing = 60;
            int buttonWidth = 60;

            for (size_t i = 0; i < text.size(); ++i) {
                y = (height / (text.size() + 1)) * (i + 1) - 30;
                _text.push_back(std::make_pair(std::make_unique<Component::Text>(std::make_pair(_render->getWidth() / 4, y), std::get<0>(text[i]), 30, WHITE), std::get<2>(text[i])));
                int buttonX = _render->getWidth() / 2 + buttonSpacing;
                int buttonY = y - buttonHeight / 2;
                if (std::get<1>(text[i]) != "slider1" && std::get<1>(text[i]) != "slider2") {
                    if (std::get<1>(text[i]) == "soundEffect"){
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "ON", buttonHeight, GREEN), "slider1"));
                        buttonX += buttonWidth + buttonSpacing;
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY * 1.07), SMALL_BUTTON_SIZE, "OFF", buttonHeight, RED), "slider1"));
                    }
                    if (std::get<1>(text[i]) == "music"){
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), BIG_BUTTON_SIZE, "ON", buttonHeight, GREEN), "slider2"));
                        buttonX += buttonWidth + buttonSpacing;
                        _buttons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY * 1.015), SMALL_BUTTON_SIZE, "OFF", buttonHeight, RED), "slider2"));
                    }
                } else {
                    _volumeSlider.emplace_back(std::make_unique<Component::SliderVolume>(std::make_pair(_render->getWidth() / 1.92, y * 1.025), 300, 20, std::get<1>(text[i])));
                }
            }
        }

        void Scene::SoundOption::destroy()
        {
            for (auto &text : _text)
                text.first->destroy();
            for (auto &button : _buttons)
                button.first->destroy();
            _buttons.clear();
            for (auto& slider : _volumeSlider)
                slider->destroy();
            _volumeSlider.clear();
            _backButton.first->destroy();
            _background->destroy();
        }

        void Scene::SoundOption::start()
        {}

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

        void Scene::SoundOption::update()
        {
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

            if (i18nHelper->getCurrentLocale() != _lang) {
                for (auto &text : _text)
                    text.first->setText(i18nHelper->getTranslation(text.second));
                _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                _lang = i18nHelper->getCurrentLocale();
            }
        }

        void Scene::SoundOption::draw3D()
        {
        }

        void Scene::SoundOption::draw2D()
        {
            _background->draw();
            _backButton.first->draw();
            for (auto& slider : _volumeSlider)
                slider->draw();
            for (auto &text : _text)
                text.first->draw();
            for (auto &button : _buttons)
                button.first->draw();
        }

        bool Scene::SoundOption::handleButtonClicked(const std::pair<std::unique_ptr<Component::Button>, std::string> &button)
        {
            std::string buttonText = button.first->getText();
            if (button.second == "slider1" || button.second == "slider2") {
                bool musicState = (buttonText == "ON");
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
                    float xPos = (clickedButton.first->getText() == "ON") ? (_render->getWidth() / 2 + 180) : (_render->getWidth() / 2 + 60);
                    for (auto &slider : _volumeSlider) {
                        if (clickedButton.second == slider->getName())
                            adjustSliderVolume(slider, clickedButton.first->getText() == "ON");
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
                slider->setStatut(true);
            } else {
                if (slider->getName() == "slider1")
                    Sfml::SoundManager::getInstance().setVolumeGeneralMusique(0.0f);
                else
                    Sfml::SoundManager::getInstance().setVolumeEffetSonore(0.0f);
                slider->setStatut(false);
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
                if (button.first->isClicked(button.first->getText()))
                    handleButtonClicked(button);
            }
            if (_backButton.first->isClicked(_backButton.second))
                return "option";
            return "soundSetting";
        }
    }
}