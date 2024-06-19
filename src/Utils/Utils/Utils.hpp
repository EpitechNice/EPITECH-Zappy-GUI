/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include <string>

namespace Zappy {
    namespace GUI {
        /**
         * @brief Check if a string is made of only numbers
         *
         * @param str The string to check
         *
         * @return `true` if the string is made of only numbers, `false` otherwise
         */
        bool isNumber(const std::string &str);
    }
}

#endif /* !UTILS_HPP_ */
