/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ColorManager
*/

#include "ColorManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            namespace ColorManager {
                Color Darker(Color color, float percent)
                {
                    if (percent < 0) percent = 0;
                    if (percent > 100) percent = 100;

                    float factor = (100 - percent) / 100.0f;

                    Color darkerColor = {
                        (unsigned char)(color.r * factor),
                        (unsigned char)(color.g * factor),
                        (unsigned char)(color.b * factor),
                        color.a
                    };

                    return darkerColor;
                }

                Color Lighter(Color color, float percent)
                {
                    if (percent < 0) percent = 0;
                    if (percent > 100) percent = 100;

                    float factor = (100 + percent) / 100.0f;

                    Color lighterColor = {
                        (unsigned char)(color.r * factor > 255 ? 255 : color.r * factor),
                        (unsigned char)(color.g * factor > 255 ? 255 : color.g * factor),
                        (unsigned char)(color.b * factor > 255 ? 255 : color.b * factor),
                        color.a
                    };

                    return lighterColor;
                }
            }
        }
    }
}