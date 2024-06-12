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
//TODO (Refacto i18n) : Create translation value for"Credit1", "Credit2", "Credit3"
            Credit::Credit(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
                int x_generalButton = GetScreenWidth() / 2;
                int y_generalButton = 0;
                int i_generalButton = 0;
                int height = GetScreenHeight();
                std::vector<std::tuple<std::string, std::string, std::string>> buttons = {
                    {i18nHelper->getTranslation("[menu.settings.credits.1_button]"), "credit1", "[menu.settings.credits.1_button]"},
                    {i18nHelper->getTranslation("[menu.settings.credits.2_button]"), "credit2", "[menu.settings.credits.2_button]"},
                    {i18nHelper->getTranslation("[menu.settings.credits.3_button]"), "credit3", "[menu.settings.credits.3_button]"},
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
            }

            void Credit::start()
            {}

            void Credit::destroy()
            {
                for (auto &button : _generalButtons)
                    std::get<0>(button)->destroy();
                _generalButtons.clear();
                std::get<0>(_backButton)->destroy();
                _background->destroy();
            }

            void Credit::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    for (auto &button : _generalButtons)
                        std::get<0>(button)->setText(i18nHelper->getTranslation(std::get<2>(button)));
                    _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                    _lang = i18nHelper->getCurrentLocale();
                }
            }

            void Credit::draw3D()
            {}

            void Credit::draw2D()
            {
                _background->draw();
                _backButton.first->draw();
                for (auto &button : _generalButtons)
                    std::get<0>(button)->draw();
            }

            std::string Credit::nextScene()
            {
                for (auto &button : _generalButtons) {
                    if (std::get<0>(button)->isClicked(std::get<2>(button)))
                        return std::get<1>(button);
                    if (_backButton.first->isClicked(_backButton.second))
                        return "menu";
                }
                return "credits";
            }
        }
    }
}