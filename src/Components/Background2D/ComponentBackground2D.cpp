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
            Background2D::Background2D(std::string texturePath)
            {
                _posX = 0;
                _posY = 0;
                _texturePath = texturePath;
                resize();
            }

            void Background2D::draw()
            {
                DrawTexture(_texture, _posX, _posY, WHITE);
            }

            void Background2D::resize()
            {
                _texture = Zappy::GUI::Raylib::TextureManager::get()->getTexture(_texturePath);
                int screenW = GetScreenWidth();
                int screenH = GetScreenHeight();

                float aspectRatio = (float)_texture.width / _texture.height;
                float screenAspectRatio = (float)screenW / screenH;

                if (screenAspectRatio > aspectRatio) {
                    _texture.width = screenW;
                    _texture.height = screenW / aspectRatio;
                } else {
                    _texture.height = screenH;
                    _texture.width = screenH * aspectRatio;
                }

                _posX = (screenW - _texture.width) / 2;
                _posY = (screenH - _texture.height) / 2;
            }
        }
    }
}