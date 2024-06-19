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
                /**
                 * @brief Darken a color
                 *
                 * @param color The color to darken
                 * @param percent The percent to darken
                 */
                Color Darker(Color color, float percent);

                /**
                 * @brief Lighten a color
                 *
                 * @param color The color to lighten
                 * @param percent The percent to lighten
                 */
                Color Lighter(Color color, float percent);
            }
        }
    }
}

#endif /* !COLOR_MANAGER_HPP_ */
