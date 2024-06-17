/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
    #define COMMANDS_HPP_

    #include <string>
    #include <sstream>
    #include <iostream>

    #include "Ressources.hpp"
    #include "TileRessources.hpp"

namespace Zappy
{
    namespace Server
    {
        class Commands
        {
            private:
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;
            public:
                Commands();
                ~Commands() = default;

                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);

                void handleCommandMsz(const std::string& responseValue);
                void handleCommandBct(const std::string& responseValue);
                void handleCommandTna(const std::string& responseValue);
                void handleCommandPnw(const std::string& responseValue);
                void handleCommandPpo(const std::string& responseValue);
                void handleCommandPlv(const std::string& responseValue);
                void handleCommandPin(const std::string& responseValue);
                void handleCommandPex(const std::string& responseValue);
                void handleCommandPbc(const std::string& responseValue);
                void handleCommandPic(const std::string& responseValue);
                void handleCommandPie(const std::string& responseValue);
                void handleCommandPfk(const std::string& responseValue);
                void handleCommandPdr(const std::string& responseValue);
                void handleCommandPgt(const std::string& responseValue);
                void handleCommandPdi(const std::string& responseValue);
                void handleCommandEnw(const std::string& responseValue);
                void handleCommandEbo(const std::string& responseValue);
                void handleCommandEdi(const std::string& responseValue);
                void handleCommandSgt(const std::string& responseValue);
                void handleCommandSst(const std::string& responseValue);
                void handleCommandSeg(const std::string& responseValue);
                void handleCommandSmg(const std::string& responseValue);
                void handleCommandSuc(const std::string& responseValue);
                void handleCommandSbp(const std::string& responseValue);
        };
    }
}

#endif /* !COMMANDS_HPP_ */
