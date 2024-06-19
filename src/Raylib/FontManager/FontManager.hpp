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

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class FontManager {
                public:
                    static FontManager *get();

                    Font getFont(std::string &fileName);
                    void destroy();
                    void unload();
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
