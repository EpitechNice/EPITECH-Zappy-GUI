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
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;

                _player = nullptr;
                _egg = nullptr;
                _noPlayerSelected = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "No player or egg selected", 20, WHITE);
                _circle = std::make_unique<Circle>(std::make_pair(_posX + 10, _posY + 10), 10, PURPLE);
                _team = std::make_unique<TextBox>(std::make_pair(_posX + 30, _posY), _sizeX, "Team: ", 20, WHITE);
                _name = std::make_unique<TextBox>(std::make_pair(_posX + 30, _team->getPosY() + _team->getSizeY() + 10), _sizeX, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_posX, _name->getPosY() + _name->getSizeY() + 10), _sizeX, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_posX, _food->getPosY() + _food->getSizeY() + 10), _sizeX, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_posX, _linemate->getPosY() + _linemate->getSizeY() + 10), _sizeX, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_posX, _deraumere->getPosY() + _deraumere->getSizeY() + 10), _sizeX, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_posX, _sibur->getPosY() + _sibur->getSizeY() + 10), _sizeX, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_posX, _mendiane->getPosY() + _mendiane->getSizeY() + 10), _sizeX, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_posX, _phiras->getPosY() + _phiras->getSizeY() + 10), _sizeX, "Thystame: ", 20, WHITE);
            }

            void InspecterInfo::draw()
            {
                if (_player == nullptr && _egg == nullptr) {
                    _noPlayerSelected->draw();
                    return;
                }
                _circle->draw();
                _team->draw();
                _name->draw();
                if (_player == nullptr) return;
                _food->draw();
                _linemate->draw();
                _deraumere->draw();
                _sibur->draw();
                _mendiane->draw();
                _phiras->draw();
                _thystame->draw();
            }

            void InspecterInfo::modPosX(float x)
            {
                _posX += x;
                _noPlayerSelected->setPosX(_posX);
                _circle->setPosX((float)(_posX + 10));
                _team->setPosX(_posX + 30);
                _name->setPosX(_posX + 30);
                _food->setPosX(_posX);
                _linemate->setPosX(_posX);
                _deraumere->setPosX(_posX);
                _sibur->setPosX(_posX);
                _mendiane->setPosX(_posX);
                _phiras->setPosX(_posX);
                _thystame->setPosX(_posX);
            }

            void InspecterInfo::setInfoPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player)
            {
                _player = player;
                if (_player == nullptr) return;
                _circle->setColor(Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[player->getTeam()]);
                _team->setText("Team: " + player->getTeam());
                _name->setText("Player #" + std::to_string(player->getId()));
                _food->setText("Food: " + std::to_string(player->getFood()));
                _linemate->setText("Linemate: " + std::to_string(player->getLinemate()));
                _deraumere->setText("Deraumere: " + std::to_string(player->getDeraumere()));
                _sibur->setText("Sibur: " + std::to_string(player->getSibur()));
                _mendiane->setText("Mendiane: " + std::to_string(player->getMendiane()));
                _phiras->setText("Phiras: " + std::to_string(player->getPhiras()));
                _thystame->setText("Thystame: " + std::to_string(player->getThystame()));
            }

            void InspecterInfo::setInfoEgg(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg)
            {
                _player = nullptr;
                _egg = egg;
                if (_egg == nullptr) return;
                _circle->setColor(Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[egg->getTeam()]);
                _team->setText("Team: " + egg->getTeam());
                _name->setText("Egg #" + std::to_string(egg->getId()));
            }
        }
    }
}