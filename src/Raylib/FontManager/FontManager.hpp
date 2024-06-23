/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** FontManager
*/

#ifndef FONT_MANAGER_HPP_
    #define FONT_MANAGER_HPP_

    #include <raylib.h>
    #include <unordered_map>
    #include <string>
    #include <vector>

    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            /**
             * @brief FontManager class
             *
             * @note This class is a singleton
             */
            class FontManager {
                public:
                    /**
                     * @brief Get the FontManager instance
                     */
                    static FontManager *get();

                    /**
                     * @brief Get a font
                     *
                     * @param fileName The font file name
                     *
                     * @return `font` The font
                     *
                     * @note This function will load the font if it's not already loaded
                     */
                    Font getFont(std::string &fileName);

                    /**
                     * @brief Destroy the FontManager instance
                     *
                     * @warning After the destruction of the instance, you won't be able to use it anymore
                     */
                    void destroy();

                    /**
                     * @brief Unload all the fonts
                     *
                     * @note This function do not clear the references
                     */
                    void unload();

                    /**
                     * @brief Reload all the fonts from the references
                     */
                    void reload();

                private:
                    FontManager();
                    ~FontManager();

                    bool _isDestroyed = false;
                    std::unordered_map<std::string, Font> _fonts;
                    std::vector<std::string> _refs;
            };
        }
    }
}


#endif /* !FONT_MANAGER_HPP_ */
