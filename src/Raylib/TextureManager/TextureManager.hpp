/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TextureManager
*/

#ifndef TEXTURE_MANAGER_HPP_
    #define TEXTURE_MANAGER_HPP_

    #include <raylib.h>
    #include <unordered_map>
    #include <string>
    #include <vector>

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class TextureManager {
                public:
                    static TextureManager *get();

                    Texture getTexture(std::string &fileName);
                    Texture getTexture(Color color, std::string &name);
                    void destroy();
                    void unload();
                    void reload();

                private:
                    TextureManager();
                    ~TextureManager();

                    bool _isDestroyed = false;
                    std::unordered_map<std::string, Texture> _textures;
                    std::vector<std::string> _refs;
            };
        }
    }
}

#endif /* !TEXTURE_MANAGER_HPP_ */
