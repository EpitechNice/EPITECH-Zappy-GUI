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
    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        /**
         * @brief Parsing class
         */
        class Parsing {
            public:
                /**
                 * @brief Parsing error class
                 *
                 * @note This class is used to throw parsing errors
                 */
                class ParsingError : public std::exception {
                    public:
                        ParsingError(const std::string &message);
                        const char *what() const noexcept override;

                    private:
                        std::string _message;
                };

                /**
                 * @brief Help class
                 *
                 * @note This class is used to throw help errors
                 */
                class Help : public std::exception {
                    public:
                        Help() = default;
                        const char *what() const noexcept override;
                };

                /**
                 * @brief Constructor of Parsing class
                 *
                 * @param argc The number of arguments
                 * @param argv The arguments
                 */
                Parsing(int argc, char **argv);
                ~Parsing() = default;

                /**
                 * @brief Get the port
                 *
                 * @return `int` The port
                 *
                 * @warning This function have to be used after the constructor. Else it will return -1
                 */
                int getPort();

                /**
                 * @brief Get the machine
                 *
                 * @return `std::string` The machine
                 *
                 * @warning This function have to be used after the constructor. Else it will return an empty string
                 */
                std::string getMachine();

            protected:
            private:
                /**
                 * @brief Parse the port argument
                 *
                 * @param argc The number of arguments
                 * @param argv The arguments
                 * @param i The index of the argument
                 */
                void _parseArgPort(int argc, char **argv, int i);

                /**
                 * @brief Parse the machine argument
                 *
                 * @param argc The number of arguments
                 * @param argv The arguments
                 * @param i The index of the argument
                 */
                void _parseArgMachine(int argc, char **argv, int i);

                int _port = -1;
                std::string _machine = "";
        };
    }
}

#endif /* !PARSING_HPP_ */
