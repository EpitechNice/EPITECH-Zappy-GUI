/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TextureManager
*/

#include "TextureManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            TextureManager *TextureManager::get()
            {
                static TextureManager instance;
                return &instance;
            }

            TextureManager::TextureManager()
            {
                _textures.clear();
                _refs.clear();

                std::vector<std::string> textures = {
                };
                for (auto &texture : textures)
                    getTexture(texture);
            }

            TextureManager::~TextureManager()
            {
                destroy();
            }

            void TextureManager::destroy()
            {
                if (_isDestroyed) return;
                unload();
                _isDestroyed = true;
            }

            Texture TextureManager::getTexture(std::string &fileName)
            {
                if (_textures.find(fileName) == _textures.end()) {
                    std::string texturePath = Zappy::GUI::Path::get()->path() + "img/" + fileName;
                    Texture texture = LoadTexture(texturePath.c_str());
                    _textures[fileName] = texture;
                    _refs.push_back(fileName);
                    return texture;
                }
                return _textures[fileName];
            }

            Texture TextureManager::getTexture(Color color, std::string &name)
            {
                if (_textures.find(name) == _textures.end()) {
                    Texture texture = LoadTextureFromImage(GenImageColor(1, 1, color));
                    _textures[name] = texture;
                    _refs.push_back(name);
                    return texture;
                }
                return _textures[name];
            }

            void TextureManager::unload()
            {
                for (auto &texture : _textures)
                    UnloadTexture(texture.second);
                _textures.clear();
            }

            void TextureManager::reload()
            {
                for (auto &ref: _refs) {
                    std::string texturePath = Zappy::GUI::Path::get()->path() + "img/" + ref;
                    Texture texture = LoadTexture(texturePath.c_str());
                    _textures[ref] = texture;
                }
            }
        }
    }
}