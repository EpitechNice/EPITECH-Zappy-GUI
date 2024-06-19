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
            this->_ressources->getTileFromPos(x, y)->setFood(q0);
            this->_ressources->getTileFromPos(x, y)->setLinemate(q1);
            this->_ressources->getTileFromPos(x, y)->setDeraumere(q2);
            this->_ressources->getTileFromPos(x, y)->setSibur(q3);
            this->_ressources->getTileFromPos(x, y)->setMendiane(q4);
            this->_ressources->getTileFromPos(x, y)->setPhiras(q5);
            this->_ressources->getTileFromPos(x, y)->setThystame(q6);
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
            //todo handle level, teamname and color
            this->_ressources->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(playerId, x, y, teamName));
        }

        void Commands::handleCommandPpo(const std::string& responseValue)
        {
            int playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
            this->_ressources->getPlayerFromId(playerId)->setX(x);
            this->_ressources->getPlayerFromId(playerId)->setY(y);
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
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setLevel(level);
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
            // this->_ressources->getPlayerFromId(playerId)->setX(x);
            // this->_ressources->getPlayerFromId(playerId)->setY(y);
            this->_ressources->getPlayerFromId(playerId)->setFood(q0);
            this->_ressources->getPlayerFromId(playerId)->setLinemate(q1);
            this->_ressources->getPlayerFromId(playerId)->setDeraumere(q2);
            this->_ressources->getPlayerFromId(playerId)->setSibur(q3);
            this->_ressources->getPlayerFromId(playerId)->setMendiane(q4);
            this->_ressources->getPlayerFromId(playerId)->setPhiras(q5);
            this->_ressources->getPlayerFromId(playerId)->setThystame(q6);
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
        }

        void Commands::handleCommandPic(const std::string& responseValue)
        {
            //todo
            // if (iss.fail() || !iss.eof()) {
            //     handleCommandSbp(responseValue);
            //     return;
            // }
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
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            this->_ressources->getTileFromPos(playerX, playerY)->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(0, playerX, playerY, this->_ressources->getPlayerFromId(playerId)->getTeam()));
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
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            int value;

            if (resourceNum == 0) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getFood();
                this->_ressources->getTileFromPos(playerX, playerY)->setFood(value + 1);
            } else if (resourceNum == 1) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getLinemate();
                this->_ressources->getTileFromPos(playerX, playerY)->setLinemate(value + 1);
            } else if (resourceNum == 2) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getDeraumere();
                this->_ressources->getTileFromPos(playerX, playerY)->setDeraumere(value + 1);
            } else if (resourceNum == 3) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getSibur();
                this->_ressources->getTileFromPos(playerX, playerY)->setSibur(value + 1);
            } else if (resourceNum == 4) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getMendiane();
                this->_ressources->getTileFromPos(playerX, playerY)->setMendiane(value + 1);
            } else if (resourceNum == 5) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getPhiras();
                this->_ressources->getTileFromPos(playerX, playerY)->setPhiras(value + 1);
            } else if (resourceNum == 6) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getThystame();
                this->_ressources->getTileFromPos(playerX, playerY)->setThystame(value + 1);
            }
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
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            int value;

            if (resourceNum == 0) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getFood();
                this->_ressources->getTileFromPos(playerX, playerY)->setFood(value - 1);
            } else if (resourceNum == 1) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getLinemate();
                this->_ressources->getTileFromPos(playerX, playerY)->setLinemate(value - 1);
            } else if (resourceNum == 2) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getDeraumere();
                this->_ressources->getTileFromPos(playerX, playerY)->setDeraumere(value - 1);
            } else if (resourceNum == 3) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getSibur();
                this->_ressources->getTileFromPos(playerX, playerY)->setSibur(value - 1);
            } else if (resourceNum == 4) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getMendiane();
                this->_ressources->getTileFromPos(playerX, playerY)->setMendiane(value - 1);
            } else if (resourceNum == 5) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getPhiras();
                this->_ressources->getTileFromPos(playerX, playerY)->setPhiras(value - 1);
            } else if (resourceNum == 6) {
                value = this->_ressources->getTileFromPos(playerX, playerY)->getThystame();
                this->_ressources->getTileFromPos(playerX, playerY)->setThystame(value - 1);
            }
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
        }

        void Commands::handleCommandEdi(const std::string& responseValue)
        {
            // if (iss.fail() || !iss.eof()) {
            //     handleCommandSbp(responseValue);
            //     return;
            // }
        }

        void Commands::handleCommandSgt(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
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
        }

        void Commands::handleCommandSeg(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
        }

        void Commands::handleCommandSmg(const std::string& responseValue)
        {
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> teamName >> std::ws;
            if (iss.fail() || !iss.eof()) {
                handleCommandSbp(responseValue);
                return;
            }
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