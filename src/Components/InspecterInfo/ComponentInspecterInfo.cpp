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
                setRef();
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                float refSize = 1.67;
                float gap = refSize * _refWidth / 100;

                _player = nullptr;
                _egg = nullptr;
                _noPlayerSelected = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "No player or egg selected", 20, WHITE);
                _team = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "Team: ", 20, WHITE);
                _name = std::make_unique<TextBox>(std::make_pair(_posX, _team->getPosY() + _team->getSizeY() + gap), _sizeX, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_posX, _name->getPosY() + _name->getSizeY() + gap), _sizeX, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_posX, _food->getPosY() + _food->getSizeY() + gap), _sizeX, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_posX, _linemate->getPosY() + _linemate->getSizeY() + gap), _sizeX, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_posX, _deraumere->getPosY() + _deraumere->getSizeY() + gap), _sizeX, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_posX, _sibur->getPosY() + _sibur->getSizeY() + gap), _sizeX, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_posX, _mendiane->getPosY() + _mendiane->getSizeY() + gap), _sizeX, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_posX, _phiras->getPosY() + _phiras->getSizeY() + gap), _sizeX, "Thystame: ", 20, WHITE);

                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
            }

            void InspecterInfo::draw()
            {
                if (_player == nullptr && _egg == nullptr) {
                    _noPlayerSelected->draw();
                    return;
                }
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

            void InspecterInfo::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                float refSize = 1.67;
                float gap = refSize * _refWidth / 100;

                _noPlayerSelected->resize();
                _team->resize();
                _name->resize();
                _food->resize();
                _linemate->resize();
                _deraumere->resize();
                _sibur->resize();
                _mendiane->resize();
                _phiras->resize();
                _thystame->resize();

                _noPlayerSelected->setPosX(_posX);
                _noPlayerSelected->setPosY(_posY);

                _team->setPosX(_posX);
                _team->setPosY(_posY);

                _name->setPosX(_posX);
                _name->setPosY(_team->getPosY() + _team->getSizeY() + gap);

                _food->setPosX(_posX);
                _food->setPosY(_name->getPosY() + _name->getSizeY() + gap);

                _linemate->setPosX(_posX);
                _linemate->setPosY(_food->getPosY() + _food->getSizeY() + gap);

                _deraumere->setPosX(_posX);
                _deraumere->setPosY(_linemate->getPosY() + _linemate->getSizeY() + gap);

                _sibur->setPosX(_posX);
                _sibur->setPosY(_deraumere->getPosY() + _deraumere->getSizeY() + gap);

                _mendiane->setPosX(_posX);
                _mendiane->setPosY(_sibur->getPosY() + _sibur->getSizeY() + gap);

                _phiras->setPosX(_posX);
                _phiras->setPosY(_mendiane->getPosY() + _mendiane->getSizeY() + gap);

                _thystame->setPosX(_posX);
                _thystame->setPosY(_phiras->getPosY() + _phiras->getSizeY() + gap);
            }

            void InspecterInfo::modPosX(float x)
            {
                _posX += x;
                _refPosX = _posX / _refWidth * 100;
                _noPlayerSelected->setPosX(_posX);
                _team->setPosX(_posX);
                _name->setPosX(_posX);
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
                _team->setColor(Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[player->getTeam()]);
                _team->setText("Team: " + player->getTeam());
                _name->setText("Player #" + std::to_string(player->getId()) + "          Lvl: " + std::to_string(player->getLvl()));
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
                _team->setColor(Zappy::GUI::Ressources::Ref::get()->ressources->teamsColor[egg->getTeam()]);
                _team->setText("Team: " + egg->getTeam());
                _name->setText("Egg #" + std::to_string(egg->getId()));
            }
        }
    }
}