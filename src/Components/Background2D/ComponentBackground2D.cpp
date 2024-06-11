/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentBackground2D
*/

#include "ComponentBackground2D.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Background2D::Background2D(std::string texturePath, bool center)
            {
                _isDestroyed = false;
                _posX = 0;
                _posY = 0;

                _texture = LoadTexture(texturePath.c_str());
                int screenW = GetScreenWidth();
                int screenH = GetScreenHeight();
                int width = screenW - _texture.width;
                int height = screenH - _texture.height;
                if (width > height) {
                    _texture.width = screenW;
                    _texture.height = screenW * _texture.height / _texture.width;
                } else {
                    _texture.height = screenH;
                    _texture.width = screenH * _texture.width / _texture.height;
                }
                if (center) {
                    _posX = (screenW - _texture.width) / 2;
                    _posY = (screenH - _texture.height) / 2;
                }
                _sizeX = _texture.width;
                _sizeY = _texture.height;
            }

            void Background2D::destroy()
            {
                if (_isDestroyed) return;
                UnloadTexture(_texture);
                _isDestroyed = true;
            }

            void Background2D::draw()
            {
                DrawTexture(_texture, _posX, _posY, WHITE);
            }
        }
    }
}