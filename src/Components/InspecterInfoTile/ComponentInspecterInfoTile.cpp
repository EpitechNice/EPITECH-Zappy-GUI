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
                setRef();
                _posX = pos.first;
                _posY = pos.second;
                _sizeX = size.first;
                _sizeY = size.second;
                float refSize = 1.67;
                float gap = refSize * _refWidth / 100;

                _tile = nullptr;
                _noTileSelected = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "No tile selected", 20, WHITE);
                _name = std::make_unique<TextBox>(std::make_pair(_posX, _posY), _sizeX, "Player #", 20, WHITE);
                _food = std::make_unique<TextBox>(std::make_pair(_posX, _name->getPosY() + _name->getSizeY() + gap), _sizeX, "Food: ", 20, WHITE);
                _linemate = std::make_unique<TextBox>(std::make_pair(_posX, _food->getPosY() + _food->getSizeY() + gap), _sizeX, "Linemate: ", 20, WHITE);
                _deraumere = std::make_unique<TextBox>(std::make_pair(_posX, _linemate->getPosY() + _linemate->getSizeY() + gap), _sizeX, "Deraumere: ", 20, WHITE);
                _sibur = std::make_unique<TextBox>(std::make_pair(_posX, _deraumere->getPosY() + _deraumere->getSizeY() + gap), _sizeX, "Sibur: ", 20, WHITE);
                _mendiane = std::make_unique<TextBox>(std::make_pair(_posX, _sibur->getPosY() + _sibur->getSizeY() + gap), _sizeX, "Mendiane: ", 20, WHITE);
                _phiras = std::make_unique<TextBox>(std::make_pair(_posX, _mendiane->getPosY() + _mendiane->getSizeY() + gap), _sizeX, "Phiras: ", 20, WHITE);
                _thystame = std::make_unique<TextBox>(std::make_pair(_posX, _phiras->getPosY() + _phiras->getSizeY() + gap), _sizeX, "Thystame: ", 20, WHITE);
                _egg = std::make_unique<TextBox>(std::make_pair(_posX, _thystame->getPosY() + _thystame->getSizeY() + gap), _sizeX, "Egg: ", 20, WHITE);
                _players = std::make_unique<TextBox>(std::make_pair(_posX, _egg->getPosY() + _egg->getSizeY() + gap), _sizeX, "Players: ", 20, WHITE);

                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
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

            void InspecterInfoTile::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                float refSize = 1.67;
                float gap = refSize * _refWidth / 100;

                _noTileSelected->resize();
                _noTileSelected->setPosX(_posX);
                _noTileSelected->setPosY(_posY);

                _name->resize();
                _name->setPosX(_posX);
                _name->setPosY(_posY);

                _food->resize();
                _food->setPosX(_posX);
                _food->setPosY(_name->getPosY() + _name->getSizeY() + gap);

                _linemate->resize();
                _linemate->setPosX(_posX);
                _linemate->setPosY(_food->getPosY() + _food->getSizeY() + gap);

                _deraumere->resize();
                _deraumere->setPosX(_posX);
                _deraumere->setPosY(_linemate->getPosY() + _linemate->getSizeY() + gap);

                _sibur->resize();
                _sibur->setPosX(_posX);
                _sibur->setPosY(_deraumere->getPosY() + _deraumere->getSizeY() + gap);

                _mendiane->resize();
                _mendiane->setPosX(_posX);
                _mendiane->setPosY(_sibur->getPosY() + _sibur->getSizeY() + gap);

                _phiras->resize();
                _phiras->setPosX(_posX);
                _phiras->setPosY(_mendiane->getPosY() + _mendiane->getSizeY() + gap);

                _thystame->resize();
                _thystame->setPosX(_posX);
                _thystame->setPosY(_phiras->getPosY() + _phiras->getSizeY() + gap);

                _egg->resize();
                _egg->setPosX(_posX);
                _egg->setPosY(_thystame->getPosY() + _thystame->getSizeY() + gap);

                _players->resize();
                _players->setPosX(_posX);
                _players->setPosY(_egg->getPosY() + _egg->getSizeY() + gap);
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
                _egg->setText("Egg: " + std::to_string(_tile->getEggs().size()));
                _players->setText("Players: " + std::to_string(_tile->getPlayers().size()));
            }
        }
    }
}