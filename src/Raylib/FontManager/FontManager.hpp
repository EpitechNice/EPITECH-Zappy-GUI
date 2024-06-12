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

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class FontManager {
                public:
                    static FontManager *get();

                    Font getFont(std::string &fileName);
                    void destroy();

                private:
                    FontManager() = default;
                    ~FontManager();

                    bool _isDestroyed = false;
                    std::unordered_map<std::string, Font> _fonts;
            };
        }
    }
}


#endif /* !FONT_MANAGER_HPP_ */
