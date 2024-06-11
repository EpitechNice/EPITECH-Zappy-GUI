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
                : _pos(pos), _size(size), _color(color), _state(DEFAULT), _textStrokeVisible(false), _stateEnabled(true), _isDestroyed(false)
            {
                _text = std::make_unique<Text>(std::make_pair(pos.first, pos.second), text, textSize, WHITE);
                std::pair<float, float> textSizes = _text->getSize();
                if (_size.first < 0)
                    _size.first = (_size.first * -1) * 2 + textSizes.first;
                if (_size.second < 0)
                    _size.second = (_size.second * -1) * 2 + textSizes.second;
                _textPos = std::make_pair(pos.first + (_size.first - textSizes.first) / 2, pos.second + (_size.second - textSizes.second) / 2);

                _text->setPos(_textPos);
                _state = DEFAULT;
                _button = std::make_unique<RoundedRectangle>(pos, size, 0.3, _color);
                _textStroke = std::make_unique<Text>(std::make_pair(_textPos.first, _textPos.second + 2), text, textSize, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));

                _lastClick = -1;
            }

            ButtonClassic::~ButtonClassic()
            {
                destroy();
            }

            void ButtonClassic::destroy()
            {
                if (!_isDestroyed) {
                    _text->destroy();
                    _textStroke->destroy();
                    _isDestroyed = true;
                }
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

            std::pair<float, float> ButtonClassic::getSize() const
            {
                return _size;
            }

            bool ButtonClassic::isClicked() const
            {
                return _state == CLICKED;
            }

            void ButtonClassic::modPosX(float x)
            {
                setPosX(_pos.first + x);
            }

            void ButtonClassic::setPosX(float x)
            {
                setPos(std::make_pair(x, _pos.second));
            }

            void ButtonClassic::setPos(std::pair<float, float> pos)
            {
                std::pair<float, float> tmp = _pos;
                tmp.first -= pos.first;
                tmp.second -= pos.second;
                _pos = pos;
                _textPos.first -= tmp.first;
                _textPos.second -= tmp.second;

                _button->setPosX(pos.first);
                _button->setPosY(pos.second);

                _text->setPos(_textPos);
                _textStroke->setPos(std::make_pair(_textPos.first, _textPos.second + 2));
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

            void ButtonClassic::setColor(Color color)
            {
                _color = color;
                _button->setColor(color);
                _textStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
            }


            void ButtonClassic::_updateState()
            {
                if (!_stateEnabled)
                    return;
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{_pos.first, _pos.second, _size.first, _size.second})) {
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