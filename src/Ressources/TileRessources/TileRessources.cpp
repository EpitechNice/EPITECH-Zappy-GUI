/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TileRessources
*/

#include "TileRessources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            TileRessources::TileRessources(int x, int y)
            {
                _x = x;
                _y = y;
                _food = 0;
                _linemate = 0;
                _deraumere = 0;
                _sibur = 0;
                _mendiane = 0;
                _phiras = 0;
                _thystame = 0;
                _players = std::vector<std::shared_ptr<Players>>();
                _eggs = std::vector<std::shared_ptr<Eggs>>();
            }

            int TileRessources::getX() const
            {
                return _x;
            }

            int TileRessources::getY() const
            {
                return _y;
            }


            int TileRessources::getFood() const
            {
                return _food;
            }

            void TileRessources::setFood(int food)
            {
                _food = food;
            }

            bool TileRessources::hasFood() const
            {
                return _food > 0;
            }


            int TileRessources::getLinemate() const
            {
                return _linemate;
            }

            void TileRessources::setLinemate(int linemate)
            {
                _linemate = linemate;
            }

            bool TileRessources::hasLinemate() const
            {
                return _linemate > 0;
            }


            int TileRessources::getDeraumere() const
            {
                return _deraumere;
            }

            void TileRessources::setDeraumere(int deraumere)
            {
                _deraumere = deraumere;
            }

            bool TileRessources::hasDeraumere() const
            {
                return _deraumere > 0;
            }


            int TileRessources::getSibur() const
            {
                return _sibur;
            }

            void TileRessources::setSibur(int sibur)
            {
                _sibur = sibur;
            }

            bool TileRessources::hasSibur() const
            {
                return _sibur > 0;
            }


            int TileRessources::getMendiane() const
            {
                return _mendiane;
            }

            void TileRessources::setMendiane(int mendiane)
            {
                _mendiane = mendiane;
            }

            bool TileRessources::hasMendiane() const
            {
                return _mendiane > 0;
            }


            int TileRessources::getPhiras() const
            {
                return _phiras;
            }

            void TileRessources::setPhiras(int phiras)
            {
                _phiras = phiras;
            }

            bool TileRessources::hasPhiras() const
            {
                return _phiras > 0;
            }


            int TileRessources::getThystame() const
            {
                return _thystame;
            }

            void TileRessources::setThystame(int thystame)
            {
                _thystame = thystame;
            }

            bool TileRessources::hasThystame() const
            {
                return _thystame > 0;
            }


            std::vector<std::shared_ptr<Players>> TileRessources::getPlayers() const
            {
                return _players;
            }

            void TileRessources::clearPlayers()
            {
                _players.clear();
            }

            void TileRessources::addPlayer(std::shared_ptr<Players> player)
            {
                _players.push_back(player);
            }

            bool TileRessources::hasPlayers() const
            {
                return !_players.empty();
            }


            std::vector<std::shared_ptr<Eggs>> TileRessources::getEggs() const
            {
                return _eggs;
            }

            void TileRessources::clearEggs()
            {
                _eggs.clear();
            }

            void TileRessources::addEgg(std::shared_ptr<Eggs> egg)
            {
                _eggs.push_back(egg);
            }

            bool TileRessources::hasEggs() const
            {
                return !_eggs.empty();
            }
        }
    }
}