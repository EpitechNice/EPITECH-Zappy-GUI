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
            }

            void InspecterSelecterGroup::draw()
            {
                for (auto &selecter : _selecters)
                    selecter->draw();
            }

            void InspecterSelecterGroup::modPosX(float x)
            {
                _posX += x;
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
                    info->setInfo(Zappy::GUI::Ressources::Ref::get()->ressources->getPlayerFromId(_selecters[_selected]->getPlayer()->getId()));
                }
            }

            void InspecterSelecterGroup::reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info)
            {
                _selecters.clear();
                _sizeY = 0;
                _selected = -1;
                info->setInfo(nullptr);
            }

            void InspecterSelecterGroup::addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                int gap = (_selecters.empty()) ? 0 : 20;
                std::shared_ptr<Zappy::GUI::Component::InspecterSelecter> newPlayer = std::make_shared<InspecterSelecter>(std::make_pair(_posX, _posY + _sizeY + gap), _sizeX, player);
                _selecters.push_back(newPlayer);
                _sizeY += newPlayer->getSizeY() + gap;
            }
        }
    }
}
