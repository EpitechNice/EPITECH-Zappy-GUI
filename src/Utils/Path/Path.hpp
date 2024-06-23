/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Path
*/

#ifndef PATH_HPP_
    #define PATH_HPP_

    #include <string>
    #include <raylib.h>

namespace Zappy {
    namespace GUI {
        class Path {
            public:
                static Path *get();
                std::string path() const;

            private:
                Path();
                ~Path() = default;

                std::string _path;
        };
    }
}

#endif /* !PATH_HPP_ */
