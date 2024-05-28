/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Color
*/

#ifndef COLOR_MANAGER_HPP_
    #define COLOR_MANAGER_HPP_

#include <raylib.h>

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            namespace ColorManager {
                Color Darker(Color color, float percent);
                Color Lighter(Color color, float percent);
            }
        }
    }
}

#endif /* !COLOR_MANAGER_HPP_ */
