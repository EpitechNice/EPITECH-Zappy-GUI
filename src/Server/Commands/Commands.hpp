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
                /**
                 * @brief Handle the command msz
                 *
                 * @note msz x y (Get the width and height of the world)
                 * @note x: width of the world
                 * @note y: height of the world
                 */
                void handleCommandMsz(const std::string& responseValue);

                /**
                 * @brief Handle the command bct
                 *
                 * @note bct x y q0 q1 q2 q3 q4 q5 q6 q7 (Get the content of a tile)
                 * @note x: x position of the tile
                 * @note y: y position of the tile
                 * @note q0: quantity of food
                 * @note q1: quantity of linemate
                 * @note q2: quantity of deraumere
                 * @note q3: quantity of sibur
                 * @note q4: quantity of mendiane
                 * @note q5: quantity of phiras
                 * @note q6: quantity of thystame
                 */
                void handleCommandBct(const std::string& responseValue);

                /**
                 * @brief Handle the command tna
                 *
                 * @note tna name (Get the name of a team)
                 * @note name: name of the team
                 */
                void handleCommandTna(const std::string& responseValue);

                /**
                 * @brief Handle the command pnw
                 *
                 * @note pnw id x y o l n (Connect a new player)
                 * @note id: player id
                 * @note x: x position of the player
                 * @note y: y position of the player
                 * @note o: orientation of the player
                 * @note l: level of the player
                 * @note n: name of the player
                 */
                void handleCommandPnw(const std::string& responseValue);

                /**
                 * @brief Handle the command ppo
                 *
                 * @note ppo id x y o (Set the position of a player)
                 * @note id: player id
                 * @note x: x position of the player
                 * @note y: y position of the player
                 * @note o: orientation of the player
                 */
                void handleCommandPpo(const std::string& responseValue);

                /**
                 * @brief Handle the command plv
                 *
                 * @note plv id l (Set the level of a player)
                 * @note id: player id
                 * @note l: level of the player
                 */
                void handleCommandPlv(const std::string& responseValue);

                /**
                 * @brief Handle the command pin
                 *
                 * @note pin id x y q0 q1 q2 q3 q4 q5 q6 q7 q8 (Player inventory)
                 * @note id: player id
                 * @note x: x position of the player
                 * @note y: y position of the player
                 * @note q0: quantity of food
                 * @note q1: quantity of linemate
                 * @note q2: quantity of deraumere
                 * @note q3: quantity of sibur
                 * @note q4: quantity of mendiane
                 * @note q5: quantity of phiras
                 * @note q6: quantity of thystame
                 */
                void handleCommandPin(const std::string& responseValue);

                /**
                 * @brief Handle the command pex
                 *
                 * @note pex id (Player explosion)
                 * @note id: player id
                 */
                void handleCommandPex(const std::string& responseValue);

                /**
                 * @brief Handle the command pbc
                 *
                 * @note pbc id message (Broadcast a message)
                 * @note id: player id
                 * @note message: message to broadcast
                 */
                void handleCommandPbc(const std::string& responseValue);

                /**
                 * @brief Handle the command pic
                 *
                 * @note pic x y l id id ... (Start an incantation)
                 * @note x: x position of the player
                 * @note y: y position of the player
                 * @note l: level of the incantation
                 * @note id: player id
                 */
                void handleCommandPic(const std::string& responseValue);

                /**
                 * @brief Handle the command pie
                 *
                 * @note pie x y r (End an incantation)
                 * @note x: x position of the player
                 * @note y: y position of the player
                 * @note r: result of the incantation
                 */
                void handleCommandPie(const std::string& responseValue);

                /**
                 * @brief Handle the command pfk
                 *
                 * @note pfk id (Player lay an egg)
                 * @note id: player id
                 */
                void handleCommandPfk(const std::string& responseValue);

                /**
                 * @brief Handle the command pdr
                 *
                 * @note pdr id r (Player drop an object)
                 * @note id: player id
                 * @note r: resource
                 */
                void handleCommandPdr(const std::string& responseValue);

                /**
                 * @brief Handle the command pgd
                 *
                 * @note pgd id r (Player get an object)
                 * @note id: player id
                 * @note r: resource
                 */
                void handleCommandPgt(const std::string& responseValue);

                /**
                 * @brief Handle the command pdi
                 *
                 * @note pdi id (Player death)
                 * @note id: player id
                 */
                void handleCommandPdi(const std::string& responseValue);

                /**
                 * @brief Handle the command enw
                 *
                 * @note enw eid pid x y (Create an egg)
                 * @note eid: egg id
                 * @note pid: player id
                 * @note x: x position of the egg
                 * @note y: y position of the egg
                 */
                void handleCommandEnw(const std::string& responseValue);

                /**
                 * @brief Handle the command eht
                 *
                 * @note eht eid (Player replace an egg)
                 * @note eid: egg id
                 */
                void handleCommandEbo(const std::string& responseValue);

                /**
                 * @brief Handle the command ebo
                 *
                 * @note ebo eid (Egg death)
                 * @note eid: egg id
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
                 * @note t: time unit
                 */
                void handleCommandSst(const std::string& responseValue);

                /**
                 * @brief Handle the command seg
                 *
                 * @note seg t (End of the game)
                 * @note t: team name
                 */
                void handleCommandSeg(const std::string& responseValue);

                /**
                 * @brief Handle the command smg
                 *
                 * @note suc (unknow command)
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
