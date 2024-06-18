/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Eggs
*/

#include "Eggs.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            Eggs::Eggs(int id, int x, int y, std::string team)
            {
                _id = id;
                _x = x;
                _y = y;
                _team = team;
            }

            int Eggs::getId() const
            {
                return _id;
            }


            int Eggs::getX() const
            {
                return _x;
            }

            void Eggs::setX(int x)
            {
                _x = x;
            }


            int Eggs::getY() const
            {
                return _y;
            }

            void Eggs::setY(int y)
            {
                _y = y;
            }


            std::string Eggs::getTeam() const
            {
                return _team;
            }
        }
    }
}