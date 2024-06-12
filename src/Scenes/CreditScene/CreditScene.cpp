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
            Credit::Credit(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_war_scenery.png");
                _backButton = std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), i18nHelper->getTranslation("[menu.back_button]"), 20, GREEN), "[menu.back_button]");
                int height = GetScreenHeight();
                std::vector<std::tuple<std::string, std::string, std::string>> buttons = {
                    {i18nHelper->getTranslation("[menu.settings.credits.1_button]"), "credit1", "[menu.settings.credits.1_button]"},
                    {i18nHelper->getTranslation("[menu.settings.credits.2_button]"), "credit2", "[menu.settings.credits.2_button]"},
                    {i18nHelper->getTranslation("[menu.settings.credits.3_button]"), "credit3", "[menu.settings.credits.3_button]"},
                };
                _lang = i18nHelper->getCurrentLocale();

                float x = GetScreenWidth() / 2;
                float y = 0;
                float yPart = height / (buttons.size() + 1);
                for (std::size_t i = 0; i < buttons.size(); i++) {
                    std::unique_ptr<Zappy::GUI::Component::Button> button = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(0, 0), std::make_pair(-20, -10), std::get<0>(buttons[i]), 30, GREEN);
                    std::pair<float, float> position = std::make_pair(x, y + yPart * (i + 1));
                    button->setPosX(position.first - button->getSizeX() / 2);
                    button->setPosY(position.second - button->getSizeY() / 2);
                    _generalButtons.push_back(std::make_tuple(std::move(button), std::get<1>(buttons[i]), std::get<2>(buttons[i])));
                    _buttonsPositions.push_back(position);
                }
            }

            void Credit::destroy()
            {
                _background->destroy();
            }

            void Credit::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    for (std::size_t i = 0; i < _generalButtons.size(); i++) {
                        std::get<0>(_generalButtons[i])->setText(i18nHelper->getTranslation(std::get<2>(_generalButtons[i])));
                        std::get<0>(_generalButtons[i])->setPosX(_buttonsPositions[i].first - std::get<0>(_generalButtons[i])->getSizeX() / 2);
                        std::get<0>(_generalButtons[i])->setPosY(_buttonsPositions[i].second - std::get<0>(_generalButtons[i])->getSizeY() / 2);
                    }
                    _backButton.first->setText(i18nHelper->getTranslation(_backButton.second));
                    _lang = i18nHelper->getCurrentLocale();
                }
            }

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