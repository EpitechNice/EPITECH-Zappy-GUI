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
            Tile::Tile(Vector3 pos, Vector3 size, Color color)
                : _pos(pos), _size(size), _color(color), _highlight(false), _select(false), _isDestroyed(false)
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

                float tileXPart = size.x / 8;
                float tileYPart = size.y / 4;
                float startX = pos.x - size.x / 2;
                float startY = pos.y - size.y / 2;
                float scale = 0.2;

                _linemate = std::make_unique<Model3D>("Rocks/rock_1/rock", (Vector3){startX + tileXPart * 2, pos.y + size.y / 2, startY + tileYPart * 1}, scale);
                _deraumere = std::make_unique<Model3D>("Rocks/rock_2/rock", (Vector3){startX + tileXPart * 6, pos.y + size.y / 2, startY + tileYPart * 1}, scale);
                _sibur = std::make_unique<Model3D>("Rocks/rock_3/rock", (Vector3){startX + tileXPart * 7, pos.y + size.y / 2, startY + tileYPart * 2}, scale);
                _mendiane = std::make_unique<Model3D>("Rocks/rock_4/rock", (Vector3){startX + tileXPart * 6, pos.y + size.y / 2, startY + tileYPart * 3}, scale);
                _phiras = std::make_unique<Model3D>("Rocks/rock_5/rock", (Vector3){startX + tileXPart * 2, pos.y + size.y / 2, startY + tileYPart * 3}, scale);
                _thystame = std::make_unique<Model3D>("Rocks/rock_6/rock", (Vector3){startX + tileXPart * 1, pos.y + size.y / 2, startY + tileYPart * 2}, scale);
                _food = std::make_unique<Model3D>("Food/scene", (Vector3){startX + tileXPart * 3, pos.y + size.y / 2, startY + tileYPart * 2}, 1, (Vector3){1, 0, 0}, -20);
                _egg = std::make_unique<Model3D>("Egg/scene", (Vector3){startX + tileXPart * 5, pos.y + size.y / 2, startY + tileYPart * 2}, 0.3);
                _food->setOnPosY(pos.y + size.y / 2 - 0.2);
                _egg->setOnPosY(pos.y + size.y / 2);
            }

            Tile::~Tile()
            {
                destroy();
            }

            void Tile::destroy()
            {
                if (_isDestroyed)
                    return;
                _linemate->destroy();
                _deraumere->destroy();
                _sibur->destroy();
                _mendiane->destroy();
                _phiras->destroy();
                _thystame->destroy();
                _food->destroy();
                _egg->destroy();
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
                _linemate->draw();
                _deraumere->draw();
                _sibur->draw();
                _mendiane->draw();
                _phiras->draw();
                _thystame->draw();
                _food->draw();
                _egg->draw();
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