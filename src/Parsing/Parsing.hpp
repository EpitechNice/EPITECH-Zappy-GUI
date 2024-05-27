/*
** EPITECH PROJECT, 2024
** zappy_gui
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_

    #include <exception>
    #include <string>
    #include <iostream>
    #include <fstream>

    #include "Utils.hpp"

namespace Zappy {
    namespace GUI {
        class Parsing {
            public:
                class ParsingError : public std::exception {
                    public:
                        ParsingError(const std::string &message);
                        const char *what() const noexcept override;

                    private:
                        std::string _message;
                };

                class Help : public std::exception {
                    public:
                        Help() = default;
                        const char *what() const noexcept override;
                };

                Parsing(int argc, char **argv);
                ~Parsing() = default;

                int getPort();
                std::string getMachine();

            protected:
            private:
                void _parseArgPort(int argc, char **argv, int i);
                void _parseArgMachine(int argc, char **argv, int i);

                int _port = -1;
                std::string _machine = "";
        };
    }
}

#endif /* !PARSING_HPP_ */
