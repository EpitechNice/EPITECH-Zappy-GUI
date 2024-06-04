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
                _render = render;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_classic_scenery.png");
                _logo = std::make_unique<Zappy::GUI::Component::Image>("assets/img/clash_of_tek.png", std::make_pair(100, 100), 0.6);
                std::pair<int, int> logoSize = _logo->getSize();
                _logo->setPos(std::make_pair((GetScreenWidth() / 8) * 6 - logoSize.first / 2 - 10, GetScreenHeight() / 2 - logoSize.second / 2 - 30));
                std::vector<std::pair<std::string, std::string>> buttons = {
                    {"PLAY", "game"},
                    {"SETTINGS", "option"},
                    {"HELP", "help"},
                    {"CREDITS", "credits"},
                    {"QUIT", "end"}
                };
                int x = 20;
                int y = 0;
                int i = 0;
                int height = GetScreenHeight();
                for (auto &button : buttons) {
                    y = (height / (buttons.size() + 1)) * (i + 1) - 30;
                    _buttons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(x, y), std::make_pair(-20, -10), button.first, 30, GREEN), button.second));
                    i++;
                }
            }

            void Menu::start()
            {
                EnableCursor();
            }

            void Menu::destroy()
            {
                for (auto &button : _buttons)
                    button.first->destroy();
                _buttons.clear();
                _logo->destroy();
                _background->destroy();
            }

            void Menu::update()
            {
            }

            void Menu::event()
            {
            }

            void Menu::draw3D()
            {
            }

            void Menu::draw2D()
            {
                _background->draw();
                _logo->draw();
                for (auto &button : _buttons)
                    button.first->draw();
            }

            std::string Menu::nextScene()
            {
                for (auto &button : _buttons) {
                    if (button.first->isClicked(button.first->getText()))
                        return button.second;
                }
                return "menu";
            }
        }
    }
}