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
        /**
         * @brief Commands class for handle and process command
         */
        class Commands
        {
            private:
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;
            public:
                /**
                 * @brief Construct Command class
                */
                Commands();
                ~Commands() = default;

                /**
                 * @brief Init ressources of the game in the command class for accesibility
                 * @param ressources The ressources you want to init
                 */
                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);

                /**
                 * @brief Handle and process bct command
                 * @param responseValue the values ​​of the bct command
                 */
                void handleCommandBct(const std::string &responseValue);
                /**
                 * @brief Handle and process tna command
                 * @param responseValue the values ​​of the tna command
                 */
                void handleCommandTna(const std::string &responseValue);
                /**
                 * @brief Handle and process pnw command
                 * @param responseValue the values ​​of the pnw command
                 */
                void handleCommandPnw(const std::string &responseValue);
                /**
                 * @brief Handle and process ppo command
                 * @param responseValue the values ​​of the ppo command
                 */
                void handleCommandPpo(const std::string &responseValue);
                /**
                 * @brief Handle and process plv command
                 * @param responseValue the values ​​of the plv command
                 */
                void handleCommandPlv(const std::string &responseValue);
                /**
                 * @brief Handle and process pin command
                 * @param responseValue the values ​​of the pex command
                 */
                void handleCommandPin(const std::string &responseValue);
                /**
                 * @brief Handle and process pex command
                 * @param responseValue the values ​​of the pex command
                 */
                void handleCommandPex(const std::string &responseValue);
                /**
                 * @brief Handle and process pbc command
                 * @param responseValue the values ​​of the pbc command
                 */
                void handleCommandPbc(const std::string &responseValue);
                /**
                 * @brief Handle and process pic command
                 * @param responseValue the values ​​of the pic command
                 */
                void handleCommandPic(const std::string &responseValue);
                /**
                 * @brief Handle and process pie command
                 * @param responseValue the values ​​of the pie command
                 */
                void handleCommandPie(const std::string &responseValue);
                /**
                 * @brief Handle and process pfk command
                 * @param responseValue the values ​​of the pfk command
                 */
                void handleCommandPfk(const std::string &responseValue);
                /**
                 * @brief Handle and process pdr command
                 * @param responseValue the values ​​of the pdr command
                 */
                void handleCommandPdr(const std::string &responseValue);
                /**
                 * @brief Handle and process pgt command
                 * @param responseValue the values ​​of the pgt command
                 */
                void handleCommandPgt(const std::string &responseValue);
                /**
                 * @brief Handle and process pdi command
                 * @param responseValue the values ​​of the pdi command
                 */
                void handleCommandPdi(const std::string &responseValue);
                /**
                 * @brief Handle and process enw command
                 * @param responseValue the values ​​of the enw command
                 */
                void handleCommandEnw(const std::string &responseValue);
                /**
                 * @brief Handle and process ebo command
                 * @param responseValue the values ​​of the ebo command
                 */
                void handleCommandEbo(const std::string &responseValue);
                /**
                 * @brief Handle and process edi command
                 * @param responseValue the values ​​of the edi command
                 */
                void handleCommandEdi(const std::string &responseValue);
                /**
                 * @brief Handle and process sgt command
                 * @param responseValue the values ​​of the sgt command
                 */
                void handleCommandSgt(const std::string &responseValue);
                /**
                 * @brief Handle and process sst command
                 * @param responseValue the values ​​of the sst command
                 */
                void handleCommandSst(const std::string &responseValue);
                /**
                 * @brief Handle and process seg command
                 * @param responseValue the values ​​of the seg command
                 */
                void handleCommandSeg(const std::string &responseValue);
                /**
                 * @brief Handle and process smg command
                 * @param responseValue the values ​​of the smg command
                 */
                void handleCommandSmg(const std::string &responseValue);
                /**
                 * @brief Handle and process suc command
                 * @param responseValue the values ​​of the suc command
                 */
                void handleCommandSuc(const std::string &responseValue);
                /**
                 * @brief Handle and process sbp command
                 * @param responseValue the values ​​of the sbp command
                 */
                void handleCommandSbp(const std::string &responseValue);
        };
    }
}

#endif /* !COMMANDS_HPP_ */
