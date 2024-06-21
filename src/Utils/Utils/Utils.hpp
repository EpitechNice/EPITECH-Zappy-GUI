/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Utils
*/

#ifndef UTILS_HPP_
    #define UTILS_HPP_

    #include <string>
    #include <vector>

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

        /**
         * @brief Split a string into a vector of strings
         *
         * @param str The string to split
         * @param delimiter The delimiter to split the string with
         *
         * @return A vector of strings
         */
        std::vector<std::string> split(const std::string &str, const std::string &delimiter);
    }
}

#endif /* !UTILS_HPP_ */
