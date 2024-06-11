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
            : serverAddress(address), serverPort(port), sockfd(-1), running(false)
            {
        }

        ServerCommunication::~ServerCommunication()
        {
            closeConnection();
        }

        bool ServerCommunication::connectToServer()
        {
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("Error: socket creation failed\n");
                return false;
            }
            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(serverPort);
            inet_pton(AF_INET, serverAddress.c_str(), &serv_addr.sin_addr);
            if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                std::cout << "Error: connection to server failed\n" << std::endl;
                closeConnection();
                return false;
            }
            return true;
        }

        void ServerCommunication::startCommunication()
        {
            running = true;
            std::thread communicationThread(&ServerCommunication::handleServerMessages, this);
            communicationThread.detach();
        }

        void ServerCommunication::handleServerMessages()
        {
            fd_set readfds;
            struct timeval timeout;
            timeout.tv_sec = 0;
            timeout.tv_usec = 1000;

            while (running) {
                FD_ZERO(&readfds);
                FD_SET(sockfd, &readfds);

                int ready = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
                if (ready == -1) {
                    std::cout << "Error in select" << std::endl;
                    break;
                } else if (ready > 0) {
                    if (FD_ISSET(sockfd, &readfds)) {
                        receiveAndProcessResponse();
                    }
                }
                    sendCommand();
            }
        }

        void ServerCommunication::receiveAndProcessResponse()
        {
            char buffer[100];
            ssize_t bytesReceived = recv(sockfd, buffer, 100, 0);

            if (bytesReceived == -1) {
                std::cout << "Error receiving message" << std::endl;
            } else if (bytesReceived == 0) {
                std::cout << "Connection closed by server" << std::endl;
                running = false;
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

            auto it = commandHandlers.find(command);
            if (it != commandHandlers.end()) {
                it->second(responseValue);
            }
        }

        void ServerCommunication::sendCommand()
        {
            std::unique_lock<std::mutex> lock(commandQueueMutex);
            if (!commandQueue.empty()) {
                std::string nextCommand = commandQueue.front();
                commandQueue.pop();
                send(sockfd, nextCommand.c_str(), nextCommand.size(), 0);
            }
            lock.unlock();
        }

        void ServerCommunication::addCommand(const std::string& command)
        {
            if (sockfd != -1) {
                std::lock_guard<std::mutex> lock(commandQueueMutex);
                commandQueue.push(command);
                commandQueueNotEmpty.notify_one();
            }
        }

        void ServerCommunication::closeConnection()
        {
            running = false;
            if (sockfd != -1) {
                close(sockfd);
                sockfd = -1;
            }
        }

        void ServerCommunication::handleCommandMsz(const std::string& responseValue)
        {
            int _heightWorld, _widthWorld;
            std::istringstream iss(responseValue);
            iss >> _heightWorld >> _widthWorld;
            mapSizeCallback(_heightWorld, _widthWorld);
        }

        void ServerCommunication::handleCommandBct(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            std::string command;
            int x, y, q0, q1, q2, q3, q4, q5, q6;
            iss >> command >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

            std::cout << "x: " << x << ", y: " << y << std::endl;
            std::cout << "q0: " << q0 << ", q1: " << q1 << ", q2: " << q2 << ", q3: " << q3 << ", q4: " << q4 << ", q5: " << q5 << ", q6: " << q6 << std::endl;
        }

        void ServerCommunication::handleCommandTna(const std::string& responseValue)
        {
            std::istringstream iss(responseValue);
            std::string teamName;
            iss >> teamName;
            std::cout << "Team name: " << teamName << std::endl;
        }

        void ServerCommunication::handleCommandPnw(const std::string& responseValue)
        {
            int playerNum, x, y, orientation, level;
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> playerNum >> x >> y >> orientation >> level >> teamName;

            std::cout << "New player: #" << playerNum << ", X: " << x << ", Y: " << y
                    << ", Orientation: " << orientation << ", Level: " << level
                    << ", Team: " << teamName << std::endl;
        }

        void ServerCommunication::handleCommandPpo(const std::string& responseValue)
        {
            int playerNum, x, y, orientation;
            std::istringstream iss(responseValue);
            iss >> playerNum >> x >> y >> orientation;

            std::cout << "Player position: #" << playerNum << ", X: " << x << ", Y: " << y
                    << ", Orientation: " << orientation << std::endl;
        }

        void ServerCommunication::handleCommandPlv(const std::string& responseValue)
        {
            int playerNum, level;
            std::istringstream iss(responseValue);
            iss >> playerNum >> level;

            std::cout << "Player level: #" << playerNum << ", Level: " << level << std::endl;
        }

        void ServerCommunication::handleCommandPin(const std::string& responseValue)
        {
            int playerNum, x, y, q0, q1, q2, q3, q4, q5, q6;
            std::istringstream iss(responseValue);
            iss >> playerNum >> x >> y >> q0 >> q1 >> q2 >> q3 >> q4 >> q5 >> q6;

            std::cout << "Player inventory: #" << playerNum << ", X: " << x << ", Y: " << y
                    << ", q0: " << q0 << ", q1: " << q1 << ", q2: " << q2
                    << ", q3: " << q3 << ", q4: " << q4 << ", q5: " << q5
                    << ", q6: " << q6 << std::endl;
        }

        void ServerCommunication::handleCommandPex(const std::string& responseValue)
        {
            int playerNum;
            std::istringstream iss(responseValue);
            iss >> playerNum;

            std::cout << "Player expelled: #" << playerNum << std::endl;
        }

        void ServerCommunication::handleCommandPbc(const std::string& responseValue)
        {
            int playerNum;
            std::string message;
            std::istringstream iss(responseValue);
            iss >> playerNum >> std::ws;
            std::getline(iss, message);

            std::cout << "Broadcast from player #" << playerNum << ": " << message << std::endl;
        }

        void ServerCommunication::handleCommandPic(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPie(const std::string& responseValue)
        {
            int x, y;
            std::string result;
            std::istringstream iss(responseValue);
            iss >> x >> y >> result;

            std::cout << "Incantation ended at (" << x << ", " << y << ") with result: " << result << std::endl;
        }

        void ServerCommunication::handleCommandPfk(const std::string& responseValue)
        {
            int playerNum;
            std::istringstream iss(responseValue);
            iss >> playerNum;

            std::cout << "Player #" << playerNum << " laid an egg." << std::endl;
        }

        void ServerCommunication::handleCommandPdr(const std::string& responseValue)
        {
            int playerNum, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerNum >> resourceNum;

            std::cout << "Player #" << playerNum << " dropped resource #" << resourceNum << std::endl;
        }

        void ServerCommunication::handleCommandPgt(const std::string& responseValue)
        {
            int playerNum, resourceNum;
            std::istringstream iss(responseValue);
            iss >> playerNum >> resourceNum;

            std::cout << "Player #" << playerNum << " took resource #" << resourceNum << std::endl;
        }

        void ServerCommunication::handleCommandPdi(const std::string& responseValue)
        {
            int playerNum;
            std::istringstream iss(responseValue);
            iss >> playerNum;

            std::cout << "Player #" << playerNum << " has died." << std::endl;
        }

        void ServerCommunication::handleCommandEnw(const std::string& responseValue)
        {
            int eggNum, playerNum, x, y;
            std::istringstream iss(responseValue);
            iss >> eggNum >> playerNum >> x >> y;

            std::cout << "New egg: #" << eggNum << " laid by player #" << playerNum << " at (" << x << ", " << y << ")" << std::endl;
        }

        void ServerCommunication::handleCommandEbo(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " hatched." << std::endl;
        }

        void ServerCommunication::handleCommandSgt(const std::string& responseValue)
        {
            int eggNum;
            std::istringstream iss(responseValue);
            iss >> eggNum;

            std::cout << "Egg #" << eggNum << " died." << std::endl;
        }

        void ServerCommunication::handleCommandSst(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Current time unit: " << timeUnit << std::endl;
        }

        void ServerCommunication::handleCommandSeg(const std::string& responseValue)
        {
            int timeUnit;
            std::istringstream iss(responseValue);
            iss >> timeUnit;

            std::cout << "Time unit set to: " << timeUnit << std::endl;
        }

        void ServerCommunication::handleCommandSmg(const std::string& responseValue)
        {
            std::string teamName;
            std::istringstream iss(responseValue);
            iss >> teamName;

            std::cout << "Game ended. Winning team: " << teamName << std::endl;
        }

        void ServerCommunication::handleCommandSuc(const std::string& responseValue)
        {
            std::string message;
            std::istringstream iss(responseValue);
            std::getline(iss, message);

            std::cout << "Server message: " << message << std::endl;
        }

        void ServerCommunication::handleCommandSbp(const std::string& responseValue)
        {
            std::cout << "Unknown command" << std::endl;
        }

        void ServerCommunication::handleCommandEdi(const std::string& responseValue)
        {
            std::cout << "Server broadcasted: " << responseValue << std::endl;
        }
    }
}
