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
                _path = path;

                _texture = Zappy::GUI::Raylib::TextureManager::get()->getTexture(path);
                _texture.width *= scale;
                _texture.height *= scale;
                _sizeX = _texture.width;
                _sizeY = _texture.height;

                setRef();
                _refPosX = _posX / _refWidth * 100;
                _refPosY = _posY / _refHeight * 100;
                _refSizeX = _sizeX / _refWidth * 100;
                _refSizeY = _sizeY / _refHeight * 100;
            }

            void Image::draw()
            {
                DrawTexture(_texture, _posX, _posY, WHITE);
            }

            void Image::resize()
            {
                setRef();
                _posX = _refPosX * _refWidth / 100;
                _posY = _refPosY * _refHeight / 100;
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refSizeY * _refHeight / 100;

                _texture = Zappy::GUI::Raylib::TextureManager::get()->getTexture(_path);
                _texture.width = _sizeX;
                _texture.height = _sizeY;
            }
        }
    }
}