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

        void Commands::setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources)
        {
            this->_ressources = ressources;
        }

        void Commands::setSharedMemory(std::shared_ptr<Zappy::Server::SharedMemory> ressources)
        {
            this->_sharedMemory = ressources;
        }

        void Commands::handleCommandMsz(const std::string& responseValue)
        {
            int _heightWorld, _widthWorld;
            std::istringstream iss(responseValue);
            iss >> _heightWorld >> _widthWorld;
        }

        void Commands::handleCommandBct(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            int x, y, q0, q1, q2, q3, q4, q5, q6;
            iss >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6 >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            auto tile = this->_ressources->getTileFromPos(x, y);
            if (tile == 0)
                return;
            tile->setFood(q0);
            tile->setLinemate(q1);
            tile->setDeraumere(q2);
            tile->setSibur(q3);
            tile->setMendiane(q4);
            tile->setPhiras(q5);
            tile->setThystame(q6);
        }

        void Commands::handleCommandTna(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            std::string teamName;
            iss >> teamName >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            this->_ressources->addTeam(teamName);
            _ressources->logs.push_back(std::make_tuple("Team " + teamName + " just added.", "Server", "Server"));
        }

        void Commands::handleCommandPnw(const std::string& responseValue)
        {
            int playerId, x, y, orientation, level;
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> orientation >> level >> teamName >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            if (orientation > 4){
                handleCommandSbp(responseValue);
                return;
            }
            auto player = std::make_shared<Zappy::GUI::Ressources::Players>(playerId, x, y, teamName);
            player->setLvl(level);
            this->_ressources->addPlayer(player);
            _ressources->logs.push_back(std::make_tuple("Player # " + std::to_string(playerId) + " just added.", "Server", "Server"));
        }

        void Commands::handleCommandPpo(const std::string& responseValue)
        {
            int playerId, x, y, orientation;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> orientation >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            if (orientation > 4){
                handleCommandSbp(responseValue);
                return;
            }
            auto player = this->_ressources->getPlayerFromId(playerId);
            if (player == 0)
                return;
            player->setX(x);
            player->setY(y);
        }

        void Commands::handleCommandPlv(const std::string& responseValue)
        {
            int playerId, level;
            std::istringstream iss(responseValue);
            iss >> playerId >> level >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            auto player = this->_ressources->getPlayerFromId(playerId);
            if (player == 0)
                return;
            player->setLvl(level);
        }

        void Commands::handleCommandPin(const std::string& responseValue)
        {
            int playerId, x, y, q0, q1, q2, q3, q4, q5, q6;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6 >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            auto player = _ressources->getPlayerFromId(playerId);
            if (player == 0)
                return;
            player->setX(x);
            player->setY(y);
            player->setFood(q0);
            player->setLinemate(q1);
            player->setDeraumere(q2);
            player->setSibur(q3);
            player->setMendiane(q4);
            player->setPhiras(q5);
            player->setThystame(q6);
        }

        void Commands::handleCommandPex(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::string msg = "I don't want anyone here !";
            std::string name = "Player #" + std::to_string(playerId);
            _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
        }

        void Commands::handleCommandPbc(const std::string& responseValue)
        {
            int playerId;
            std::string message;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::getline(iss, message);
            std::string name = "Player #" + std::to_string(playerId);
            _ressources->logs.push_back(std::make_tuple(message, name, "Global"));
        }

        void Commands::handleCommandPic(const std::string& responseValue)
        {
            int x, y, level;
            std::vector<int> playersId;
            std::istringstream iss(responseValue);
            iss >> x >> y >> level;
            while (!iss.eof()) {
                int playerId;
                iss >> playerId;
                playersId.push_back(playerId);
            }
            if (iss.fail()) {
                handleCommandSbp(responseValue);
                return;
            }

            std::string msg = "Incantation at " + std::to_string(x) + " " + std::to_string(y) + " has started by ";
            for (auto &playerId : playersId)
                msg += "Player #" + std::to_string(playerId) + " ";
            std::string name = "Server";
            _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
        }

        void Commands::handleCommandPie(const std::string& responseValue)
        {
            int x, y;
            std::string result;
            std::istringstream iss(responseValue);
            iss >> x >> y >> result >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::string msg = "Incantation at " + std::to_string(x) + " " + std::to_string(y) + " has " + (result == "ko" ? "failed" : "succeed");
            std::string name = "Server";
            _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
        }

        void Commands::handleCommandPfk(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::string msg = "I have laid an egg !";
            std::string name = "Player #" + std::to_string(playerId);
            _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
        }

        void Commands::handleCommandPdr(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            auto player = this->_ressources->getPlayerFromId(playerId);
            if (player == 0)
                return;
            int playerX = player->getX();
            int playerY = player->getY();
            auto tile = this->_ressources->getTileFromPos(playerX, playerY);
            if (tile == 0)
                return;
            int tileX = tile->getX();
            int tileY = tile->getY();
            std::ostringstream commandStream;
            commandStream << "bct " << tileX << " " << tileY << "\r\n";
            const std::string command = commandStream.str();
            _sharedMemory->addCommand(command);
            std::ostringstream commandStream2;
            commandStream2 << "pin " << playerId << "\r\n";
            const std::string command2 = commandStream2.str();
            _sharedMemory->addCommand(command2);

            std::string msg = "I drop that :" + resourceNum == 0 ? "food" : resourceNum == 1 ? "linemate" : resourceNum == 2 ? "deraumere" : resourceNum == 3 ? "sibur" : resourceNum == 4 ? "mendiane" : resourceNum == 5 ? "phiras" : "thystame";
            std::string name = "Player #" + std::to_string(playerId);
            _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
        }

        void Commands::handleCommandPgt(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }

            auto player = this->_ressources->getPlayerFromId(playerId);
            if (player == 0)
                return;
            int playerX = player->getX();
            int playerY = player->getY();
            auto tile = this->_ressources->getTileFromPos(playerX, playerY);
            if (tile == 0)
                return;
            int tileX = tile->getX();
            int tileY = tile->getY();
            std::ostringstream commandStream;
            commandStream << "bct " << tileX << " " << tileY << "\r\n";
            const std::string command = commandStream.str();
            _sharedMemory->addCommand(command);
            std::ostringstream commandStream2;
            commandStream2 << "pin " << playerId << "\r\n";
            const std::string command2 = commandStream2.str();
            _sharedMemory->addCommand(command2);

            std::string msg = "I take that :" + resourceNum == 0 ? "food" : resourceNum == 1 ? "linemate" : resourceNum == 2 ? "deraumere" : resourceNum == 3 ? "sibur" : resourceNum == 4 ? "mendiane" : resourceNum == 5 ? "phiras" : "thystame";
            std::string name = "Player #" + std::to_string(playerId);
            _ressources->logs.push_back(std::make_tuple(msg, name, "Global"));
        }

        void Commands::handleCommandPdi(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple("Player #" + std::to_string(playerId) + " just died.", "Server", "Server"));
        }

        void Commands::handleCommandEnw(const std::string& responseValue)
        {
            int eggNum, playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> eggNum >> playerId >> x >> y >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::string msg = "Egg #" + std::to_string(eggNum) + " just laid by Player #" + std::to_string(playerId);
            std::string name = "Server";
            _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(eggNum, x, y, _ressources->getPlayerFromId(playerId)->getTeam()));
        }

        void Commands::handleCommandEbo(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple("Egg #" + std::to_string(eggNum) + " just hatched.", "Server", "Server"));
            _ressources->removeEgg(eggNum);
        }

        void Commands::handleCommandEdi(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple("Egg #" + std::to_string(eggNum) + " just died.", "Server", "Server"));
            _ressources->removeEgg(eggNum);
        }

        void Commands::handleCommandSgt(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple("Time unit set to " + std::to_string(timeUnit), "Server", "Server"));
        }

        void Commands::handleCommandSst(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple("Time unit set to " + std::to_string(timeUnit), "Server", "Server"));
        }

        void Commands::handleCommandSeg(const std::string& responseValue)
        {
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> teamName >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            std::string msg = "Team " + teamName + " won the game.";
            std::string name = "Team " + teamName;
            _ressources->logs.push_back(std::make_tuple(msg, name, "Server"));
        }

        void Commands::handleCommandSmg(const std::string& responseValue)
        {
            std::string msg;
            std::istringstream iss(responseValue);
            iss >> msg >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            _ressources->logs.push_back(std::make_tuple(msg, "Server", "Server"));
        }

        void Commands::handleCommandSuc([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "Unknown command" << std::endl;
        }

        void Commands::handleCommandSbp([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "command parametre" << std::endl;
        }
    }
}