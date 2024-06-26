/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Commands
*/

#include "Commands.hpp"

namespace Zappy {
    namespace Server {
        Commands::Commands()
        {
            this->_ressources = nullptr;
        }

        std::shared_ptr<Zappy::GUI::Ressources::Ressources> Commands::getRessources()
        {
            return this->_ressources;
        }

        std::shared_ptr<Zappy::Server::SharedMemory> Commands::getSharedMemory()
        {
            return this->_sharedMemory;
        }

        void Commands::setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources)
        {
            this->_ressources = ressources;
        }

        void Commands::setSharedMemory(std::shared_ptr<Zappy::Server::SharedMemory> sharedMemory)
        {
            this->_sharedMemory = sharedMemory;
        }

        void Commands::handleCommandMsz(const std::string& responseValue)
        {
            std::regex regex("msz ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                if (_ressources->mapSet) return;
                int width = std::stoi(match[1]);
                int height = std::stoi(match[2]);

                for (int i = 0; i < height; i++) {
                    std::vector<std::shared_ptr<Zappy::GUI::Ressources::TileRessources>> line;
                    for (int j = 0; j < width; j++) {
                        std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tile = std::make_shared<Zappy::GUI::Ressources::TileRessources>(i, j);
                        line.push_back(tile);
                    }
                    _ressources->tileRessources.push_back(line);
                }
                _ressources->mapSet = true;
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandBct(const std::string& responseValue)
        {
            std::regex regex("bct ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int x = std::stoi(match[1]);
                int y = std::stoi(match[2]);
                int q0 = std::stoi(match[3]);
                int q1 = std::stoi(match[4]);
                int q2 = std::stoi(match[5]);
                int q3 = std::stoi(match[6]);
                int q4 = std::stoi(match[7]);
                int q5 = std::stoi(match[8]);
                int q6 = std::stoi(match[9]);

                auto tile = this->_ressources->getTileFromPos(x, y);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }
                tile->setFood(q0);
                tile->setLinemate(q1);
                tile->setDeraumere(q2);
                tile->setSibur(q3);
                tile->setMendiane(q4);
                tile->setPhiras(q5);
                tile->setThystame(q6);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandTna(const std::string& responseValue)
        {
            std::regex regex("tna ([a-zA-Z0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                std::string teamName = match[1];
                this->_ressources->addTeam(teamName);
                _ressources->logs.push_back(std::make_tuple("Team " + teamName + " just added.", "Server", "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPnw(const std::string& responseValue)
        {
            std::regex regex("pnw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([a-zA-Z0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int x = std::stoi(match[2]);
                int y = std::stoi(match[3]);
                int orientation = std::stoi(match[4]);
                int level = std::stoi(match[5]);
                std::string teamName = match[6];

                if (orientation > 4 || orientation < 1 || level < 1 || level > 8) {
                    handleCommandSbp(responseValue);
                    return;
                }

                auto player = std::make_shared<Zappy::GUI::Ressources::Players>(playerId, x, y, teamName);
                player->setLvl(level);
                _ressources->addPlayer(player);
                _ressources->logs.push_back(std::make_tuple("Player #" + std::to_string(playerId) + " just join the " + teamName + "." , "Server", "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPpo(const std::string& responseValue)
        {
            std::regex regex("ppo ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int x = std::stoi(match[2]);
                int y = std::stoi(match[3]);
                int orientation = std::stoi(match[4]);

                if (orientation > 4 || orientation < 1) {
                    handleCommandSbp(responseValue);
                    return;
                }

                auto player = _ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                player->setX(x);
                player->setY(y);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPlv(const std::string& responseValue)
        {
            std::regex regex("plv ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int level = std::stoi(match[2]);

                if (level < 1 || level > 8) {
                    handleCommandSbp(responseValue);
                    return;
                }

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                player->setLvl(level);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPin(const std::string& responseValue)
        {
            std::regex regex("pin ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int x = std::stoi(match[2]);
                int y = std::stoi(match[3]);
                int q0 = std::stoi(match[4]);
                int q1 = std::stoi(match[5]);
                int q2 = std::stoi(match[6]);
                int q3 = std::stoi(match[7]);
                int q4 = std::stoi(match[8]);
                int q5 = std::stoi(match[9]);
                int q6 = std::stoi(match[10]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                player->setX(x);
                player->setY(y);
                player->setFood(q0);
                player->setLinemate(q1);
                player->setDeraumere(q2);
                player->setSibur(q3);
                player->setMendiane(q4);
                player->setPhiras(q5);
                player->setThystame(q6);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPex(const std::string& responseValue)
        {
            std::regex regex("pex ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int playerX = player->getX();
                int playerY = player->getY();
                auto tile = this->_ressources->getTileFromPos(playerX, playerY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                std::vector<std::pair<int, int>> directions;
                for (int i = -1; i < 1; i++) {
                    int x = tileX + i;
                    x = (x < 0) ? x + _ressources->tileRessources.size() : x;
                    x = (x >= (int)_ressources->tileRessources.size()) ? x - _ressources->tileRessources.size() : x;

                    for (int j = -1; j < 1; j++) {
                        int y = tileY + j;
                        y = (y < 0) ? y + _ressources->tileRessources[0].size() : y;
                        y = (y >= (int)_ressources->tileRessources[0].size()) ? y - _ressources->tileRessources[0].size() : y;

                        directions.push_back(std::make_pair(x, y));
                    }
                }

                for (auto &direction : directions)
                    _sharedMemory->addCommand("bct " + std::to_string(direction.first) + " " + std::to_string(direction.second));
                std::string msg = "I don't want anyone here !";
                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPbc(const std::string& responseValue)
        {
            std::regex regex("pbc ([0-9]+) (.+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                std::string message = match[2];

                auto player = _ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(message, name, "Global"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPic(const std::string& responseValue)
        {
            std::regex regex("pic ([0-9]+) ([0-9]+) ([0-9]+) (.+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int x = std::stoi(match[1]);
                int y = std::stoi(match[2]);
                int level = std::stoi(match[3]);

                std::vector<int> playersId;
                std::istringstream iss(match[4]);
                while (!iss.eof()) {
                    int playerId;
                    iss >> playerId;
                    playersId.push_back(playerId);
                }
                if (iss.fail()) {
                    handleCommandSbp(responseValue);
                    return;
                }

                std::string msg = "Incantation of level " + std::to_string(level) + " at Tile[" + std::to_string(x) + "][" + std::to_string(y) + "] just started by:\n";
                for (auto &playerId : playersId) {
                    msg += "- Player #" + std::to_string(playerId);
                    if (playerId != playersId.back())
                        msg += "\n";
                }
                std::string name = "Server";
                _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPie(const std::string& responseValue)
        {
            std::regex regex("pie ([0-9]+) ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int x = std::stoi(match[1]);
                int y = std::stoi(match[2]);
                int result = std::stoi(match[3]);

                std::string msg = "Incantation at Tile[" + std::to_string(x) + "][" + std::to_string(y) + "] has " + (result == 0 ? "failed" : "succeed");
                msg += ".";
                if (result != 0) msg += " All players on the tile just up their level to " + std::to_string(result) + ".";
                std::string name = "Server";
                _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPfk(const std::string& responseValue)
        {
            std::regex regex("pfk ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int playerX = player->getX();
                int playerY = player->getY();
                auto tile = this->_ressources->getTileFromPos(playerX, playerY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                std::ostringstream commandStream;
                commandStream << "bct " << tileX << " " << tileY;
                const std::string command = commandStream.str();
                _sharedMemory->addCommand(command);

                std::string msg = "I let that here...";
                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPdr(const std::string& responseValue)
        {
            std::regex regex ("pdr ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int resourceNum = std::stoi(match[2]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int playerX = player->getX();
                int playerY = player->getY();
                auto tile = this->_ressources->getTileFromPos(playerX, playerY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                if (resourceNum < 0 || resourceNum > 6) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                _sharedMemory->addCommand("pin " + std::to_string(playerId));
                _sharedMemory->addCommand("bct " + std::to_string(tileX) + " " + std::to_string(tileY));
                std::string msg = "I don't need that ";
                msg += resourceNum == 0 ? "food" : resourceNum == 1 ? "linemate" : resourceNum == 2 ? "deraumere" : resourceNum == 3 ? "sibur" : resourceNum == 4 ? "mendiane" : resourceNum == 5 ? "phiras" : "thystame";
                msg += " anymore...";
                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPgt(const std::string& responseValue)
        {
            std::regex regex ("pgt ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);
                int resourceNum = std::stoi(match[2]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int playerX = player->getX();
                int playerY = player->getY();
                auto tile = this->_ressources->getTileFromPos(playerX, playerY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                if (resourceNum < 0 || resourceNum > 6) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                _sharedMemory->addCommand("pin " + std::to_string(playerId));
                _sharedMemory->addCommand("bct " + std::to_string(tileX) + " " + std::to_string(tileY));
                std::string msg = "I need that ";
                msg += resourceNum == 0 ? "food" : resourceNum == 1 ? "linemate" : resourceNum == 2 ? "deraumere" : resourceNum == 3 ? "sibur" : resourceNum == 4 ? "mendiane" : resourceNum == 5 ? "phiras" : "thystame";
                msg += ".";
                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandPdi(const std::string& responseValue)
        {
            std::regex regex("pdi ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int playerId = std::stoi(match[1]);

                auto player = this->_ressources->getPlayerFromId(playerId);
                if (player == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int playerX = player->getX();
                int playerY = player->getY();
                auto tile = this->_ressources->getTileFromPos(playerX, playerY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                _sharedMemory->addCommand("bct " + std::to_string(tileX) + " " + std::to_string(tileY));
                std::string msg = "My time has come...";
                std::string name = "Player #" + std::to_string(playerId);
                _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
                _ressources->removePlayer(playerId);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandEnw(const std::string& responseValue)
        {
            std::regex regex("enw ([0-9]+) (-?[0-9]+) ([0-9]+) ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int eggNum = std::stoi(match[1]);
                int playerId = std::stoi(match[2]);
                int x = std::stoi(match[3]);
                int y = std::stoi(match[4]);

                std::string name = "Server";
                std::string msg = "Egg #" + std::to_string(eggNum) + " just ";
                auto player = _ressources->getPlayerFromId(playerId);
                std::string team = (player == nullptr) ? "?" : player->getTeam();

                msg += (player == nullptr) ? "appear" : "laid by Player #" + std::to_string(playerId);
                msg += " at Tile[" + std::to_string(x) + "][" + std::to_string(y) + "]";
                _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(eggNum, x, y, team));
                _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandEbo(const std::string& responseValue)
        {
            std::regex regex("ebo ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int eggNum = std::stoi(match[1]);

                auto egg = _ressources->getEggFromId(eggNum);
                if (egg == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int eggX = egg->getX();
                int eggY = egg->getY();
                auto tile = this->_ressources->getTileFromPos(eggX, eggY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                _sharedMemory->addCommand("bct " + std::to_string(tileX) + " " + std::to_string(tileY));
                std::string msg = "Egg #" + std::to_string(eggNum) + " have been replaced by a player.";
                std::string name = "Server";
                _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
                _ressources->removeEgg(eggNum);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandEdi(const std::string& responseValue)
        {
            std::regex regex("edi ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int eggNum = std::stoi(match[1]);

                auto egg = _ressources->getEggFromId(eggNum);
                if (egg == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int eggX = egg->getX();
                int eggY = egg->getY();
                auto tile = this->_ressources->getTileFromPos(eggX, eggY);
                if (tile == nullptr) {
                    handleCommandSbp(responseValue);
                    return;
                }

                int tileX = tile->getX();
                int tileY = tile->getY();
                _sharedMemory->addCommand("bct " + std::to_string(tileX) + " " + std::to_string(tileY));
                std::string msg = "Egg #" + std::to_string(eggNum) + " just died.";
                std::string name = "Server";
                _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
                _ressources->removeEgg(eggNum);
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandSgt(const std::string& responseValue)
        {
            std::regex regex("sgt ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                int timeUnit = std::stoi(match[1]);
                _ressources->logs.push_back(std::make_tuple("Time unit set to " + std::to_string(timeUnit), "Server", "Server"));
                _ressources->frequency = timeUnit;
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandSst(const std::string& responseValue)
        {
            std::regex regex("sst ([0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                _ressources->frequency = std::stoi(match[1]);
                _ressources->logs.push_back(std::make_tuple("Time unit set to " + std::to_string(_ressources->frequency), "Server", "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandSeg(const std::string& responseValue)
        {
            std::regex regex("seg ([a-zA-Z0-9]+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                std::string teamName = match[1];
                _ressources->logs.push_back(std::make_tuple("Team " + teamName + " won the game.", "Server", "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandSmg(const std::string& responseValue)
        {
            std::regex regex("smg (.+)");
            std::smatch match;

            if (std::regex_search(responseValue, match, regex)) {
                std::string message = match[1];
                _ressources->logs.push_back(std::make_tuple(message, "Server", "Server"));
            } else {
                handleCommandSbp(responseValue);
            }
        }

        void Commands::handleCommandSuc([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "Unknown command" << std::endl;
            std::cerr << "Unknown command: [" << responseValue << "]" << std::endl;
        }

        void Commands::handleCommandSbp([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "command parameters" << std::endl;
            std::cerr << "Error in command parameters: [" << responseValue << "]" << std::endl;
        }
    }
}