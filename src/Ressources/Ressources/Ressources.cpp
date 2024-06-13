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

            std::pair<int, int> Ressources::getMapDimensions() const
            {
                if (!mapSet) return std::make_pair(0, 0);
                return std::make_pair(tileRessources.size(), tileRessources[0].size());
            }
        }
    }
}