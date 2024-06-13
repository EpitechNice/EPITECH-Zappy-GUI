/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Commands
*/

#include "Commands.hpp"

namespace Zappy {
    namespace Server {
        Commands::Commands(){}

        void Commands::handleCommandMsz(const std::string& responseValue)
        {
            int _heightWorld, _widthWorld;
            std::istringstream iss(responseValue);
            iss >> _heightWorld >> _widthWorld;
            // todo
        }

        void Commands::handleCommandBct(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            int x, y, q0, q1, q2, q3, q4, q5, q6;
            iss >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setFood(q0);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setLinemate(q1);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setDeraumere(q2);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setSibur(q3);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setMendiane(q4);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setPhiras(q5);
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(x, y)->setThystame(q6);
        }

        void Commands::handleCommandTna(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            std::string teamName;
            iss >> teamName;
            std::cout << "Team name: " << teamName << std::endl;
            // todo
        }

        void Commands::handleCommandPnw(const std::string& responseValue)
        {
            int playerId, x, y, orientation, level;
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> orientation >> level >> teamName;

            std::cout << "New player: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", Orientation: " << orientation << ", Level: " << level
                    << ", Team: " << teamName << std::endl;
            //todo handle level, teamname and color
            Zappy::GUI::Ressources::Ressources::get()->players.push_back(std::make_shared<Zappy::GUI::Ressources::Players>(playerId, x, y, BLUE));
        }

        void Commands::handleCommandPpo(const std::string& responseValue)
        {
            int playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y;

            std::cout << "Player position: #" << playerId << ", X: " << x << ", Y: " << y << std::endl;
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setX(x);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setY(y);
            // todo virify this
        }

        void Commands::handleCommandPlv(const std::string& responseValue)
        {
            int playerId, level;
            std::istringstream iss(responseValue);
            iss >> playerId >> level;

            std::cout << "Player level: #" << playerId << ", Level: " << level << std::endl;
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setLevel(level);
            // todo
        }

        void Commands::handleCommandPin(const std::string& responseValue)
        {
            int playerId, x, y, q0, q1, q2, q3, q4, q5, q6;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

            std::cout << "Player inventory: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", q0: " << q0 << ", q1: " << q1 << ", q2: " << q2
                    << ", q3: " << q3 << ", q4: " << q4 << ", q5: " << q5
                    << ", q6: " << q6 << std::endl;
            // Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setX(x);
            // Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setY(y);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setFood(q0);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setLinemate(q1);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setDeraumere(q2);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setSibur(q3);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setMendiane(q4);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setPhiras(q5);
            Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->setThystame(q6);
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
            int playerX = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getEgg();
            Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setEgg(value + 1);
        }

        void Commands::handleCommandPdr(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum;
            int playerX = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " dropped resource #" << resourceNum << std::endl;
            if (resourceNum == 0) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getFood();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setFood(value + 1);
            } else if (resourceNum == 1) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getLinemate();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setLinemate(value + 1);
            } else if (resourceNum == 2) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getDeraumere();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setDeraumere(value + 1);
            } else if (resourceNum == 3) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getSibur();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setSibur(value + 1);
            } else if (resourceNum == 4) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getMendiane();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setMendiane(value + 1);
            } else if (resourceNum == 5) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getPhiras();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setPhiras(value + 1);
            } else if (resourceNum == 6) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getThystame();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setThystame(value + 1);
            }
        }

        void Commands::handleCommandPgt(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum;
            int playerX = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Zappy::GUI::Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " took resource #" << resourceNum << std::endl;
            if (resourceNum == 0) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getFood();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setFood(value - 1);
            } else if (resourceNum == 1) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getLinemate();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setLinemate(value - 1);
            } else if (resourceNum == 2) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getDeraumere();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setDeraumere(value - 1);
            } else if (resourceNum == 3) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getSibur();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setSibur(value - 1);
            } else if (resourceNum == 4) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getMendiane();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setMendiane(value - 1);
            } else if (resourceNum == 5) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getPhiras();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setPhiras(value - 1);
            } else if (resourceNum == 6) {
                value = Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getThystame();
                Zappy::GUI::Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setThystame(value - 1);
            }
        }

        void Commands::handleCommandPdi(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId;

            std::cout << "Player #" << playerId << " has died." << std::endl;
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
    }
}