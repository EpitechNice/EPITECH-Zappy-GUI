/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroupDraggable
*/

#include "ComponentInspecterSelecterGroupDraggable.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterSelecterGroupDraggable::InspecterSelecterGroupDraggable(std::pair<int, int> pos, std::pair<int, int> size)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                _isDragged = false;

                _selecterGroup = std::make_unique<InspecterSelecterGroup>(pos, size.first);
            }

            void InspecterSelecterGroupDraggable::draw()
            {
                _selecterGroup->draw();
            }

            void InspecterSelecterGroupDraggable::setPosX(float x)
            {
                _posX = x;
                _selecterGroup->setPosX(x);
            }

            void InspecterSelecterGroupDraggable::modPosX(float x)
            {
                _posX += x;
                _selecterGroup->modPosX(x);
            }



            void InspecterSelecterGroupDraggable::update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info)
            {
                _selecterGroup->update(info);
                if (IsMouseButtonUp(MOUSE_LEFT_BUTTON)) {
                    if (_isDragged)
                        _endDrag();
                    return;
                }
                if (_isDragged && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                    _updateSelectersPos();
                    return;
                }
                if (CheckCollisionPointRec(GetMousePosition(), Rectangle{(float)_posX, (float)_posY, (float)_sizeX, (float)_sizeY})) {
                    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                        if (!_isDragged)
                            _setDragOffset();
                } else
                    _endDrag();
                _updateSelectersPos();
            }

            void InspecterSelecterGroupDraggable::reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info)
            {
                _selecterGroup->reset(info);
            }

            void InspecterSelecterGroupDraggable::addSelecter(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                _selecterGroup->addPlayer(player);
                _selecterGroup->setPosY(_posY);
            }

            void InspecterSelecterGroupDraggable::_updateSelectersPos()
            {
                if (_isDragged)
                    _selecterGroup->setPosY(GetMouseY() - _dragOffset.second);
            }

            void InspecterSelecterGroupDraggable::_setDragOffset()
            {
                _dragOffset = {GetMouseX() - _selecterGroup->getPosX(), GetMouseY() - _selecterGroup->getPosY()};
                _isDragged = true;
            }

            void InspecterSelecterGroupDraggable::_endDrag()
            {
                _isDragged = false;
                float groupPosY = _selecterGroup->getPosY();
                float groupSizeY = _selecterGroup->getSizeY();

                if (groupSizeY < _sizeY) {
                    _selecterGroup->setPosY(_posY);
                    return;
                }

                if (groupPosY > _posY) {
                    _selecterGroup->setPosY(_posY);
                    return;
                }

                if (groupPosY + groupSizeY < _posY + _sizeY) {
                    _selecterGroup->setPosY(_posY - groupSizeY + _sizeY);
                    return;
                }
            }
        }
    }
}