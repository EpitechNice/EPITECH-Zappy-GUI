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
            {
                _posX = pos.first;
                _posY = pos.second;

                _texture = Zappy::GUI::Raylib::TextureManager::get()->getTexture(path);
                _texture.width *= scale;
                _texture.height *= scale;
                _sizeX = _texture.width;
                _sizeY = _texture.height;
            }

            void Image::draw()
            {
                DrawTexture(_texture, _posX, _posY, WHITE);
            }
        }
    }
}