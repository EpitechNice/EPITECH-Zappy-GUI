/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentTile
*/

#include "ComponentTile.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Tile::Tile(Vector3 pos, Vector3 size, Color color, std::shared_ptr<Ressources> ressourcesDrawer, std::shared_ptr<Zappy::GUI::Ressources::TileRessources> ressources)
            {
                _posX = pos.x;
                _posY = pos.y;
                _posZ = pos.z;
                _sizeX = size.x;
                _sizeY = size.y;
                _sizeZ = size.z;
                _color = color;
                _ressourcesDrawer = ressourcesDrawer;
                _ressources = ressources;
                _highlight = false;
                _select = false;

                _grassSize = {size.x, size.y / 2, size.z};
                _grassPos = {pos.x, pos.y + size.y / 4, pos.z};
                _dirtSize = {size.x, size.y / 2, size.z};
                _dirtPos = {pos.x, pos.y - size.y / 4, pos.z};
                _grass = std::make_unique<Cube>(_grassPos, _grassSize, color, Cube::CUBE);
                _dirt = std::make_unique<Cube>(_dirtPos, _dirtSize, BROWN, Cube::CUBE);
                _wire = std::make_unique<Cube>((Vector3){_posX, _posY, _posZ}, (Vector3){_sizeX, _sizeY, _sizeZ}, BLACK, Cube::WIRES);
                _selectEffect = _sizeY / 3;
            }

            BoundingBox Tile::getTopBox() const
            {
                return {
                    .min = { _posX - _sizeX / 2, (float)(_posY + _sizeY / 2 - 0.1), _posZ - _sizeZ / 2 },
                    .max = { _posX + _sizeX / 2, (float)(_posY + _sizeY / 2 + 0.1), _posZ + _sizeZ / 2 },
                };
            }

            void Tile::draw()
            {
                _grass->draw();
                _dirt->draw();
                if (_select)
                    _wire->draw();

                _ressourcesDrawer->setPosX(_posX);
                _ressourcesDrawer->setPosY(_posY + (_select ? _selectEffect : 0));
                _ressourcesDrawer->setPosZ(_posZ);

                if (_ressources->hasLinemate()) _ressourcesDrawer->drawLinemate();
                if (_ressources->hasDeraumere()) _ressourcesDrawer->drawDeraumere();
                if (_ressources->hasMendiane()) _ressourcesDrawer->drawMendiane();
                if (_ressources->hasPhiras()) _ressourcesDrawer->drawPhiras();
                if (_ressources->hasSibur()) _ressourcesDrawer->drawSibur();
                if (_ressources->hasThystame()) _ressourcesDrawer->drawThystame();
                if (_ressources->hasFood()) _ressourcesDrawer->drawFood();
                if (_ressources->hasEgg()) _ressourcesDrawer->drawEgg();
                if (_ressources->hasPlayers()) _ressourcesDrawer->drawZappy();
            }

            void Tile::highlight(bool highlight)
            {
                if (_highlight != highlight && !_select) {
                    _highlight = highlight;
                    if (!_highlight) {
                        _grass->setColor(_color);
                        _dirt->setColor(BROWN);
                    } else {
                        _grass->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 40));
                        _dirt->setColor(Zappy::GUI::Raylib::ColorManager::Darker(BROWN, 40));
                    }
                }
            }

            void Tile::select(bool select)
            {
                if (_select != select) {
                    _select = select;
                    if (!_select) {
                        _grass->setPosY(_grassPos.y);
                        _dirt->setPosY(_dirtPos.y);
                        _wire->setPosY(_posY);
                    } else {
                        _grass->setPosY(_grassPos.y + _selectEffect);
                        _dirt->setPosY(_dirtPos.y + _selectEffect);
                        _wire->setPosY(_posY + _selectEffect);
                    }
                }
            }
        }
    }
}