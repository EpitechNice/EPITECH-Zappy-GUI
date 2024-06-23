/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Path
*/

#include "Path.hpp"

namespace Zappy {
    namespace GUI {
        Path *Path::get()
        {
            static Path instance;
            return &instance;
        }

        Path::Path()
        {
            _path = "assets/";

            if (!DirectoryExists(_path.c_str()))
                _path = "GUI/assets/";
        }

        std::string Path::path() const
        {
            return _path;
        }
    }
}