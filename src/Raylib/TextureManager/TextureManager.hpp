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
            /**
             * @brief TextureManager class
             *
             * @note This class is a singleton
             */
            class TextureManager {
                public:
                    /**
                     * @brief Get the TextureManager instance
                     */
                    static TextureManager *get();

                    /**
                     * @brief Get a texture
                     *
                     * @param fileName The texture file name
                     *
                     * @return `texture` The texture
                     *
                     * @note This function will load the texture if it's not already loaded
                     */
                    Texture getTexture(std::string &fileName);

                    /**
                     * @brief Get a texture
                     *
                     * @param color The color of the texture
                     * @param name The name of the texture
                     *
                     * @return `texture` The texture
                     *
                     * @note This function will load the texture if it's not already loaded
                     * @note The loading of the texture is based on the name
                     */
                    Texture getTexture(Color color, std::string &name);

                    /**
                     * @brief Destroy the TextureManager instance
                     *
                     * @warning After the destruction of the instance, you won't be able to use it anymore
                     */
                    void destroy();

                    /**
                     * @brief Unload all the textures
                     *
                     * @note This function do not clear the references
                     */
                    void unload();

                    /**
                     * @brief Reload all the textures from the references
                     */
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
