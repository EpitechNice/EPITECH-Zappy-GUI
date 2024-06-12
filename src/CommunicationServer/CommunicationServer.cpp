/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ConectServer
*/

#include "CommunicationServer.hpp"

namespace Zappy {
    namespace GUI {
        ServerCommunication::ServerCommunication(const std::string& address, int port)
            : _serverAddress(address), _serverPort(port), _sockfd(-1), _running(false)
            {
        }

        ServerCommunication::~ServerCommunication()
        {
            closeConnection();
        }

        void ServerCommunication::connectToServer()
        {
            _sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (_sockfd == -1) {
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _serverAddress, _serverPort);
            }
            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(_serverPort);
            inet_pton(AF_INET, _serverAddress.c_str(), &serv_addr.sin_addr);
            if (connect(_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                closeConnection();
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _serverAddress, _serverPort);
            }
        }

        void ServerCommunication::startCommunication()
        {
            _running = true;
            std::thread communicationThread(&ServerCommunication::handleServerMessages, this);
            communicationThread.detach();
        }

        void ServerCommunication::handleServerMessages()
        {
            fd_set readfds;
            struct timeval timeout;
            timeout.tv_sec = 0;
            timeout.tv_usec = 1000;

            while (_running) {
                FD_ZERO(&readfds);
                FD_SET(_sockfd, &readfds);

                int ready = select(_sockfd + 1, &readfds, NULL, NULL, &timeout);
                if (ready == -1) {
                    std::cout << "Error in select" << std::endl;
                    break;
                } else if (ready > 0) {
                    if (FD_ISSET(_sockfd, &readfds)) {
                        receiveAndProcessResponse();
                    }
                }
                    sendCommand();
            }
        }

        void ServerCommunication::receiveAndProcessResponse()
        {
            char buffer[100];
            ssize_t bytesReceived = recv(_sockfd, buffer, 100, 0);

            if (bytesReceived == -1) {
                std::cout << "Error receiving message" << std::endl;
            } else if (bytesReceived == 0) {
                std::cout << "Connection closed by server" << std::endl;
                _running = false;
            } else {
                buffer[bytesReceived] = '\0';
                std::string bufferStr(buffer);
                handleResponse(bufferStr);
            }
        }

        void ServerCommunication::handleResponse(const std::string& buffer)
        {
            std::string command = buffer.substr(0, 3);
            std::string responseValue = buffer.substr(3);

            auto it = _commandHandlers.find(command);
            if (it != _commandHandlers.end()) {
                it->second(responseValue);
            }
        }

        void ServerCommunication::sendCommand()
        {
            std::unique_lock<std::mutex> lock(_commandQueueMutex);
            if (!_commandQueue.empty()) {
                std::string nextCommand = _commandQueue.front();
                _commandQueue.pop();
                send(_sockfd, nextCommand.c_str(), nextCommand.size(), 0);
            }
            lock.unlock();
        }

        void ServerCommunication::addCommand(const std::string& command)
        {
            if (_sockfd != -1) {
                std::lock_guard<std::mutex> lock(_commandQueueMutex);
                _commandQueue.push(command);
                _commandQueueNotEmpty.notify_one();
            }
        }

        void ServerCommunication::closeConnection()
        {
            _running = false;
            if (_sockfd != -1) {
                close(_sockfd);
                _sockfd = -1;
            }
        }

        void ServerCommunication::handleCommandMsz(const std::string& responseValue)
        {
            int _heightWorld, _widthWorld;
            std::istringstream iss(responseValue);
            iss >> _heightWorld >> _widthWorld;
            _mapSizeCallback(_heightWorld, _widthWorld);
        }

        void ServerCommunication::handleCommandBct(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            int x, y, q0, q1, q2, q3, q4, q5, q6;
            iss >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;
            Ressources::Ressources::get()->getTileFromPos(x, y)->setFood(q0);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setLinemate(q1);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setDeraumere(q2);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setSibur(q3);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setMendiane(q4);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setPhiras(q5);
            Ressources::Ressources::get()->getTileFromPos(x, y)->setThystame(q6);
        }

        void ServerCommunication::handleCommandTna(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            std::string teamName;
            iss >> teamName;
            std::cout << "Team name: " << teamName << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandPnw(const std::string& responseValue)
        {
            int playerId, x, y, orientation, level;
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> orientation >> level >> teamName;

            std::cout << "New player: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", Orientation: " << orientation << ", Level: " << level
                    << ", Team: " << teamName << std::endl;
            //todo handle level, teamname and color
            Ressources::Ressources::get()->players.push_back(std::make_shared<Ressources::Players>(playerId, x, y, BLUE));
        }

        void ServerCommunication::handleCommandPpo(const std::string& responseValue)
        {
            int playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y;

            std::cout << "Player position: #" << playerId << ", X: " << x << ", Y: " << y << std::endl;
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setX(x);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setY(y);
            // todo virify this
        }

        void ServerCommunication::handleCommandPlv(const std::string& responseValue)
        {
            int playerId, level;
            std::istringstream iss(responseValue);
            iss >> playerId >> level;

            std::cout << "Player level: #" << playerId << ", Level: " << level << std::endl;
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setLevel(level);
            // todo
        }

        void ServerCommunication::handleCommandPin(const std::string& responseValue)
        {
            int playerId, x, y, q0, q1, q2, q3, q4, q5, q6;
            std::istringstream iss(responseValue);
            iss >> playerId >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

            std::cout << "Player inventory: #" << playerId << ", X: " << x << ", Y: " << y
                    << ", q0: " << q0 << ", q1: " << q1 << ", q2: " << q2
                    << ", q3: " << q3 << ", q4: " << q4 << ", q5: " << q5
                    << ", q6: " << q6 << std::endl;
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setX(x);
            // Ressources::Ressources::get()->getPlayerFromId(playerId)->setY(y);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setFood(q0);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setLinemate(q1);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setDeraumere(q2);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setSibur(q3);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setMendiane(q4);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setPhiras(q5);
            Ressources::Ressources::get()->getPlayerFromId(playerId)->setThystame(q6);
        }

        void ServerCommunication::handleCommandPex(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId;

            std::cout << "Player expelled: #" << playerId << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandPbc(const std::string& responseValue)
        {
            int playerId;
            std::string message;
            std::istringstream iss(responseValue);
            iss >> playerId >> std::ws;
            std::getline(iss, message);

            std::cout << "Broadcast from player #" << playerId << ": " << message << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandPic(const std::string& responseValue)
        {
            std::cout << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPie(const std::string& responseValue)
        {
            int x, y;
            std::string result;
            std::istringstream iss(responseValue);
            iss >> x >> y >> result;

            std::cout << "Incantation ended at (" << x << ", " << y << ") with result: " << result << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandPfk(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId;

            std::cout << "Player #" << playerId << " laid an egg." << std::endl;
            int playerX = Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getEgg();
            Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setEgg(value + 1);
        }

        void ServerCommunication::handleCommandPdr(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum;
            int playerX = Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " dropped resource #" << resourceNum << std::endl;
            if (resourceNum == 0) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getFood();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setFood(value + 1);
            } else if (resourceNum == 1) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getLinemate();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setLinemate(value + 1);
            } else if (resourceNum == 2) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getDeraumere();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setDeraumere(value + 1);
            } else if (resourceNum == 3) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getSibur();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setSibur(value + 1);
            } else if (resourceNum == 4) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getMendiane();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setMendiane(value + 1);
            } else if (resourceNum == 5) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getPhiras();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setPhiras(value + 1);
            } else if (resourceNum == 6) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getThystame();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setThystame(value + 1);
            }
        }

        void ServerCommunication::handleCommandPgt(const std::string& responseValue)
        {
            int playerId, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerId >> resourceNum;
            int playerX = Ressources::Ressources::get()->getPlayerFromId(playerId)->getX();
            int playerY = Ressources::Ressources::get()->getPlayerFromId(playerId)->getY();
            int value;

            std::cout << "Player #" << playerId << " took resource #" << resourceNum << std::endl;
            if (resourceNum == 0) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getFood();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setFood(value - 1);
            } else if (resourceNum == 1) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getLinemate();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setLinemate(value - 1);
            } else if (resourceNum == 2) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getDeraumere();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setDeraumere(value - 1);
            } else if (resourceNum == 3) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getSibur();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setSibur(value - 1);
            } else if (resourceNum == 4) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getMendiane();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setMendiane(value - 1);
            } else if (resourceNum == 5) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getPhiras();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setPhiras(value - 1);
            } else if (resourceNum == 6) {
                value = Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->getThystame();
                Ressources::Ressources::get()->getTileFromPos(playerX, playerY)->setThystame(value - 1);
            }
        }

        void ServerCommunication::handleCommandPdi(const std::string& responseValue)
        {
            int playerId;
            std::istringstream iss(responseValue);
            iss >> playerId;

            std::cout << "Player #" << playerId << " has died." << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandEnw(const std::string& responseValue)
        {
            int eggNum, playerId, x, y;
            std::istringstream iss(responseValue);
            iss >> eggNum >> playerId >> x >> y;

            std::cout << "New egg: #" << eggNum << " laid by player #" << playerId << " at (" << x << ", " << y << ")" << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandEbo(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " hatched." << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandEdi(const std::string& responseValue)
        {
            std::cout << "Server broadcasted: " << responseValue << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandSgt(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " died." << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandSst(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Current time unit: " << timeUnit << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandSeg(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Time unit set to: " << timeUnit << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandSmg(const std::string& responseValue)
        {
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> teamName;

            std::cout << "Game ended. Winning team: " << teamName << std::endl;
            // todo
        }

        void ServerCommunication::handleCommandSuc([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "Unknown command" << std::endl;
        }

        void ServerCommunication::handleCommandSbp([[maybe_unused]] const std::string& responseValue)
        {
            std::cout << "command parametre" << std::endl;
        }
    }
}
