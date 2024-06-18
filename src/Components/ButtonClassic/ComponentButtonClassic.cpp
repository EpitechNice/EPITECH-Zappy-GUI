/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButtonClassic
*/

#include "ComponentButtonClassic.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            ButtonClassic::ButtonClassic(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _color = color;
                _state = DEFAULT;
                _textStrokeVisible = false;
                _stateEnabled = true;


                _text = std::make_unique<Text>(std::make_pair(pos.first, pos.second), text, textSize, WHITE);
                std::pair<float, float> textSizes = {_text->getSizeX(), _text->getSizeY()};
                if (_sizeX < 0)
                    _sizeX = (_sizeX * -1) * 2 + textSizes.first;
                if (_sizeY < 0)
                    _sizeY = (_sizeY * -1) * 2 + textSizes.second;

                _text->setPosX(pos.first + (_sizeX - textSizes.first) / 2);
                _text->setPosY(pos.second + (_sizeY - textSizes.second) / 2);
                _state = DEFAULT;
                _button = std::make_unique<RoundedRectangle>(pos, size, 0.3, _color);
                _textStroke = std::make_unique<Text>(std::make_pair(_text->getPosX(), _text->getPosY() + 2), text, textSize, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));

                _lastClick = -1;

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
            }

            void ButtonClassic::draw()
            {
                State oldState = _state;
                _updateState();
                _modState(oldState);

                _button->draw();
                if (_textStrokeVisible)
                    _textStroke->draw();
                _text->draw();
            }

            void ButtonClassic::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;

                _button->resize();
                _text->resize();
                _textStroke->resize();
                std::pair<float, float> textSizes = {_text->getSizeX(), _text->getSizeY()};
                if (_sizeX < 0)
                    _sizeX = (_sizeX * -1) * 2 + textSizes.first;
                if (_sizeY < 0)
                    _sizeY = (_sizeY * -1) * 2 + textSizes.second;
            }


            void ButtonClassic::setPosX(float x)
            {
                float tmp = _posX;
                tmp -= x;
                _posX = x;
                _button->setPosX(x);
                _text->modPosX(-tmp);
                _textStroke->modPosX(-tmp);
                _refPosX = _posX / _refWidth * 100;
            }

            void ButtonClassic::modPosX(float x)
            {
                setPosX(_posX + x);
            }

            void ButtonClassic::setPosY(float y)
            {
                float tmp = _posY;
                tmp -= y;
                _posY = y;
                _button->setPosY(y);
                _text->modPosY(-tmp);
                _textStroke->modPosY(-tmp + 2);
                _refPosY = _posY / _refHeight * 100;
            }

            void ButtonClassic::modPosY(float y)
            {
                setPosY(_posY + y);
            }

            void ButtonClassic::setColor(Color color)
            {
                _color = color;
                _button->setColor(color);
                _textStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
            }


            bool ButtonClassic::isClicked() const
            {
                return _state == CLICKED;
            }

            void ButtonClassic::enableTextStroke()
            {
                _textStrokeVisible = true;
            }

            void ButtonClassic::disableTextStroke()
            {
                _textStrokeVisible = false;
            }

            void ButtonClassic::enableState()
            {
                _stateEnabled = true;
                _state = NONE;
            }

            void ButtonClassic::disableState()
            {
                _stateEnabled = false;
                _state = NONE;
            }


            void ButtonClassic::_updateState()
            {
                if (!_stateEnabled)
                    return;
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{_posX, _posY, _sizeX, _sizeY})) {
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && time(nullptr) > _lastClick + 0.5) {
                        _state = CLICKED;
                        _lastClick = time(nullptr);
                    } else
                        _state = HOVER;
                } else {
                    _state = DEFAULT;
                }
            }

            void ButtonClassic::_modState(State oldState)
            {
                if (_state == CLICKED && oldState != CLICKED) {
                    _button->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
                } else if (_state == HOVER && oldState != HOVER) {
                    _button->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 20));
                } else if (_state == DEFAULT && oldState != DEFAULT) {
                    _button->setColor(_color);
                }
            }
        }
    }
}