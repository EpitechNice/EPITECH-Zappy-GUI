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
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _gap = gap;
                _isDragged = false;

                _textGroup = std::make_unique<TextGroup>(pos, _sizeX, gap);

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
            }

            void TextGroupDraggable::draw()
            {
                _textGroup->draw();
            }

            void TextGroupDraggable::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;

                _textGroup->resize();
            }

            void TextGroupDraggable::setPosX(float x)
            {
                _posX = x;
                _textGroup->setPosX(x);
                _refPosX = _posX / _refWidth * 100;
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
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{(float)_posX, (float)_posY, (float)_sizeX, (float)_sizeY})) {
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
                _textGroup->setPosY(_posY - _textGroup->getSizeY() + _sizeY);
            }

            void TextGroupDraggable::_updateTextsPos()
            {
                if (_isDragged)
                    _textGroup->setPosY(GetMouseY() - _dragOffset.second);
            }

            void TextGroupDraggable::_setDragOffset()
            {
                _dragOffset = std::make_pair(GetMouseX() - _textGroup->getPosX(), GetMouseY() - _textGroup->getPosY());
                _isDragged = true;
            }

            void TextGroupDraggable::_endDrag()
            {
                _isDragged = false;
                float groupPosY = _textGroup->getPosY();
                float groupSizeY = _textGroup->getSizeY();

                if (groupSizeY < _sizeY) {
                    _textGroup->setPosY(_posY - groupSizeY + _sizeY);
                    return;
                }

                if (groupPosY > _posY) {
                    _textGroup->setPosY(_posY);
                    return;
                }
                if (groupPosY + groupSizeY < _posY + _sizeY) {
                    _textGroup->setPosY(_posY - groupSizeY + _sizeY);
                    return;
                }
            }
        }
    }
}