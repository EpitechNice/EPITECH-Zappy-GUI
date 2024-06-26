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
                eggs = std::vector<std::shared_ptr<Eggs>>();
                teamsColor = std::unordered_map<std::string, Color>();
                mapSet = false;
                logs = std::vector<std::tuple<std::string, std::string, std::string>>();

                teamsColor["?"] = (Color){255, 255, 255, 255};
            }

            void Ressources::addPlayer(std::shared_ptr<Players> player)
            {
                players.push_back(player);
                std::string team = player->getTeam();
                addTeam(team);
            }

            void Ressources::addTeam(std::string teamName)
            {
                if (teamsColor.find(teamName) != teamsColor.end()) return;
                unsigned char r = rand() % 256;
                unsigned char g = rand() % 256;
                unsigned char b = rand() % 256;
                Color color = (Color){r, g, b, 255};
                bool isUnique = false;
                while (!isUnique) {
                    isUnique = true;
                    for (auto &teamColor : teamsColor) {
                        if (teamColor.second.r == r && teamColor.second.g == g && teamColor.second.b == b) {
                            isUnique = false;
                            break;
                        }
                    }
                    if (!isUnique) {
                        r = rand() % 256;
                        g = rand() % 256;
                        b = rand() % 256;
                        color = (Color){r, g, b, 255};
                    }
                }
                teamsColor[teamName] = color;
            }

            void Ressources::removePlayer(int id)
            {
                for (auto it = players.begin(); it != players.end(); it++) {
                    if ((*it)->getId() == id) {
                        players.erase(it);
                        setPlayerOnMap();
                        break;
                    }
                }
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

            std::shared_ptr<Eggs> Ressources::getEggFromId(int id) const
            {
                for (auto &egg : eggs)
                    if (egg->getId() == id)
                        return egg;
                return nullptr;
            }

            std::pair<int, int> Ressources::getMapDimensions() const
            {
                if (!mapSet) return std::make_pair(0, 0);
                return std::make_pair(tileRessources.size(), tileRessources[0].size());
            }

            std::shared_ptr<TileRessources> Ressources::getTileFromPos(int posX, int posY) const
            {
                if (posX < 0 || posY < 0 || posX >= (int)tileRessources.size() || posY >= (int)tileRessources[0].size())
                    return nullptr;
                return tileRessources[posX][posY];
            }

            void Ressources::addEgg(std::shared_ptr<Eggs> egg)
            {
                eggs.push_back(egg);
            }

            void Ressources::removeEgg(int id)
            {
                for (auto it = eggs.begin(); it != eggs.end(); it++) {
                    if ((*it)->getId() == id) {
                        eggs.erase(it);
                        setEggOnMap();
                        break;
                    }
                }
            }

            void Ressources::setEggOnMap()
            {
                for (auto &line: tileRessources)
                    for (auto &tile: line)
                        tile->clearEggs();
                for (auto &egg : eggs)
                    tileRessources[egg->getX()][egg->getY()]->addEgg(egg);
            }
        }
    }
}