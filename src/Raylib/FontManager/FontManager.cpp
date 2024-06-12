/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** FontManager
*/

#include "FontManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            FontManager *FontManager::get()
            {
                static FontManager instance;
                return &instance;
            }

            FontManager::~FontManager()
            {
                destroy();
            }

            void FontManager::destroy()
            {
                if (_isDestroyed) return;
                for (auto &font : _fonts)
                    UnloadFont(font.second);
                _fonts.clear();
                _isDestroyed = true;
            }

            Font FontManager::getFont(std::string &fileName)
            {
                if (_fonts.find(fileName) == _fonts.end()) {
                    std::string path = "assets/font/" + fileName;
                    Font font = LoadFont(path.c_str());
                    _fonts[fileName] = font;
                    return font;
                }
                return _fonts[fileName];
            }
        }
    }
}
