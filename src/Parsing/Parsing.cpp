/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** Parsing
*/

#include "Parsing.hpp"

namespace Zappy {
    namespace GUI {
        Parsing::Parsing(int argc, char **argv)
        {
            if (argc == 2 && std::string(argv[1]) == "-help")
                throw Help();

            if (argc != 5)
                throw ParsingError("Invalid number of arguments. Got " + std::to_string(argc) + " expected 5.");
            for (int i = 1; i < argc; i++) {
                if (std::string(argv[i]) == "-p") {
                    _parseArgPort(argc, argv, i);
                    i++;
                    continue;
                }
                if (std::string(argv[i]) == "-h") {
                    _parseArgMachine(argc, argv, i);
                    i++;
                    continue;
                }
                throw ParsingError("Invalid argument: \"" + std::string(argv[i]) + "\".");
            }
            if (_port == -1)
                throw ParsingError("Invalid argument: \"-p\". Port not set.");
            if (_machine.empty())
                throw ParsingError("Invalid argument: \"-h\". Machine not set.");
        }

        int Parsing::getPort()
        {
            return _port;
        }

        std::string Parsing::getMachine()
        {
            return _machine;
        }


        void Parsing::_parseArgPort(int argc, char **argv, int i)
        {
            if (_port != -1)
                throw ParsingError("Invalid argument: \"-p\". Port already set.");
            if (i + 1 >= argc)
                throw ParsingError("Invalid argument for \"-p\": \". Expect a value.");
            if (!isNumber(argv[i + 1]))
                throw ParsingError("Invalid argument for \"-p\": \"" + std::string(argv[i + 1]) + "\". Expect a number.");
            if (std::stoi(argv[i + 1]) < 0 || std::stoi(argv[i + 1]) > 65535)
                    throw ParsingError("Invalid argument for \"-p\": \"" + std::string(argv[i + 1]) + "\". Expect a number between 0 and 65535.");
            _port = std::stoi(argv[i + 1]);
        }

        void Parsing::_parseArgMachine(int argc, char **argv, int i)
        {
            if (!_machine.empty())
                throw ParsingError("Invalid argument: \"-h\". Machine already set.");
            if (i + 1 >= argc)
                throw ParsingError("Invalid argument for \"-h\". Expect a value.");
            if (std::string(argv[i + 1]).empty())
                throw ParsingError("Invalid argument for \"-h\". Expect a name.");
            _machine = argv[i + 1];
        }
    }
}