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

            FontManager::FontManager()
            {
                _refs.clear();
                _fonts.clear();
            }

            FontManager::~FontManager()
            {
                destroy();
            }

            void FontManager::destroy()
            {
                if (_isDestroyed) return;
                unload();
                _isDestroyed = true;
            }

            Font FontManager::getFont(std::string &fileName)
            {
                if (_fonts.find(fileName) == _fonts.end()) {
                    std::string path = Zappy::GUI::Path::get()->path() + "font/" + fileName;
                    Font font = LoadFont(path.c_str());
                    _fonts[fileName] = font;
                    _refs.push_back(fileName);
                    return font;
                }
                return _fonts[fileName];
            }

            void FontManager::unload()
            {
                for (auto &font : _fonts)
                    UnloadFont(font.second);
                _fonts.clear();
            }

            void FontManager::reload()
            {
                for (auto &ref: _refs) {
                    std::string path = Zappy::GUI::Path::get()->path() + "font/" + ref;
                    Font font = LoadFont(path.c_str());
                    _fonts[ref] = font;
                }
            }
        }
    }
}
