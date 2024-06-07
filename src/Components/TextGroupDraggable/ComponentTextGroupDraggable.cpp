/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentTextGroupDraggable
*/

#include "ComponentTextGroupDraggable.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            TextGroupDraggable::TextGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size, int gap)
                : _pos(pos), _size(size), _gap(gap), _isDragged(false), _isDestroyed(false)
            {
                _textGroup = std::make_unique<TextGroup>(pos, _size.first, gap);
            }

            TextGroupDraggable::~TextGroupDraggable()
            {
                destroy();
            }

            void TextGroupDraggable::destroy()
            {
                if (_isDestroyed)
                    return;
                _textGroup->destroy();
                _isDestroyed = true;
            }

            void TextGroupDraggable::draw()
            {
                _textGroup->draw();
            }

            void TextGroupDraggable::update()
            {
                if (IsMouseButtonUp(MOUSE_LEFT_BUTTON)) {
                    if (_isDragged)
                        _endDrag();
                    return;
                }
                if (_isDragged && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    _updateTextsPos();
                    return;
                }
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{(float)_pos.first, (float)_pos.second, (float)_size.first, (float)_size.second})) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        if (!_isDragged)
                            _setDragOffset();
                } else
                    _endDrag();
                _updateTextsPos();
            }

            void TextGroupDraggable::addText(std::string name, std::string text, int gap, Color color)
            {
                _textGroup->addText(name, text, gap, color);
                std::pair<int, int> groupSize = _textGroup->getSize();
                _textGroup->setPosY(_pos.second - groupSize.second + _size.second);
            }

            void TextGroupDraggable::setPosX(int x)
            {
                _pos.first = x;
                _textGroup->setPosX(x);
            }

            void TextGroupDraggable::_updateTextsPos()
            {
                if (_isDragged)
                    _textGroup->setPosY(GetMouseY() - _dragOffset.second);
            }

            void TextGroupDraggable::_setDragOffset()
            {
                std::pair<int, int> groupPos = _textGroup->getPos();
                _dragOffset = std::make_pair(GetMouseX() - groupPos.first, GetMouseY() - groupPos.second);
                _isDragged = true;
            }

            void TextGroupDraggable::_endDrag()
            {
                _isDragged = false;
                std::pair<int, int> groupPos = _textGroup->getPos();
                std::pair<int, int> groupSize = _textGroup->getSize();

                if (groupSize.second < _size.second) {
                    _textGroup->setPosY(_pos.second - groupSize.second + _size.second);
                    return;
                }

                if (groupPos.second > _pos.second) {
                    _textGroup->setPosY(_pos.second);
                    return;
                }
                if (groupPos.second + groupSize.second < _pos.second + _size.second) {
                    _textGroup->setPosY(_pos.second - groupSize.second + _size.second);
                    return;
                }
            }
        }
    }
}