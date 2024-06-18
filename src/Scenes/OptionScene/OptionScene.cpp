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
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("map_forest_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");

                std::vector<std::tuple<std::string, std::string, std::string>> buttons = {
                    {i18nHelper->getTranslation("[menu.settings.sound_button]"), "soundSetting", "[menu.settings.sound_button]"},
                    {i18nHelper->getTranslation("[menu.settings.resolution_button]"), "resolutionSetting", "[menu.settings.resolution_button]"},
                };
                std::vector<std::tuple<std::string, Zappy::GUI::I18n::SupportedLocale, std::string>> buttonsLanguageValue = {
                    {i18nHelper->getTranslation("[menu.settings.lang.en_GB_button]"), Zappy::GUI::I18n::SupportedLocale::en_GB, "[menu.settings.lang.en_GB_button]"},
                    {i18nHelper->getTranslation("[menu.settings.lang.fr_FR_button]"), Zappy::GUI::I18n::SupportedLocale::fr_FR, "[menu.settings.lang.fr_FR_button]"}
                };
                _lang = i18nHelper->getCurrentLocale();

                float y = _render->getHeight() / 3;

                for (std::size_t i = 0; i < buttons.size(); i++) {
                    std::unique_ptr<Zappy::GUI::Component::Button> button = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), std::get<0>(buttons[i]), 30, GREEN);
                    std::pair<float, float> pos = std::make_pair(_render->getWidth() / (buttons.size() + 1) * (i + 1), y);
                    button->setPosX(pos.first - button->getSizeX() / 2);
                    button->setPosY(pos.second - button->getSizeY() / 2);
                    _generalButtons.push_back(std::make_tuple(std::move(button), std::get<1>(buttons[i]), std::get<2>(buttons[i]), pos));
                }

                std::unique_ptr<Zappy::GUI::Component::Text> text = std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(0, y * 2 - y / 3), i18nHelper->getTranslation("[menu.settings.lang_title]"), 30, WHITE);
                text->setPosX(_render->getWidth() / 2 - text->getSizeX() / 2);
                _text = std::make_tuple(std::move(text), "[menu.settings.lang_title]", std::make_pair(_render->getWidth() / 2, y * 2 - y / 3));

                y = y * 2 + y / 3;
                for (std::size_t i = 0; i < buttonsLanguageValue.size(); i++) {
                    std::unique_ptr<Zappy::GUI::Component::Button> button = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), std::get<0>(buttonsLanguageValue[i]), 18, GREEN);
                    std::pair<float, float> pos = std::make_pair(_render->getWidth() / (buttonsLanguageValue.size() + 1) * (i + 1), y);
                    button->setPosX(pos.first - button->getSizeX() / 2);
                    button->setPosY(pos.second - button->getSizeY() / 2);
                    _languageButtons.push_back(std::make_tuple(std::move(button), std::get<1>(buttonsLanguageValue[i]), std::get<2>(buttonsLanguageValue[i]), pos));
                    if (std::get<1>(buttonsLanguageValue[i]) == i18nHelper->getCurrentLocale())
                        std::get<0>(_languageButtons.back())->setColor(BLUE);
                }
            }

            void Option::start()
            {
                EnableCursor();
                _render->view()->disableCamera();
            }

            void Option::destroy()
            {
                _background->destroy();
            }

            void Option::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    int i = 1;
                    int width = GetScreenWidth();
                    for (auto &button : _generalButtons) {
                        std::get<0>(button)->setText(i18nHelper->getTranslation(std::get<2>(button)));
                        std::get<0>(button)->setPosX((width / 3) * i - std::get<0>(button)->getSizeX() / 2);
                        i++;
                    }
                    std::get<0>(_text)->setText(i18nHelper->getTranslation(std::get<1>(_text)));
                    std::get<0>(_text)->setPosX(width / 2 - std::get<0>(_text)->getSizeX() / 2);
                    _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                    _lang = i18nHelper->getCurrentLocale();
                }

                for (auto &button : _languageButtons) {
                    if (std::get<0>(button)->isClicked()) {
                        i18nHelper->setCurrentLocale(std::get<1>(button));
                        for (auto &otherButton : _languageButtons)
                            std::get<0>(otherButton)->setColor(GREEN);
                        std::get<0>(button)->setColor(BLUE);
                    }
                }
            }

            void Option::draw2D()
            {
                _background->draw();
                _backButton.first->draw();
                for (auto &button : _generalButtons)
                    std::get<0>(button)->draw();
                std::get<0>(_text)->draw();
                for (auto &button : _languageButtons)
                    std::get<0>(button)->draw();
            }

            std::string Option::nextScene()
            {
                for (auto &button : _generalButtons) {
                    if (std::get<0>(button)->isClicked(std::get<0>(button)->getText()))
                        return std::get<1>(button);
                    if (_backButton.first->isClicked(_backButton.second))
                        return "menu";
                }
                return "option";
            }

            void Option::resize()
            {
                _background->resize();
                _backButton.first->resize();
                for (auto &button : _generalButtons)
                    std::get<0>(button)->resize();
                std::get<0>(_text)->resize();
                for (auto &button : _languageButtons)
                    std::get<0>(button)->resize();
            }
        }
    }
}