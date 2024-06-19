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
            iss >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
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
            iss >> teamName;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
                return;
            }
            std::cout << "Team name: " << teamName << std::endl;
            // todo
        }

        void Commands::handleCommandPnw(const std::string& responseValue)
        {
            int playerId, x, y, orientation, level;
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> orientation >> level >> teamName;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
                return;
            }

            std::cout << "New player: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", Orientation: " << orientation << ", Level: " << level
                    << ", Team: " << teamName << std::endl;
            //todo handle level, teamname and color
            this->_ressources->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(playerId, x, y, teamName));
        }

        void Commands::handleCommandPpo(const std::string& responseValue)
        {
            int playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
                return;
            }

            std::cout << "Player position: #" << playerId << ", X: " << x << ", Y: " << y << std::endl;
            this->_ressources->getPlayerFromId(playerId)->setX(x);
            this->_ressources->getPlayerFromId(playerId)->setY(y);
            // todo virify this
        }

        void Commands::handleCommandPlv(const std::string& responseValue)
        {
            int playerId, level;
            std::istringstream iss(responseValue);
            iss >> playerId >> level;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
                return;
            }

            std::cout << "Player level: #" << playerId << ", Level: " << level << std::endl;
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setLevel(level);
            // todo
        }

        void Commands::handleCommandPin(const std::string& responseValue)
        {
            int playerId, x, y, q0, q1, q2, q3, q4, q5, q6;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
            if (iss.fail() || !iss.eof()) {
                handleCommandSuc(responseValue);
                return;
            }

            std::cout << "Player inventory: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", q0: " << q0 << ", q1: " << q1 << ", q2: " << q2
                    << ", q3: " << q3 << ", q4: " << q4 << ", q5: " << q5
                    << ", q6: " << q6 << std::endl;
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
            iss >> playerId;

            std::cout << "Player expelled: #" << playerId << std::endl;
            // todo
        }

        void Commands::handleCommandPbc(const std::string& responseValue)
        {
            int playerId;
            std::string message;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            std::getline(iss, message);

            std::cout << "Broadcast from player #" << playerId << ": " << message << std::endl;
            // todo
        }

        void Commands::handleCommandPic(const std::string& responseValue)
        {
            std::cout << responseValue << std::endl;
            //todo
        }

        void Commands::handleCommandPie(const std::string& responseValue)
        {
            int x, y;
            std::string result;
            std::istringstream iss(responseValue);
            iss >> x >> y >> result;

            std::cout << "Incantation ended at (" << x << ", " << y << ") with result: " << result << std::endl;
            // todo
        }

        void Commands::handleCommandPfk(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId;

            std::cout << "Player #" << playerId << " laid an egg." << std::endl;
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            this->_ressources->getTileFromPos(playerX, playerY)->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(0, playerX, playerY, this->_ressources->getPlayerFromId(playerId)->getTeam()));
        }

        void Commands::handleCommandPdr(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum;
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " dropped resource #" << resourceNum << std::endl;
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
            iss >> playerId >> resourceNum;
            int playerX = this->_ressources->getPlayerFromId(playerId)->getX();
            int playerY = this->_ressources->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " took resource #" << resourceNum << std::endl;
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
            iss >> playerId;

            std::cout << "Player #" << playerId << " has died." << std::endl;
            _ressources->logs.push_back(std::make_tuple("Player #" + std::to_string(playerId) + " just died.", "Server", "Server"));
            // todo
        }

        void Commands::handleCommandEnw(const std::string& responseValue)
        {
            int eggNum, playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> eggNum >> playerId >> x >> y;

            std::cout << "New egg: #" << eggNum << " laid by player #" << playerId << " at (" << x << ", " << y << ")" << std::endl;
            // todo
        }

        void Commands::handleCommandEbo(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " hatched." << std::endl;
            // todo
        }

        void Commands::handleCommandEdi(const std::string& responseValue)
        {
            std::cout << "Server broadcasted: " << responseValue << std::endl;
            // todo
        }

        void Commands::handleCommandSgt(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " died." << std::endl;
            // todo
        }

        void Commands::handleCommandSst(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Current time unit: " << timeUnit << std::endl;
            // todo
        }

        void Commands::handleCommandSeg(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Time unit set to: " << timeUnit << std::endl;
            // todo
        }

        void Commands::handleCommandSmg(const std::string& responseValue)
        {
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> teamName;

            std::cout << "Game ended. Winning team: " << teamName << std::endl;
            // todo
        }

        void Commands::handleCommandSuc([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "Unknown command" << std::endl;
        }

        void Commands::handleCommandSbp([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "command parametre" << std::endl;
        }

        std::vector<std::string> Commands::split(const std::string &str, const std::string &delim)
        {
            if (str.empty())
                return {};
            if (str.find(delim) == std::string::npos)
                return {str};

            std::vector<std::string> tokens;
            std::size_t start = 0;

            while (true) {
                std::size_t end = str.find(delim, start);
                if (end == std::string::npos) {
                    tokens.push_back(str.substr(start));
                    break;
                }
                tokens.push_back(str.substr(start, end - start));
                start = end + delim.size();
                while (delim.find(str[start]) != std::string::npos && start < str.size())
                    start++;
            }
            return tokens;
        }

        std::string Commands::clean(const std::string &str)
        {
            std::string cleaned = str;
            cleaned.erase(std::remove(cleaned.begin(), cleaned.end(), '\n'), cleaned.end());
            cleaned.erase(std::remove(cleaned.begin(), cleaned.end(), '\r'), cleaned.end());
            cleaned.erase(std::remove(cleaned.begin(), cleaned.end(), '\t'), cleaned.end());
            for (size_t i = 0; i < cleaned.size(); i++)
                if (cleaned[i] == ' ' && cleaned[i + 1] == ' ')
                    cleaned.erase(i, 1);
            for (size_t i = 0; cleaned[i] == ' ';)
                cleaned.erase(i, 1);
            for (size_t i = cleaned.size() - 1; cleaned[i] == ' '; i--)
                cleaned.erase(i, 1);
            return cleaned;
        }
    }
}