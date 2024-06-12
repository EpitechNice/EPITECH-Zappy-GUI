/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Menu
*/

#include "MenuScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            Menu::Menu(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_classic_scenery.png");
                _logo = std::make_unique<Zappy::GUI::Component::Image>("assets/img/clash_of_tek.png", std::make_pair(100, 100), 0.6);
                _logo->setPosX((GetScreenWidth() / 8) * 6 - _logo->getSizeX() / 2 - 10);
                _logo->setPosY(GetScreenHeight() / 2 - _logo->getSizeY() / 2 - 30);
                std::vector<std::tuple<std::string, std::string, std::string>> buttons = {
                    {i18nHelper->getTranslation("[menu.start_title]"), "game", "[menu.start_title]"},
                    {i18nHelper->getTranslation("[menu.settings_title]"), "option", "[menu.settings_title]"},
                    {i18nHelper->getTranslation("[menu.help_title]"), "help", "[menu.help_title]"},
                    {i18nHelper->getTranslation("[menu.credits_title]"), "credits", "[menu.credits_title]"},
                    {i18nHelper->getTranslation("[menu.quit_title]"), "end", "[menu.quit_title]"}
                };
                _lang = i18nHelper->getCurrentLocale();
                int x = 20;
                int y = 0;
                int i = 0;
                int height = GetScreenHeight();
                for (auto &button : buttons) {
                    y = (height / (buttons.size() + 1)) * (i + 1) - 30;
                    _buttons.push_back(std::make_tuple(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x, y), std::make_pair(-20, -10), std::get<0>(button), 30, GREEN), std::get<1>(button), std::get<2>(button)));
                    i++;
                }
            }

            void Menu::start()
            {
                EnableCursor();
                _render->view()->disableCamera();
            }

            void Menu::destroy()
            {
                _logo->destroy();
                _background->destroy();
            }

            void Menu::update()
            {
                Zappy::GUI::I18n::I18nHelper* i18nHelper = Zappy::GUI::I18n::I18nHelper::getInstance();

                if (i18nHelper->getCurrentLocale() != _lang) {
                    for (auto &button : _buttons)
                        std::get<0>(button)->setText(i18nHelper->getTranslation(std::get<2>(button)));
                    _lang = i18nHelper->getCurrentLocale();
                }
            }

            void Menu::draw3D()
            {
            }

            void Menu::draw2D()
            {
                _background->draw();
                _logo->draw();
                for (auto &button : _buttons)
                    std::get<0>(button)->draw();
            }

            std::string Menu::nextScene()
            {
                for (auto &button : _buttons) {
                    if (std::get<0>(button)->isClicked(std::get<0>(button)->getText()))
                        return std::get<1>(button);
                }
                return "menu";
            }
        }
    }
}