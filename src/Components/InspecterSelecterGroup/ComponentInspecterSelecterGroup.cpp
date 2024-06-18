/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroup
*/

#include "ComponentInspecterSelecterGroup.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterSelecterGroup::InspecterSelecterGroup(std::pair<int, int> pos, int width)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = width;
                _sizeY = 0;

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
            }

            void InspecterSelecterGroup::draw()
            {
                for (auto &selecter : _selecters)
                    selecter->draw();
            }

            void InspecterSelecterGroup::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;

                int tmp = 0;
                for (auto &selecter : _selecters) {
                    selecter->resize();
                    selecter->setPosX(_posX);
                    selecter->setPosY(_posY + tmp);
                    tmp += selecter->getSizeY() + _gap;
                }
            }

            void InspecterSelecterGroup::modPosX(float x)
            {
                _posX += x;
                _refPosX = _posX / _refWidth * 100;
                for (auto &selecter : _selecters)
                    selecter->modPosX(x);
            }

            void InspecterSelecterGroup::setPosX(float x)
            {
                int diff = x - _posX;
                modPosX(diff);
            }

            void InspecterSelecterGroup::setPosY(float y)
            {
                int diff = y - _posY;
                _posY = y;
                _refPosY = _posY / _refHeight * 100;
                for (auto &selecter : _selecters)
                    selecter->modPosY(diff);
            }


            void InspecterSelecterGroup::update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info)
            {
                int bselected = _selected;
                for (std::size_t i = 0; i < _selecters.size(); i++) {
                    _selecters[i]->update();
                    if (_selecters[i]->isClicked())
                        bselected = i;
                }
                if (bselected != -1) {
                    if (_selected != -1)
                        _selecters[_selected]->setSelected(false);
                    _selected = bselected;
                    _selecters[_selected]->setSelected(true);
                    if (_selecters[_selected]->isPlayer())
                        info->setInfoPlayer(Zappy::GUI::Ressources::Ref::get()->ressources->getPlayerFromId(_selecters[_selected]->getPlayer()->getId()));
                    else
                        info->setInfoEgg(Zappy::GUI::Ressources::Ref::get()->ressources->getEggFromId(_selecters[_selected]->getEgg()->getId()));
                }
            }

            void InspecterSelecterGroup::reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info)
            {
                _selecters.clear();
                _sizeY = 0;
                _selected = -1;
                info->setInfoPlayer(nullptr);
            }

            void InspecterSelecterGroup::addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                _selecters.push_back(std::make_shared<InspecterSelecter>(std::make_pair(_posX, _posY + _sizeY), _sizeX, player));
                _sizeY += _selecters.back()->getSizeY() + _gap;
            }

            void InspecterSelecterGroup::addEgg(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg)
            {
                _selecters.push_back(std::make_shared<InspecterSelecter>(std::make_pair(_posX, _posY + _sizeY), _sizeX, egg));
                _sizeY += _selecters.back()->getSizeY() + _gap;
            }
        }
    }
}
