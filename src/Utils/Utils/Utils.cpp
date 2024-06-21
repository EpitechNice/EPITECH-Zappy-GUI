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

        std::vector<std::string> split(const std::string &str, const std::string &delim)
        {
            if (str.empty())
                return {};
            if (str.find(delim) == std::string::npos)
                return {str};

            std::vector<std::string> tokens;
            std::size_t start = 0;

            while (true) {
                std::size_t end = str.find(delim, start);
                if (end == std::string::npos) {
                    tokens.push_back(str.substr(start));
                    break;
                }
                tokens.push_back(str.substr(start, end - start));
                start = end + delim.size();
                while (delim.find(str[start]) != std::string::npos && start < str.size())
                    start++;
            }
            return tokens;
        }
    }
}