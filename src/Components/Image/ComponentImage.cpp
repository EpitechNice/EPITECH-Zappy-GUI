/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentImage
*/

#include "ComponentImage.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Image::Image(std::string path, std::pair<float, float> pos, float scale)
                : _path(path), _pos(pos)
            {
                _texture = LoadTexture(path.c_str());
                _isDestroyed = false;
                _texture.width *= scale;
                _texture.height *= scale;
            }

            Image::~Image()
            {
                destroy();
            }

            void Image::destroy()
            {
                if (!_isDestroyed) {
                    UnloadTexture(_texture);
                    _isDestroyed = true;
                }
            }


            void Image::draw()
            {
                DrawTexture(_texture, _pos.first, _pos.second, WHITE);
            }


            void Image::setPos(std::pair<float, float> pos)
            {
                _pos = pos;
            }


            std::pair<int, int> Image::getSize()
            {
                return std::make_pair(_texture.width, _texture.height);
            }
        }
    }
}