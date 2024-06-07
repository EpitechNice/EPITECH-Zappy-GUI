/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Ressources
*/

#include "Ressources.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            Ressources *Ressources::get()
            {
                static Ressources ressources;
                return &ressources;
            }

            Ressources::Ressources()
            {
                tileRessources = std::vector<std::vector<std::shared_ptr<TileRessources>>>();
                players = std::vector<std::shared_ptr<Players>>();
            }

            void Ressources::addPlayer(std::shared_ptr<Players> player)
            {
                players.push_back(player);
            }

            void Ressources::setPlayerOnMap()
            {
                for (auto &line: tileRessources)
                    for (auto &tile: line)
                        tile->clearPlayers();
                for (auto &player : players)
                    tileRessources[player->getX()][player->getY()]->addPlayer(player);
            }

            std::shared_ptr<Players> Ressources::getPlayerFromId(int id) const
            {
                for (auto &player : players)
                    if (player->getId() == id)
                        return player;
                return nullptr;
            }
        }
    }
}