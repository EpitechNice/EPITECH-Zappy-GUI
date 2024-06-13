/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButton
*/

#include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Button::Button(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color)
            {
                _posX = pos.first;
                _posY = pos.second;
                _initialSizeX = size.first;
                _initialSizeY = size.second;
                _color = color;

                std::pair<float, float> buttonSize = size;
                _text = std::make_unique<Text>(std::make_pair(pos.first, pos.second), text, textSize, WHITE);
                std::pair<float, float> textSizes = {_text->getSizeX(), _text->getSizeY()};
                if (buttonSize.first < 0)
                    buttonSize.first = (buttonSize.first * -1) * 2 + textSizes.first;
                if (buttonSize.second < 0)
                    buttonSize.second = (buttonSize.second * -1) * 2 + textSizes.second;
                std::pair<float, float> topButtonSize = std::make_pair(buttonSize.first - 6, buttonSize.second - 7 - 6);
                std::pair<float, float> topButtonPos = std::make_pair(pos.first + 3, pos.second + 3);
                std::pair<float, float> textPosition = std::make_pair(topButtonPos.first + (topButtonSize.first - textSizes.first) / 2, topButtonPos.second + (topButtonSize.second - textSizes.second) / 2);

                _state = NONE;
                _blackStroke = std::make_unique<RoundedRectangle>(std::make_pair(pos.first - 1, pos.second - 1), std::make_pair(buttonSize.first + 2, buttonSize.second + 2), 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
                _upEffect = std::make_unique<RoundedRectangle>(pos, buttonSize, 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 20));
                _background = std::make_unique<RoundedRectangle>(pos, std::make_pair(buttonSize.first, buttonSize.second - 7), 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 10));
                _topButton = std::make_unique<RoundedRectangle>(topButtonPos, topButtonSize, 0.3, _color);
                _reflexioneffect = std::make_unique<RoundedRectangle>(std::make_pair(pos.first + 4, pos.second + 4), std::make_pair(buttonSize.first - 8, (buttonSize.second - 7 - 8) / 2), 0.3, Zappy::GUI::Raylib::ColorManager::Lighter(_color, 5));
                _circle = std::make_unique<Circle>(std::make_pair(pos.first + buttonSize.first - 8, pos.second + 8), 4, Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
                _textStroke = std::make_unique<Text>(std::make_pair(textPosition.first, textPosition.second + 2), text, textSize, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
                _sizeX = buttonSize.first;
                _sizeY = buttonSize.second;
                _textPos = textPosition;

                _bubble = true;
                _lastClick = -1;
                _modState(DEFAULT);
            }

            void Button::draw()
            {
                if (_state != DISABLED) {
                    State oldState = _state;
                    _updateState();
                    _modState(oldState);
                }

                _blackStroke->draw();
                _upEffect->draw();
                _background->draw();
                _topButton->draw();
                _reflexioneffect->draw();
                if (_bubble)
                    _circle->draw();
                _textStroke->draw();
                _text->draw();
            }

            void Button::setSizeX(float x)
            {
                _changeSize(x, _initialSizeY);
            }

            void Button::setSizeY(float y)
            {
                _changeSize(_initialSizeX, y);
            }

            void Button::setPosX(float x)
            {
                modPosX(x - _posX);
            }

            void Button::setPosY(float y)
            {
                modPosY(y - _posY);
            }

            void Button::setColor(Color color)
            {
                _color = color;
                _blackStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 50));
                _upEffect->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 20));
                _background->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 10));
                _topButton->setColor(_color);
                _reflexioneffect->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 5));
                _circle->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
            }

            void Button::modPosX(float x)
            {
                _posX += x;
                _blackStroke->modPosX(x);
                _upEffect->modPosX(x);
                _background->modPosX(x);
                _topButton->modPosX(x);
                _reflexioneffect->modPosX(x);
                _circle->modPosX(x);
                _textPos.first += x;
                _text->setPosX(_textPos.first);
                _textStroke->setPosX(_textPos.first);
                _modState(NONE);
            }

            void Button::modPosY(float y)
            {
                _posY += y;
                _blackStroke->modPosY(y);
                _upEffect->modPosY(y);
                _background->modPosY(y);
                _topButton->modPosY(y);
                _reflexioneffect->modPosY(y);
                _circle->modPosY(y);
                _textPos.second += y;
                _text->setPosY(_textPos.second);
                _textStroke->setPosY(_textPos.second + 2);
                _modState(NONE);
            }


            void Button::enableBubble()
            {
                _bubble = true;
            }

            void Button::disableBubble()
            {
                _bubble = false;
            }

            bool Button::isHover() const
            {
                return _state == HOVER;
            }

            bool Button::isClickedWihoutSong() const
            {
                return isClicked();
            }

            bool Button::isClicked() const
            {
                return _state == CLICKED;
            }

            bool Button::isClicked(std::string textButton)
            {
                if (_state == CLICKED && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
                    if (textButton == "[menu.back_button]"){
                        Sfml::SoundManager::getInstance().setEffetSonore("assets/Musique/effetSonoreButtonBack.wav");
                        Sfml::SoundManager::getInstance().playButtonClickSound();
                    } else if (textButton == "[menu.start_title]"){
                        Sfml::SoundManager::getInstance().setMusique("assets/Musique/ClashofTekCombatMusic.wav");
                        Sfml::SoundManager::getInstance().playgeneralSound();
                    } else {
                        Sfml::SoundManager::getInstance().setEffetSonore("assets/Musique/effetSonoreButton1.wav");
                        Sfml::SoundManager::getInstance().playButtonClickSound();
                    }
                    return true;
                }
                return false;
            }

            void Button::setText(std::string text)
            {
                _text->setText(text);
                _textStroke->setText(text);
                _changeSize(_initialSizeX, _initialSizeY);
            }

            std::string Button::getText() const
            {
                return _text->getText();
            }

            void Button::setState(State state)
            {
                State tmp = _state;
                _state = state;
                _modState(tmp);
            }


            void Button::_updateState()
            {
                if (_state == DISABLED)
                    return;
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{_posX, _posY, _sizeX, _sizeY})) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        _state = CLICKED;
                    else
                        _state = HOVER;
                } else
                    _state = DEFAULT;
            }

            void Button::_modState(State oldState)
            {
                if (oldState == _state)
                    return;

                if (_state == DISABLED) {
                    _blackStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(DARKGRAY, 50));
                    _upEffect->setColor(Zappy::GUI::Raylib::ColorManager::Darker(DARKGRAY, 20));
                    _background->setColor(Zappy::GUI::Raylib::ColorManager::Darker(DARKGRAY, 10));
                    _topButton->setColor(DARKGRAY);
                    _reflexioneffect->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(DARKGRAY, 5));
                    _circle->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(DARKGRAY, 50));
                    _textStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(DARKGRAY, 50));
                } else {
                    _blackStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 50));
                    _upEffect->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 20));
                    _background->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 10));
                    _topButton->setColor(_color);
                    _reflexioneffect->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 5));
                    _circle->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
                    _textStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 50));
                }
                if (_state == HOVER || _state == DISABLED) {
                    _blackStroke->setSizeX(_sizeX + 2);
                    _blackStroke->setSizeY(_sizeY + 2 - _hoverEffect);
                    _blackStroke->setPosX(_posX - 1);
                    _blackStroke->setPosY(_posY - 1 + _hoverEffect);

                    _upEffect->setSizeX(_sizeX);
                    _upEffect->setSizeY(_sizeY - _hoverEffect);
                    _upEffect->setPosX(_posX);
                    _upEffect->setPosY(_posY + _hoverEffect);

                    _background->setPosX(_posX);
                    _background->setPosY(_posY + _hoverEffect);

                    _topButton->setPosX(_posX + 3);
                    _topButton->setPosY(_posY + 3 + _hoverEffect);

                    _reflexioneffect->setPosX(_posX + 4);
                    _reflexioneffect->setPosY(_posY + 4 + _hoverEffect);

                    _circle->setPosX((float)(_posX + _sizeX - 8));
                    _circle->setPosY((float)(_posY + 8 + _hoverEffect));

                    _text->setPosX(_textPos.first);
                    _text->setPosY(_textPos.second + _hoverEffect);

                    _textStroke->setPosX(_textPos.first);
                    _textStroke->setPosY(_textPos.second + 2 + _hoverEffect);
                } else if (_state == CLICKED) {
                    _blackStroke->setSizeX(_sizeX + 2);
                    _blackStroke->setSizeY(_sizeY + 2 - _pressEffect);
                    _blackStroke->setPosX(_posX - 1);
                    _blackStroke->setPosY(_posY - 1 + _pressEffect);

                    _upEffect->setSizeX(_sizeX);
                    _upEffect->setSizeY(_sizeY - _pressEffect);
                    _upEffect->setPosX(_posX);
                    _upEffect->setPosY(_posY + _pressEffect);

                    _background->setPosX(_posX);
                    _background->setPosY(_posY + _pressEffect);

                    _topButton->setPosX(_posX + 3);
                    _topButton->setPosY(_posY + 3 + _pressEffect);

                    _reflexioneffect->setPosX(_posX + 4);
                    _reflexioneffect->setPosY(_posY + 4 + _pressEffect);

                    _circle->setPosX((float)(_posX + _sizeX - 8));
                    _circle->setPosY((float)(_posY + 8 + _pressEffect));

                    _text->setPosX(_textPos.first);
                    _text->setPosY(_textPos.second + _pressEffect);

                    _textStroke->setPosX(_textPos.first);
                    _textStroke->setPosY(_textPos.second + 2 + _pressEffect);
                } else {
                    _blackStroke->setSizeX(_sizeX + 2);
                    _blackStroke->setSizeY(_sizeY + 2);
                    _blackStroke->setPosX(_posX - 1);
                    _blackStroke->setPosY(_posY - 1);

                    _upEffect->setSizeX(_sizeX);
                    _upEffect->setSizeY(_sizeY);
                    _upEffect->setPosX(_posX);
                    _upEffect->setPosY(_posY);

                    _background->setPosX(_posX);
                    _background->setPosY(_posY);

                    _topButton->setPosX(_posX + 3);
                    _topButton->setPosY(_posY + 3);

                    _reflexioneffect->setPosX(_posX + 4);
                    _reflexioneffect->setPosY(_posY + 4);

                    _circle->setPosX((float)(_posX + _sizeX - 8));
                    _circle->setPosY((float)(_posY + 8));

                    _text->setPosX(_textPos.first);
                    _text->setPosY(_textPos.second);

                    _textStroke->setPosX(_textPos.first);
                    _textStroke->setPosY(_textPos.second + 2);
                }
            }

            void Button::_changeSize(float sizeX, float sizeY)
            {
                std::pair<float, float> buttonSize = std::make_pair(sizeX, sizeY);
                std::pair<float, float> textSizes = {_text->getSizeX(), _text->getSizeY()};
                if (buttonSize.first < 0)
                    buttonSize.first = (buttonSize.first * -1) * 2 + textSizes.first;
                if (buttonSize.second < 0)
                    buttonSize.second = (buttonSize.second * -1) * 2 + textSizes.second;
                std::pair<float, float> topButtonSize = std::make_pair(buttonSize.first - 6, buttonSize.second - 7 - 6);
                std::pair<float, float> topButtonPos = std::make_pair(_posX + 3, _posY + 3);
                std::pair<float, float> textPosition = std::make_pair(topButtonPos.first + (topButtonSize.first - textSizes.first) / 2, topButtonPos.second + (topButtonSize.second - textSizes.second) / 2);

                _blackStroke->setSizeX(buttonSize.first + 2);
                _blackStroke->setSizeY(buttonSize.second + 2);
                _blackStroke->setPosX(_posX - 1);
                _blackStroke->setPosY(_posY - 1);

                _upEffect->setSizeX(buttonSize.first);
                _upEffect->setSizeY(buttonSize.second);
                _upEffect->setPosX(_posX);
                _upEffect->setPosY(_posY);

                _background->setSizeX(buttonSize.first);
                _background->setSizeY(buttonSize.second - 7);
                _background->setPosX(_posX);
                _background->setPosY(_posY);

                _topButton->setSizeX(topButtonSize.first);
                _topButton->setSizeY(topButtonSize.second);
                _topButton->setPosX(topButtonPos.first);
                _topButton->setPosY(topButtonPos.second);

                _reflexioneffect->setSizeX(buttonSize.first - 8);
                _reflexioneffect->setSizeY((buttonSize.second - 7 - 8) / 2);
                _reflexioneffect->setPosX(_posX + 4);
                _reflexioneffect->setPosY(_posY + 4);

                _circle->setPosX((float)(_posX + buttonSize.first - 8));
                _circle->setPosY((float)(_posY + 8));

                _text->setPosX(textPosition.first);
                _text->setPosY(textPosition.second);

                _textStroke->setPosX(textPosition.first);
                _textStroke->setPosY(textPosition.second + 2);

                _sizeX = buttonSize.first;
                _sizeY = buttonSize.second;
                _initialSizeX = sizeX;
                _initialSizeY = sizeY;
                _textPos = textPosition;
            }
        }
    }
}
