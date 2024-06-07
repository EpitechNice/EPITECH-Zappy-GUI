/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroupDraggable
*/

#include "ComponentInspecterSelecterGroupDragabble.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterSelecterGroupDraggable::InspecterSelecterGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size)
                : _pos(pos), _size(size), _isDragged(false), _isDestroyed(false)
            {
                _selecterGroup = std::make_unique<InspecterSelecterGroup>(pos, size.first);
            }

            InspecterSelecterGroupDraggable::~InspecterSelecterGroupDraggable()
            {
                destroy();
            }

            void InspecterSelecterGroupDraggable::destroy()
            {
                if (_isDestroyed)
                    return;
                _selecterGroup->destroy();
                _isDestroyed = true;
            }

            void InspecterSelecterGroupDraggable::draw()
            {
                _selecterGroup->draw();
            }

            void InspecterSelecterGroupDraggable::update()
            {
                _selecterGroup->update();
                if (IsMouseButtonUp(MOUSE_LEFT_BUTTON)) {
                    if (_isDragged)
                        _endDrag();
                    return;
                }
                if (_isDragged && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    _updateSelectersPos();
                    return;
                }
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{(float)_pos.first, (float)_pos.second, (float)_size.first, (float)_size.second})) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        if (!_isDragged)
                            _setDragOffset();
                } else
                    _endDrag();
                _updateSelectersPos();
            }

            void InspecterSelecterGroupDraggable::reset()
            {
                _selecterGroup->reset();
            }

            void InspecterSelecterGroupDraggable::addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                _selecterGroup->addPlayer(player);
                _selecterGroup->setPosY(_pos.second);
            }

            void InspecterSelecterGroupDraggable::setPosX(int x)
            {
                _pos.first = x;
                _selecterGroup->setPosX(x);
            }

            void InspecterSelecterGroupDraggable::modPosX(int x)
            {
                _pos.first += x;
                _selecterGroup->modPosX(x);
            }

            void InspecterSelecterGroupDraggable::_updateSelectersPos()
            {
                if (_isDragged)
                    _selecterGroup->setPosY(GetMouseY() - _dragOffset.second);
            }

            void InspecterSelecterGroupDraggable::_setDragOffset()
            {
                std::pair<int, int> groupPos = _selecterGroup->getPos();
                _dragOffset = {GetMouseX() - groupPos.first, GetMouseY() - groupPos.second};
                _isDragged = true;
            }

            void InspecterSelecterGroupDraggable::_endDrag()
            {
                _isDragged = false;
                std::pair<int, int> groupPos = _selecterGroup->getPos();
                std::pair<int, int> groupSize = _selecterGroup->getSize();

                if (groupSize.second < _size.second) {
                    _selecterGroup->setPosY(_pos.second);
                    return;
                }

                if (groupPos.second > _pos.second) {
                    _selecterGroup->setPosY(_pos.second);
                    return;
                }

                if (groupPos.second + groupSize.second < _pos.second + _size.second) {
                    _selecterGroup->setPosY(_pos.second - groupSize.second + _size.second);
                    return;
                }
            }
        }
    }
}