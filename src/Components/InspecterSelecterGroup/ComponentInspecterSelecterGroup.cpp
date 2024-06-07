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
                _pos = pos;
                _size = std::make_pair(width, 0);
            }

            InspecterSelecterGroup::~InspecterSelecterGroup()
            {
                destroy();
            }

            void InspecterSelecterGroup::destroy()
            {
                if (_isDestroyed) return;
                for (auto &player : _players)
                    player->destroy();
                _players.clear();
                _isDestroyed = true;
            }

            void InspecterSelecterGroup::update()
            {
                int bselected = _selected;
                for (std::size_t i = 0; i < _players.size(); i++) {
                    _players[i]->update();
                    if (_players[i]->isClicked())
                        bselected = i;
                }
                if (bselected != -1) {
                    if (_selected != -1)
                        _players[_selected]->setSelected(false);
                    _selected = bselected;
                    _players[_selected]->setSelected(true);
                }
            }

            void InspecterSelecterGroup::draw()
            {
                for (auto &player : _players)
                    player->draw();
            }

            void InspecterSelecterGroup::reset()
            {
                _players.clear();
                _size.second = 0;
                _selected = -1;
            }

            void InspecterSelecterGroup::addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                int gap = (_players.empty()) ? 0 : 20;
                std::shared_ptr<Zappy::GUI::Component::InspecterSelecter> newPlayer = std::make_shared<InspecterSelecter>(std::make_pair(_pos.first, _pos.second + _size.second + gap), _size.first, player);
                _players.push_back(newPlayer);
                _size.second += newPlayer->getSize().second + gap;
            }

            void InspecterSelecterGroup::modPosX(int x)
            {
                _pos.first += x;
                for (auto &player : _players)
                    player->modPosX(x);
            }

            void InspecterSelecterGroup::setPosX(int x)
            {
                int diff = x - _pos.first;
                modPosX(diff);
            }

            void InspecterSelecterGroup::setPosY(int y)
            {
                int diff = y - _pos.second;
                _pos.second = y;
                for (auto &player : _players)
                    player->modPosY(diff);
            }

            std::pair<int, int> InspecterSelecterGroup::getSize() const
            {
                return _size;
            }

            std::pair<int, int> InspecterSelecterGroup::getPos() const
            {
                return _pos;
            }
        }
    }
}
