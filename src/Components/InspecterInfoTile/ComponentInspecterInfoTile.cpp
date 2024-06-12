/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterInfoTile
*/

#include "ComponentInspecterInfoTile.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            InspecterInfoTile::InspecterInfoTile(std::pair<int, int> pos, std::pair<int, int> size)
            {
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;

                _tile = nullptr;
                _noTileSelected = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "No tile selected", 20, WHITE);
                _name = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_posX, _name->getPosY() + _name->getSizeY() + 10), _sizeX, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_posX, _food->getPosY() + _food->getSizeY() + 10), _sizeX, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_posX, _linemate->getPosY() + _linemate->getSizeY() + 10), _sizeX, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_posX, _deraumere->getPosY() + _deraumere->getSizeY() + 10), _sizeX, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_posX, _sibur->getPosY() + _sibur->getSizeY() + 10), _sizeX, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_posX, _mendiane->getPosY() + _mendiane->getSizeY() + 10), _sizeX, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_posX, _phiras->getPosY() + _phiras->getSizeY() + 10), _sizeX, "Thystame: ", 20, WHITE);
                _egg = std::make_unique<TextBox>(std::make_pair(_posX, _thystame->getPosY() + _thystame->getSizeY() + 10), _sizeX, "Egg: ", 20, WHITE);
                _players = std::make_unique<TextBox>(std::make_pair(_posX, _egg->getPosY() + _egg->getSizeY() + 10), _sizeX, "Players: ", 20, WHITE);
            }

            void InspecterInfoTile::draw()
            {
                if (_tile == nullptr) {
                    _noTileSelected->draw();
                    return;
                }
                _name->draw();
                _food->draw();
                _linemate->draw();
                _deraumere->draw();
                _sibur->draw();
                _mendiane->draw();
                _phiras->draw();
                _thystame->draw();
                _egg->draw();
                _players->draw();
            }

            void InspecterInfoTile::modPosX(float x)
            {
                _posX += x;
                _noTileSelected->setPosX(_posX);
                _name->setPosX(_posX);
                _food->setPosX(_posX);
                _linemate->setPosX(_posX);
                _deraumere->setPosX(_posX);
                _sibur->setPosX(_posX);
                _mendiane->setPosX(_posX);
                _phiras->setPosX(_posX);
                _thystame->setPosX(_posX);
                _egg->setPosX(_posX);
                _players->setPosX(_posX);
            }

            void InspecterInfoTile::setInfo(std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tile)
            {
                _tile = tile;
                if (_tile == nullptr) return;
                _name->setText("Tile [" + std::to_string(tile->getX()) + "][" + std::to_string(tile->getY()) + "]");
                _food->setText("Food: " + std::to_string(_tile->getFood()));
                _linemate->setText("Linemate: " + std::to_string(_tile->getLinemate()));
                _deraumere->setText("Deraumere: " + std::to_string(_tile->getDeraumere()));
                _sibur->setText("Sibur: " + std::to_string(_tile->getSibur()));
                _mendiane->setText("Mendiane: " + std::to_string(_tile->getMendiane()));
                _phiras->setText("Phiras: " + std::to_string(_tile->getPhiras()));
                _thystame->setText("Thystame: " + std::to_string(_tile->getThystame()));
                _egg->setText("Egg: " + std::to_string(_tile->getEgg()));
                _players->setText("Players: " + std::to_string(_tile->getPlayers().size()));
            }
        }
    }
}