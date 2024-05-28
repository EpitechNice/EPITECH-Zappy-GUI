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
                : _pos(pos), _size(size), _color(color), _isDestroyed(false)
            {
                std::pair<float, float> buttonSize = size;
                _text = std::make_unique<Text>(std::make_pair(pos.first, pos.second), text, textSize, WHITE);
                std::pair<float, float> textSizes = _text->getSize();
                if (buttonSize.first < 0)
                    buttonSize.first = (buttonSize.first * -1) * 2 + textSizes.first;
                if (buttonSize.second < 0)
                    buttonSize.second = (buttonSize.second * -1) * 2 + textSizes.second;
                std::pair<float, float> topButtonSize = std::make_pair(buttonSize.first - 6, buttonSize.second - 7 - 6);
                std::pair<float, float> topButtonPos = std::make_pair(pos.first + 3, pos.second + 3);
                std::pair<float, float> textPosition = std::make_pair(topButtonPos.first + (topButtonSize.first - textSizes.first) / 2, topButtonPos.second + (topButtonSize.second - textSizes.second) / 2);

                _text->setPos(textPosition);
                _state = DEFAULT;
                _blackStroke = std::make_unique<RoundedRectangle>(std::make_pair(pos.first - 1, pos.second - 1), std::make_pair(buttonSize.first + 2, buttonSize.second + 2), 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
                _upEffect = std::make_unique<RoundedRectangle>(pos, buttonSize, 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 20));
                _background = std::make_unique<RoundedRectangle>(pos, std::make_pair(buttonSize.first, buttonSize.second - 7), 0.3, Zappy::GUI::Raylib::ColorManager::Darker(color, 10));
                _topButton = std::make_unique<RoundedRectangle>(topButtonPos, topButtonSize, 0.3, _color);
                _reflexioneffect = std::make_unique<RoundedRectangle>(std::make_pair(pos.first + 4, pos.second + 4), std::make_pair(buttonSize.first - 8, (buttonSize.second - 7 - 8) / 2), 0.3, Zappy::GUI::Raylib::ColorManager::Lighter(_color, 5));
                _circle = std::make_unique<Circle>(std::make_pair(pos.first + buttonSize.first - 8, pos.second + 8), 4, Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
                _textStroke = std::make_unique<Text>(std::make_pair(textPosition.first, textPosition.second + 2), text, textSize, Zappy::GUI::Raylib::ColorManager::Darker(color, 50));
                _size = buttonSize;
                _textPos = textPosition;
            }

            Button::~Button()
            {
                destroy();
            }

            void Button::destroy()
            {
                if (!_isDestroyed) {
                    _text->destroy();
                    _textStroke->destroy();
                    _isDestroyed = true;
                }
            }


            void Button::draw()
            {
                State oldState = _state;
                _updateState();
                _modState(oldState);

                _blackStroke->draw();
                _upEffect->draw();
                _background->draw();
                _topButton->draw();
                _reflexioneffect->draw();
                _circle->draw();
                _textStroke->draw();
                _text->draw();
            }

            std::pair<float, float> Button::getSize() const
            {
                return _size;
            }

            bool Button::isClicked() const
            {
                return _state == CLICKED && IsMouseButtonReleased(MOUSE_LEFT_BUTTON);
            }

            void Button::_updateState()
            {
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{_pos.first, _pos.second, _size.first, _size.second})) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        _state = CLICKED;
                    else
                        _state = HOVER;
                } else
                    _state = DEFAULT;
            }

            void Button::changeColor(Color color)
            {
                _color = color;
                _blackStroke->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 50));
                _upEffect->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 20));
                _background->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 10));
                _topButton->setColor(_color);
                _reflexioneffect->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 5));
                _circle->setColor(Zappy::GUI::Raylib::ColorManager::Lighter(_color, 50));
            }

            void Button::_modState(State oldState)
            {
                if (oldState == _state)
                    return;
                if (_state == HOVER) {
                    _blackStroke->setSize(std::make_pair(_size.first + 2, _size.second + 2 - _hoverEffect));
                    _blackStroke->setPosition(std::make_pair(_pos.first - 1, _pos.second - 1 + _hoverEffect));
                    _upEffect->setSize(std::make_pair(_size.first, _size.second - _hoverEffect));
                    _upEffect->setPosition(std::make_pair(_pos.first, _pos.second + _hoverEffect));
                    _background->setPosition(std::make_pair(_pos.first, _pos.second + _hoverEffect));
                    _topButton->setPosition(std::make_pair(_pos.first + 3, _pos.second + 3 + _hoverEffect));
                    _reflexioneffect->setPosition(std::make_pair(_pos.first + 4, _pos.second + 4 + _hoverEffect));
                    _circle->setPos(std::make_pair(_pos.first + _size.first - 8, _pos.second + 8 + _hoverEffect));
                    _text->setPos(std::make_pair(_textPos.first, _textPos.second + _hoverEffect));
                    _textStroke->setPos(std::make_pair(_textPos.first, _textPos.second + 2 + _hoverEffect));
                } else if (_state == CLICKED) {
                    _blackStroke->setSize(std::make_pair(_size.first + 2, _size.second + 2 - _pressEffect));
                    _blackStroke->setPosition(std::make_pair(_pos.first - 1, _pos.second - 1 + _pressEffect));
                    _upEffect->setSize(std::make_pair(_size.first, _size.second - _pressEffect));
                    _upEffect->setPosition(std::make_pair(_pos.first, _pos.second + _pressEffect));
                    _background->setPosition(std::make_pair(_pos.first, _pos.second + _pressEffect));
                    _topButton->setPosition(std::make_pair(_pos.first + 3, _pos.second + 3 + _pressEffect));
                    _reflexioneffect->setPosition(std::make_pair(_pos.first + 4, _pos.second + 4 + _pressEffect));
                    _circle->setPos(std::make_pair(_pos.first + _size.first - 8, _pos.second + 8 + _pressEffect));
                    _text->setPos(std::make_pair(_textPos.first, _textPos.second + _pressEffect));
                    _textStroke->setPos(std::make_pair(_textPos.first, _textPos.second + 2 + _pressEffect));
                } else {
                    _blackStroke->setSize(std::make_pair(_size.first + 2, _size.second + 2));
                    _blackStroke->setPosition(std::make_pair(_pos.first - 1, _pos.second - 1));
                    _upEffect->setSize(_size);
                    _upEffect->setPosition(_pos);
                    _background->setPosition(_pos);
                    _topButton->setPosition(std::make_pair(_pos.first + 3, _pos.second + 3));
                    _reflexioneffect->setPosition(std::make_pair(_pos.first + 4, _pos.second + 4));
                    _circle->setPos(std::make_pair(_pos.first + _size.first - 8, _pos.second + 8));
                    _text->setPos(_textPos);
                    _textStroke->setPos(std::make_pair(_textPos.first, _textPos.second + 2));
                }
            }
        }
    }
}