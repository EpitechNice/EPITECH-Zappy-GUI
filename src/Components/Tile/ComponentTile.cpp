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
            Tile::Tile(Vector3 pos, Color color)
                : _pos(pos), _color(color), _highlight(false)
            {
                _grass = std::make_unique<Cubic>((Vector3){pos.x, pos.y + 0.3f, pos.z}, (Vector3){1.0f, 0.4f, 1.0f}, color);
                _dirt = std::make_unique<Cubic>((Vector3){pos.x, -0.2f, pos.z}, (Vector3){1.0f, 0.6f, 1.0f}, BROWN);
            }

            void Tile::draw()
            {
                _grass->draw();
                _dirt->draw();
            }

            void Tile::highlight(bool highlight)
            {
                if (_highlight != highlight) {
                    _highlight = highlight;
                    if (_highlight == false) {
                        _grass->setColor(_color);
                        _dirt->setColor(BROWN);
                    } else {
                        _grass->setColor(Zappy::GUI::Raylib::ColorManager::Darker(_color, 40));
                        _dirt->setColor(Zappy::GUI::Raylib::ColorManager::Darker(BROWN, 40));
                    }
                }
            }
        }
    }
}