/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Players
*/

#include "Players.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            Players::Players(int id, int x, int y, Color team)
            {
                _id = id;
                _x = x;
                _y = y;
                _team = team;
                _linemate = 0;
                _deraumere = 0;
                _sibur = 0;
                _mendiane = 0;
                _phiras = 0;
                _thystame = 0;
                _food = 0;
            }

            int Players::getId() const
            {
                return _id;
            }


            int Players::getX() const
            {
                return _x;
            }

            void Players::setX(int x)
            {
                _x = x;
            }


            int Players::getY() const
            {
                return _y;
            }

            void Players::setY(int y)
            {
                _y = y;
            }


            int Players::getLinemate() const
            {
                return _linemate;
            }

            void Players::setLinemate(int linemate)
            {
                _linemate = linemate;
            }


            int Players::getDeraumere() const
            {
                return _deraumere;
            }

            void Players::setDeraumere(int deraumere)
            {
                _deraumere = deraumere;
            }


            int Players::getSibur() const
            {
                return _sibur;
            }

            void Players::setSibur(int sibur)
            {
                _sibur = sibur;
            }


            int Players::getMendiane() const
            {
                return _mendiane;
            }

            void Players::setMendiane(int mendiane)
            {
                _mendiane = mendiane;
            }


            int Players::getPhiras() const
            {
                return _phiras;
            }

            void Players::setPhiras(int phiras)
            {
                _phiras = phiras;
            }


            int Players::getThystame() const
            {
                return _thystame;
            }

            void Players::setThystame(int thystame)
            {
                _thystame = thystame;
            }


            int Players::getFood() const
            {
                return _food;
            }

            void Players::setFood(int food)
            {
                _food = food;
            }


            Color Players::getTeam() const
            {
                return _team;
            }
        }
    }
}