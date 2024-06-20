/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ResolutionOption
*/

#include "ResolutionOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        Scene::ResolutionOption::ResolutionOption(std::shared_ptr<Raylib::Render> render)
        {
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

            _render = render;
            _background = std::make_unique<Component::Background2D>("map_forest_scenery.png");
            _backButton = std::make_pair(std::make_unique<Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
            std::vector<std::pair<std::string, std::string>> buttons_resolution = {
                {"1920x1080", "Resolution_1920x1080"},
                {"1200x600", "Resolution_1200x600"},
                {"800x400", "Resolution_800x400"},
            };
            std::vector<std::pair<std::string, std::string>> buttons_fps = {
                {"30fps", "FPS_30"},
                {"60fps", "FPS_60"},
                {"120fps", "FPS_120"},
            };
            std::vector<std::pair<std::string, std::string>> text = {
                {i18nHelper->getTranslation("[menu.settings.resolution.res_title]"), "[menu.settings.resolution.res_title]"},
                {i18nHelper->getTranslation("[menu.settings.resolution.fps_title]"), "[menu.settings.resolution.fps_title]"},
                {i18nHelper->getTranslation("[menu.settings.resolution.delay_title]"), "[menu.settings.resolution.delay_title]"},
            };
            _lang = i18nHelper->getCurrentLocale();
            int buttonHeight = 30;
            int y = 0;
            int height = _render->getHeight();
            int buttonSpacing = 20;
            int buttonX = 0;
            int buttonY = 0;
            for (size_t i = 0; i < text.size(); ++i) {
                y = (height / (text.size() + 1)) * (i + 1) - 30;
                _text.push_back(std::make_pair(std::make_unique<Component::Text>(std::make_pair(_render->getWidth() / 5, y), text[i].first, 30, WHITE), text[i].second));
                buttonX = _render->getWidth() / 2.5;
                buttonY = y - buttonHeight / 2;
                if (text[i].second == "[menu.settings.resolution.res_title]") {
                    for (const auto& button : buttons_resolution) {
                        if (button.second == "Resolution_1200x600")
                            _resolutionButtons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, BLUE), button.second));
                        else
                            _resolutionButtons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                        buttonX += _resolutionButtons.back().first->getSizeX() + buttonSpacing;
                    }
                } else if (text[i].second == "[menu.settings.resolution.fps_title]") {
                    for (const auto& button : buttons_fps) {
                        if (button.second == "FPS_60")
                            _fpsButtons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, BLUE), button.second));
                        else
                            _fpsButtons.push_back(std::make_pair(std::make_unique<Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                        buttonX += _fpsButtons.back().first->getSizeX() + buttonSpacing;
                    }
                } else if (text[i].second == "[menu.settings.resolution.delay_title]") {
                    _delaySlider = std::make_unique<Component::DelayServerSection>(std::make_pair(buttonX, y - buttonHeight / 2), std::make_pair(_render->getWidth() / 4, buttonHeight * 2));
                }
            }
            _wannaResize = false;
        }

        void Scene::ResolutionOption::destroy()
        {
            _background->destroy();
        }

        void Scene::ResolutionOption::update()
        {
            Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

            if (i18nHelper->getCurrentLocale() != _lang) {
                for (auto &text : _text)
                    text.first->setText(i18nHelper->getTranslation(text.second));
                _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                _lang = i18nHelper->getCurrentLocale();
            }

            for (auto &button : _resolutionButtons) {
                if (button.first->isClicked(button.first->getText())){
                    for (auto &otherButton : _resolutionButtons) {
                        if (otherButton.first != button.first)
                            otherButton.first->setColor(GREEN);
                    }
                    button.first->setColor(BLUE);
                    _wannaResize = true;
                    if (button.second == "Resolution_1920x1080")
                        _render->setDimensions(1080, 1920);
                    else if (button.second == "Resolution_1200x600")
                        _render->setDimensions(600, 1200);
                    else if (button.second == "Resolution_800x400")
                        _render->setDimensions(400, 800);
                }
            }
            for (auto &button : _fpsButtons) {
                if (button.first->isClicked(button.first->getText())){
                    if (button.second == "FPS_30"){
                        _render->setFps(30);
                    } else if (button.second == "FPS_60")
                        _render->setFps(60);
                    else if (button.second == "FPS_120")
                        _render->setFps(120);
                    for (auto &otherButton : _fpsButtons) {
                        if (otherButton.first != button.first)
                            otherButton.first->setColor(GREEN);
                    }
                    button.first->setColor(BLUE);
                }
            }
            _delaySlider->update();
        }

        void Scene::ResolutionOption::draw2D()
        {
            _background->draw();
            _backButton.first->draw();
            for (auto &text : _text)
                text.first->draw();
            for (auto &button : _resolutionButtons)
                button.first->draw();
            for (auto &button : _fpsButtons)
                button.first->draw();
            _delaySlider->draw();
        }

        std::string Scene::ResolutionOption::nextScene()
        {
            if (_backButton.first->isClicked(_backButton.second))
                return "option";
            if (_wannaResize) {
                _wannaResize = false;
                return "resize";
            }
            return "resolutionSetting";
        }

        void Scene::ResolutionOption::resize()
        {
            _background->resize();
            _backButton.first->resize();
            for (auto &button : _resolutionButtons)
                button.first->resize();
            for (auto &button : _fpsButtons)
                button.first->resize();
            _delaySlider->resize();
            for (auto &text : _text)
                text.first->resize();
        }
    }
}