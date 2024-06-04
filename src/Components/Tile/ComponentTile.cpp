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
            Tile::Tile(Vector3 pos, Vector3 size, Color color, std::shared_ptr<Ressources> ressources)
                : _pos(pos), _size(size), _color(color), _ressources(ressources), _highlight(false), _select(false), _isDestroyed(false)
            {
                std::cout << "Tile size: " << size.x << " " << size.y << " " << size.z << std::endl;
                _grassSize = {size.x, size.y / 2, size.z};
                _grassPos = {pos.x, pos.y + size.y / 4, pos.z};
                _dirtSize = {size.x, size.y / 2, size.z};
                _dirtPos = {pos.x, pos.y - size.y / 4, pos.z};
                _grass = std::make_unique<Cubic>(_grassPos, _grassSize, color);
                _dirt = std::make_unique<Cubic>(_dirtPos, _dirtSize, BROWN);
                _wire = std::make_unique<Cubic>(_pos, _size, BLACK);
                _wire->setMode(Cubic::WIRES);
            }

            Tile::~Tile()
            {
                destroy();
            }

            void Tile::destroy()
            {
                if (_isDestroyed)
                    return;
                _isDestroyed = true;
            }

            Vector3 Tile::getPos() const
            {
                return _pos;
            }

            BoundingBox Tile::getTopBox() const
            {
                return {
                    .min = { _pos.x - _size.x / 2, (float)(_pos.y + _size.y / 2 - 0.1), _pos.z - _size.z / 2 },
                    .max = { _pos.x + _size.x / 2, (float)(_pos.y + _size.y / 2 + 0.1), _pos.z + _size.z / 2 },
                };
            }

            void Tile::draw()
            {
                _grass->draw();
                _dirt->draw();
                if (_select)
                    _wire->draw();

                Vector3 pos = _pos;
                pos.y += _select ? _size.y / 2 : 0;
                _ressources->setPos(pos);
                _ressources->drawLinemate();
                _ressources->drawDeraumere();
                _ressources->drawMendiane();
                _ressources->drawPhiras();
                _ressources->drawSibur();
                _ressources->drawThystame();
                _ressources->drawFood();
                _ressources->drawEgg();
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
                        _wire->setPosY(_pos.y);
                    } else {
                        _grass->setPosY(_grassPos.y + _size.y / 2);
                        _dirt->setPosY(_dirtPos.y + _size.y / 2);
                        _wire->setPosY(_pos.y + _size.y / 2);
                    }
                }
            }
        }
    }
}