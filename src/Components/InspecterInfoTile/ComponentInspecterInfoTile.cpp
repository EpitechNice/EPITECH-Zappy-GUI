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
                _tile = nullptr;
                _pos = pos;
                _size = size;
                _noTileSelected = std::make_unique<TextBox>(std::make_pair(_pos.first, _pos.second), _size.first, "No tile selected", 20, WHITE);
                _name = std::make_unique<TextBox>(std::make_pair(_pos.first, _pos.second), _size.first, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_pos.first, _name->getPosY() + _name->getSizeY() + 10), _size.first, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_pos.first, _food->getPosY() + _food->getSizeY() + 10), _size.first, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_pos.first, _linemate->getPosY() + _linemate->getSizeY() + 10), _size.first, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_pos.first, _deraumere->getPosY() + _deraumere->getSizeY() + 10), _size.first, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_pos.first, _sibur->getPosY() + _sibur->getSizeY() + 10), _size.first, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_pos.first, _mendiane->getPosY() + _mendiane->getSizeY() + 10), _size.first, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_pos.first, _phiras->getPosY() + _phiras->getSizeY() + 10), _size.first, "Thystame: ", 20, WHITE);
                _egg = std::make_unique<TextBox>(std::make_pair(_pos.first, _thystame->getPosY() + _thystame->getSizeY() + 10), _size.first, "Egg: ", 20, WHITE);
                _players = std::make_unique<TextBox>(std::make_pair(_pos.first, _egg->getPosY() + _egg->getSizeY() + 10), _size.first, "Players: ", 20, WHITE);
                _isDestroyed = false;
            }

            InspecterInfoTile::~InspecterInfoTile()
            {
                destroy();
            }

            void InspecterInfoTile::destroy()
            {
                if (_isDestroyed) return;
                _noTileSelected->destroy();
                _name->destroy();
                _food->destroy();
                _linemate->destroy();
                _deraumere->destroy();
                _sibur->destroy();
                _mendiane->destroy();
                _phiras->destroy();
                _thystame->destroy();
                _egg->destroy();
                _players->destroy();
                _isDestroyed = true;
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

            void InspecterInfoTile::modPosX(int x)
            {
                _pos.first += x;
                _noTileSelected->setPosX(_pos.first);
                _name->setPosX(_pos.first);
                _food->setPosX(_pos.first);
                _linemate->setPosX(_pos.first);
                _deraumere->setPosX(_pos.first);
                _sibur->setPosX(_pos.first);
                _mendiane->setPosX(_pos.first);
                _phiras->setPosX(_pos.first);
                _thystame->setPosX(_pos.first);
                _egg->setPosX(_pos.first);
                _players->setPosX(_pos.first);
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