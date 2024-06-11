/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterInfo
*/

#include "ComponentInspecterInfo.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterInfo::InspecterInfo(std::pair<int, int> pos, std::pair<int, int> size)
            {
                _player = nullptr;
                _pos = pos;
                _size = size;
                _noPlayerSelected = std::make_unique<TextBox>(std::make_pair(_pos.first, _pos.second), _size.first, "No player selected", 20, WHITE);
                _circle = std::make_unique<Circle>(std::make_pair(_pos.first + 10, _pos.second + 10), 10, PURPLE);
                _name = std::make_unique<TextBox>(std::make_pair(_pos.first + 30, _pos.second), _size.first, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_pos.first, _name->getPosY() + _name->getSizeY() + 10), _size.first, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_pos.first, _food->getPosY() + _food->getSizeY() + 10), _size.first, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_pos.first, _linemate->getPosY() + _linemate->getSizeY() + 10), _size.first, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_pos.first, _deraumere->getPosY() + _deraumere->getSizeY() + 10), _size.first, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_pos.first, _sibur->getPosY() + _sibur->getSizeY() + 10), _size.first, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_pos.first, _mendiane->getPosY() + _mendiane->getSizeY() + 10), _size.first, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_pos.first, _phiras->getPosY() + _phiras->getSizeY() + 10), _size.first, "Thystame: ", 20, WHITE);
                _isDestroyed = false;
            }

            InspecterInfo::~InspecterInfo()
            {
                destroy();
            }

            void InspecterInfo::destroy()
            {
                if (_isDestroyed) return;
                _noPlayerSelected->destroy();
                _name->destroy();
                _food->destroy();
                _linemate->destroy();
                _deraumere->destroy();
                _sibur->destroy();
                _mendiane->destroy();
                _phiras->destroy();
                _thystame->destroy();
                _isDestroyed = true;
            }

            void InspecterInfo::draw()
            {
                if (_player == nullptr) {
                    _noPlayerSelected->draw();
                    return;
                }
                _circle->draw();
                _name->draw();
                _food->draw();
                _linemate->draw();
                _deraumere->draw();
                _sibur->draw();
                _mendiane->draw();
                _phiras->draw();
                _thystame->draw();
            }

            void InspecterInfo::modPosX(int x)
            {
                _pos.first += x;
                _noPlayerSelected->setPosX(_pos.first);

                _circle->setPosX((float)(_pos.first + 10));
                _circle->setPosY((float)(_pos.second + 10));

                _name->setPosX(_pos.first + 30);
                _food->setPosX(_pos.first);
                _linemate->setPosX(_pos.first);
                _deraumere->setPosX(_pos.first);
                _sibur->setPosX(_pos.first);
                _mendiane->setPosX(_pos.first);
                _phiras->setPosX(_pos.first);
                _thystame->setPosX(_pos.first);
            }

            void InspecterInfo::setInfo(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                _player = player;
                if (_player == nullptr) return;
                _circle->setColor(player->getTeam());
                _name->setText("Player #" + std::to_string(player->getId()));
                _food->setText("Food: " + std::to_string(player->getFood()));
                _linemate->setText("Linemate: " + std::to_string(player->getLinemate()));
                _deraumere->setText("Deraumere: " + std::to_string(player->getDeraumere()));
                _sibur->setText("Sibur: " + std::to_string(player->getSibur()));
                _mendiane->setText("Mendiane: " + std::to_string(player->getMendiane()));
                _phiras->setText("Phiras: " + std::to_string(player->getPhiras()));
                _thystame->setText("Thystame: " + std::to_string(player->getThystame()));
            }
        }
    }
}