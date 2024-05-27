/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Parsing
*/

#include "Parsing.hpp"

namespace Zappy {
    namespace GUI {
        const char* Parsing::Help::what() const noexcept
        {
            std::ifstream file("assets/help.txt");
            if (!file.is_open())
                return "Failed to open help file.";
            std::string content;
            std::string line;
            while (std::getline(file, line))
                content += line + "\n";
            file.close();
            std::cout << content << std::endl;
            return "";
        }
    }
}