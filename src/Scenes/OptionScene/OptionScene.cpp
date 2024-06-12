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
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
                int x_generalButton = _render->getWidth() / 2;
                int y_generalButton = 0;
                int i_generalButton = 0;
                int height = _render->getHeight() / 1.5;

                std::vector<std::tuple<std::string, std::string, std::string>> buttons = {
                    {i18nHelper->getTranslation("[menu.settings.sound_button]"), "soundSetting", "[menu.settings.sound_button]"},
                    {i18nHelper->getTranslation("[menu.settings.resolution_button]"), "resolutionSetting", "[menu.settings.resolution_button]"},
                };
                std::vector<std::tuple<std::string, Zappy::GUI::I18n::SupportedLocale, std::string>> buttonsLanguageValue = {
                    {i18nHelper->getTranslation("[menu.settings.lang.en_GB_button]"), Zappy::GUI::I18n::SupportedLocale::en_GB, "[menu.settings.lang.en_GB_button]"},
                    {i18nHelper->getTranslation("[menu.settings.lang.fr_FR_button]"), Zappy::GUI::I18n::SupportedLocale::fr_FR, "[menu.settings.lang.fr_FR_button]"}
                };
                _lang = i18nHelper->getCurrentLocale();

                for (auto &button : buttons) {
                    auto button_width = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), std::get<0>(button), 30, GREEN)->getSize().first;
                    y_generalButton = (height / (buttons.size() + 1)) * (i_generalButton + 1) - 30;
                    x_generalButton -= button_width / 2;
                    _generalButtons.push_back(std::make_tuple(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_generalButton, y_generalButton), std::make_pair(-20, -10), std::get<0>(button), 30, GREEN), std::get<1>(button), std::get<2>(button)));
                    x_generalButton += button_width / 2;
                    i_generalButton++;
                }
                _text.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(x_generalButton * 0.9 , y_generalButton * 1.5), i18nHelper->getTranslation("[menu.settings.lang_title]"), 30, WHITE), "[menu.settings.lang_title]"));
                int x_langueButton = x_generalButton / 2;
                int y_langueButton = y_generalButton * 1.5 + 50;
                int i_langueButton = 20;

                for (auto &buttonLanguageValue : buttonsLanguageValue) {
                    y_langueButton = y_langueButton;
                    x_langueButton += i_langueButton;
                    if (!_languageButtons.empty())
                        x_langueButton += std::get<0>(_languageButtons.back())->getSize().first;
                    if (std::get<1>(buttonLanguageValue) == i18nHelper->getCurrentLocale())
                        _languageButtons.push_back(std::make_tuple(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_langueButton, y_langueButton), std::make_pair(-20, -10), i18nHelper->getTranslation(std::get<0>(buttonLanguageValue)), 18, BLUE), std::get<1>(buttonLanguageValue), std::get<2>(buttonLanguageValue)));
                    else {
                        _languageButtons.push_back(std::make_tuple(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x_langueButton, y_langueButton), std::make_pair(-20, -10), i18nHelper->getTranslation(std::get<0>(buttonLanguageValue)), 18, GREEN), std::get<1>(buttonLanguageValue), std::get<2>(buttonLanguageValue)));
                    }
                }
            }

            void Option::start()
            {
                EnableCursor();
                _render->view()->disableCamera();
            }

            void Option::destroy()
            {
                for (auto &text : _text)
                    text.first->destroy();
                for (auto &button : _generalButtons)
                    std::get<0>(button)->destroy();
                for (auto &button : _languageButtons)
                    std::get<0>(button)->destroy();
                _generalButtons.clear();
                _backButton.first->destroy();
                _background->destroy();
            }

            void Option::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    for (auto &button : _generalButtons)
                        std::get<0>(button)->setText(i18nHelper->getTranslation(std::get<2>(button)));
                    for (auto &languageButton : _languageButtons)
                        std::get<0>(languageButton)->setText(i18nHelper->getTranslation(std::get<2>(languageButton)));
                    for (auto &text : _text)
                        text.first->setText(i18nHelper->getTranslation(text.second));
                    _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                    _lang = i18nHelper->getCurrentLocale();
                }
            }

            void Option::draw3D()
            {}

            void Option::draw2D()
            {
                _background->draw();
                _backButton.first->draw();
                for (auto &button : _generalButtons)
                    std::get<0>(button)->draw();
                for (auto &button : _languageButtons)
                    std::get<0>(button)->draw();
                for (auto &text : _text)
                    text.first->draw();
            }

            std::string Option::nextScene()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                for (auto &button : _generalButtons) {
                    if (std::get<0>(button)->isClicked(std::get<0>(button)->getText()))
                        return std::get<1>(button);
                    if (_backButton.first->isClicked(_backButton.second))
                        return "menu";
                }
                for (auto &button : _languageButtons) {
                    if (std::get<0>(button)->isClicked(std::get<0>(button)->getText())) {
                        i18nHelper->setCurrentLocale(std::get<1>(button));
                        for (auto &otherButton : _languageButtons) {
                            if (std::get<0>(otherButton) != std::get<0>(button))
                                std::get<0>(otherButton)->changeColor(GREEN);
                        }
                        std::get<0>(button)->changeColor(BLUE);
                    }
                }
                return "option";
            }
        }
    }
}