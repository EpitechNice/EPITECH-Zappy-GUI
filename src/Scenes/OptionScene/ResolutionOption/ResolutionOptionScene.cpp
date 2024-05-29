/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ResolutionOption
*/

#include "ResolutionOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            ResolutionOption::ResolutionOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render)
            {
                _render = render;
                _resolution = Resolution_1920x1080;
                _fps = FPS_60;
                _background = std::make_unique<Zappy::GUI::Component::Background2D>("assets/img/map_forest_scenery.png");
                _backButton = std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(20, 20), std::make_pair(-20, -10), "<- BACK", 20, GREEN);
                std::vector<std::pair<std::string, std::string>> buttons_resolution = {
                    {"2960x1440", "Resolution_2960x1440"},
                    {"1920x1080", "Resolution_1920x1080"},
                    {"1334x750", "Resolution_1334x750"},
                };
                std::vector<std::pair<std::string, std::string>> buttons_fps = {
                    {"30fps", "FPS_30"},
                    {"60fps", "FPS_60"},
                    {"120fps", "FPS_120"},
                };
                std::vector<std::string> text = {
                    "Resolution :",
                    "Fps :",
                };
                int buttonHeight = 30;
                int y = 0;
                int height = _render->getHeight();
                int buttonSpacing = 20;
                int buttonX = 0;
                int buttonY = 0;
                for (size_t i = 0; i < text.size(); ++i) {
                    y = (height / (text.size() + 1)) * (i + 1) - 30;
                    _text.push_back(std::make_unique<Zappy::GUI::Component::Text>(std::make_pair(_render->getWidth() / 5, y), text[i], 30, WHITE));
                    buttonX = _render->getWidth() / 2.5;
                    buttonY = y - buttonHeight / 2;
                    if (text[i] == "Resolution :") {
                        for (const auto& button : buttons_resolution) {
                            if (button.second == "Resolution_1920x1080")
                                _resolutionButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, BLUE), button.second));
                            else
                                _resolutionButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                            buttonX += _resolutionButtons.back().first->getSize().first + buttonSpacing;
                        }
                    } else if (text[i] == "Fps :") {
                        for (const auto& button : buttons_fps) {
                            if (button.second == "FPS_60")
                                _fpsButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, BLUE), button.second));
                            else
                                _fpsButtons.push_back(std::make_pair(std::make_unique<Zappy::GUI::Component::Button>(std::make_pair(buttonX, buttonY), std::make_pair(-20, -10), button.first, buttonHeight, GREEN), button.second));
                            buttonX += _fpsButtons.back().first->getSize().first + buttonSpacing;
                        }
                    }
                }
            }

            void ResolutionOption::destroy()
            {
                for (auto &text : _text)
                    text->destroy();
                for (auto &button : _resolutionButtons)
                    button.first->destroy();
                _resolutionButtons.clear();
                for (auto &button : _fpsButtons)
                    button.first->destroy();
                _fpsButtons.clear();
                _backButton->destroy();
                _background->destroy();
            }


            void ResolutionOption::start()
            {
            }

            void ResolutionOption::event()
            {
            }

            void ResolutionOption::draw3D()
            {
            }

            void ResolutionOption::draw2D()
            {
                _background->draw();
                _backButton->draw();
                for (auto &text : _text)
                    text->draw();
                for (auto &button : _resolutionButtons)
                    button.first->draw();
                for (auto &button : _fpsButtons)
                    button.first->draw();
            }


            std::string ResolutionOption::nextScene()
            {
                if (_backButton->isClicked())
                    return "option";
                for (auto &button : _resolutionButtons) {
                    if (button.first->isClicked()){
                        if (button.second == "Resolution_2960x1440")
                            _resolution = Resolution_2960x1440;
                        else if (button.second == "Resolution_1920x1080")
                            _resolution = Resolution_1920x1080;
                        else if (button.second == "Resolution_1334x750")
                            _resolution = Resolution_1334x750;
                        for (auto &otherButton : _resolutionButtons) {
                            if (otherButton.first != button.first)
                                otherButton.first->changeColor(GREEN);
                        }
                        button.first->changeColor(BLUE);
                    }
                }
                for (auto &button : _fpsButtons) {
                    if (button.first->isClicked()){
                        if (button.second == "FPS_30"){
                            _render->setFps(30);
                        } else if (button.second == "FPS_60")
                            _render->setFps(60);
                        else if (button.second == "FPS_120")
                            _render->setFps(120);
                        for (auto &otherButton : _fpsButtons) {
                            if (otherButton.first != button.first)
                                otherButton.first->changeColor(GREEN);
                        }
                        button.first->changeColor(BLUE);
                    }
                }
                return "resolutionSetting";
            }
        }
    }
}