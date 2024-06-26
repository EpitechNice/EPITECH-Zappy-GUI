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
    #include <regex>

    #include "Ressources.hpp"
    #include "TileRessources.hpp"
    #include "SharedMemory.hpp"

namespace Zappy
{
    namespace Server
    {
        /**
         * @brief Commands class
         */
        class Commands
        {
            private:
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;
                std::shared_ptr<Zappy::Server::SharedMemory> _sharedMemory;
            public:
                /**
                 * @brief Construct by default
                 */
                Commands();
                ~Commands() = default;

                /**
                 * @brief Get game's ressources
                 *
                 * @return `_ressources` game's ressources
                 */
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> getRessources();

                /**
                 * @brief Get sharedMemory
                 *
                 * @return `_sharedMemory` commands queue from server
                 */
                std::shared_ptr<Zappy::Server::SharedMemory> getSharedMemory();

                /**
                 * @brief set the command list to use it directly in command
                 *
                 * @note _sharedMemory set
                 * @param sharedMemory: list of commands
                 */
                void setSharedMemory(std::shared_ptr<Zappy::Server::SharedMemory> sharedMemory);

                /**
                 * @brief set the ressources for the command
                 *
                 * @note _ressources set
                 * @param ressources: the ressources of the game
                 */
                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);

                /**
                 * @brief Handle the command msz
                 *
                 * @note msz x y (Get the width and height of the world)
                 * @param x: width of the world
                 * @param y: height of the world
                 */
                void handleCommandMsz(const std::string& responseValue);

                /**
                 * @brief Handle the command bct
                 *
                 * @note bct x y q0 q1 q2 q3 q4 q5 q6 q7 (Get the content of a tile)
                 * @param x: x position of the tile
                 * @param y: y position of the tile
                 * @param q0: quantity of food
                 * @param q1: quantity of linemate
                 * @param q2: quantity of deraumere
                 * @param q3: quantity of sibur
                 * @param q4: quantity of mendiane
                 * @param q5: quantity of phiras
                 * @param q6: quantity of thystame
                 */
                void handleCommandBct(const std::string& responseValue);

                /**
                 * @brief Handle the command tna
                 *
                 * @note tna name (Get the name of a team)
                 * @param name: name of the team
                 */
                void handleCommandTna(const std::string& responseValue);

                /**
                 * @brief Handle the command pnw
                 *
                 * @note pnw id x y o l n (Connect a new player)
                 * @param id: player id
                 * @param x: x position of the player
                 * @param y: y position of the player
                 * @param o: orientation of the player
                 * @param l: level of the player
                 * @param n: name of the player
                 */
                void handleCommandPnw(const std::string& responseValue);

                /**
                 * @brief Handle the command ppo
                 *
                 * @note ppo id x y o (Set the position of a player)
                 * @param id: player id
                 * @param x: x position of the player
                 * @param y: y position of the player
                 * @param o: orientation of the player
                 */
                void handleCommandPpo(const std::string& responseValue);

                /**
                 * @brief Handle the command plv
                 *
                 * @note plv id l (Set the level of a player)
                 * @param id: player id
                 * @param l: level of the player
                 */
                void handleCommandPlv(const std::string& responseValue);

                /**
                 * @brief Handle the command pin
                 *
                 * @note pin id x y q0 q1 q2 q3 q4 q5 q6 q7 q8 (Player inventory)
                 * @param id: player id
                 * @param x: x position of the player
                 * @param y: y position of the player
                 * @param q0: quantity of food
                 * @param q1: quantity of linemate
                 * @param q2: quantity of deraumere
                 * @param q3: quantity of sibur
                 * @param q4: quantity of mendiane
                 * @param q5: quantity of phiras
                 * @param q6: quantity of thystame
                 */
                void handleCommandPin(const std::string& responseValue);

                /**
                 * @brief Handle the command pex
                 *
                 * @note pex id (Player explosion)
                 * @param id: player id
                 */
                void handleCommandPex(const std::string& responseValue);

                /**
                 * @brief Handle the command pbc
                 *
                 * @note pbc id message (Broadcast a message)
                 * @param id: player id
                 * @param message: message to broadcast
                 */
                void handleCommandPbc(const std::string& responseValue);

                /**
                 * @brief Handle the command pic
                 *
                 * @note pic x y l id id ... (Start an incantation)
                 * @param x: x position of the player
                 * @param y: y position of the player
                 * @param l: level of the incantation
                 * @param id: player id
                 */
                void handleCommandPic(const std::string& responseValue);

                /**
                 * @brief Handle the command pie
                 *
                 * @note pie x y r (End an incantation)
                 * @param x: x position of the player
                 * @param y: y position of the player
                 * @param r: result of the incantation
                 */
                void handleCommandPie(const std::string& responseValue);

                /**
                 * @brief Handle the command pfk
                 *
                 * @note pfk id (Player lay an egg)
                 * @param id: player id
                 */
                void handleCommandPfk(const std::string& responseValue);

                /**
                 * @brief Handle the command pdr
                 *
                 * @note pdr id r (Player drop an object)
                 * @param id: player id
                 * @param r: resource
                 */
                void handleCommandPdr(const std::string& responseValue);

                /**
                 * @brief Handle the command pgd
                 *
                 * @note pgd id r (Player get an object)
                 * @param id: player id
                 * @param r: resource
                 */
                void handleCommandPgt(const std::string& responseValue);

                /**
                 * @brief Handle the command pdi
                 *
                 * @note pdi id (Player death)
                 * @param id: player id
                 */
                void handleCommandPdi(const std::string& responseValue);

                /**
                 * @brief Handle the command enw
                 *
                 * @note enw eid pid x y (Create an egg)
                 * @param eid: egg id
                 * @param pid: player id
                 * @param x: x position of the egg
                 * @param y: y position of the egg
                 */
                void handleCommandEnw(const std::string& responseValue);

                /**
                 * @brief Handle the command eht
                 *
                 * @note eht eid (Player replace an egg)
                 * @param eid: egg id
                 */
                void handleCommandEbo(const std::string& responseValue);

                /**
                 * @brief Handle the command ebo
                 *
                 * @note ebo eid (Egg death)
                 * @param eid: egg id
                 */
                void handleCommandEdi(const std::string& responseValue);

                /**
                 * @brief Handle the command sgt
                 *
                 * @note sgt (Get the time unit)
                 */
                void handleCommandSgt(const std::string& responseValue);

                /**
                 * @brief Handle the command sst
                 *
                 * @note sst t (Set the time unit)
                 * @param t: time unit
                 */
                void handleCommandSst(const std::string& responseValue);

                /**
                 * @brief Handle the command seg
                 *
                 * @note seg t (End of the game)
                 * @param t: team name
                 */
                void handleCommandSeg(const std::string& responseValue);

                /**
                 * @brief Handle the command smg
                 *
                 * @note smg message (Send a message to all players)
                 */
                void handleCommandSmg(const std::string& responseValue);

                /**
                 * @brief Handle the command suc
                 *
                 * @note suc (unknow command)
                 */
                void handleCommandSuc(const std::string& responseValue);

                /**
                 * @brief Handle the command sbp
                 *
                 * @note sbp (command Parameter)
                 */
                void handleCommandSbp(const std::string& responseValue);
        };
    }
}

#endif /* !COMMANDS_HPP_ */
