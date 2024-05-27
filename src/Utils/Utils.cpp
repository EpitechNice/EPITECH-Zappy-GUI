/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Utils
*/

#include "Utils.hpp"

namespace Zappy {
    namespace GUI {
        bool isNumber(const std::string &str)
        {
            for (const auto &c : str)
                if (!std::isdigit(c) && c != '-')
                    return false;
            return true;
        }
    }
}