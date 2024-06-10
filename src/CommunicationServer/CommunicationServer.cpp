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
            : serverAddress(address), serverPort(port), sockfd(-1), running(false), _sizeWorld(10, 10)
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

        void ServerCommunication::handleResponse(const std::string& buffer) {
            std::string command = buffer.substr(0, 3);
            std::string value = buffer.substr(3);

            auto it = commandHandlers.find(command);
            if (it != commandHandlers.end()) {
                it->second(value);
            } else {
                std::cerr << "Command not found: " << command << std::endl;
            }
        }

        void ServerCommunication::sendCommand()
        {
            std::unique_lock<std::mutex> lock(commandQueueMutex);
            if (!commandQueue.empty()) {
                std::string nextCommand = commandQueue.front();
                commandQueue.pop();
                std::cout << "Command sent to server: " << nextCommand << std::endl;
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

        void ServerCommunication::handleCommandMsz(const std::string& info)
        {
            int _heightWorld, _widthWorld;
            std::istringstream iss(info);
            if (!(iss >> _heightWorld >> _widthWorld))
                std::cerr << "Error in parsing sizeWorld" << std::endl;
            _sizeWorld = { _heightWorld, _widthWorld};
            std::cout << "info msz: " << _heightWorld << " " << _widthWorld << std::endl;
        }

        void ServerCommunication::handleCommandBct(const std::string& info) {
            size_t pos1 = info.find(' ');
            size_t pos2 = info.find(' ', pos1 + 1);
            int x = std::stoi(info.substr(pos1 + 1, pos2 - pos1 - 1));
            int y = std::stoi(info.substr(pos2 + 1));

            LastTileresearch_Resources LastTileresearch_Resources;
            LastTileresearch_Resources.food = Ressources::Ressources::get()->tileRessources[x][y]->getFood();
            LastTileresearch_Resources.linemate = Ressources::Ressources::get()->tileRessources[x][y]->getLinemate();
            LastTileresearch_Resources.deraumere = Ressources::Ressources::get()->tileRessources[x][y]->getDeraumere();
            LastTileresearch_Resources.sibur = Ressources::Ressources::get()->tileRessources[x][y]->getSibur();
            LastTileresearch_Resources.mendiane = Ressources::Ressources::get()->tileRessources[x][y]->getMendiane();
            LastTileresearch_Resources.phiras = Ressources::Ressources::get()->tileRessources[x][y]->getPhiras();
            LastTileresearch_Resources.thystame = Ressources::Ressources::get()->tileRessources[x][y]->getThystame();
            std::cout << "info bct command:" << std::endl;
            std::cout << "\tFood: " << LastTileresearch_Resources.food << std::endl;
            std::cout << "\tLinemate: " << LastTileresearch_Resources.linemate << std::endl;
            std::cout << "\tDeraumere: " << LastTileresearch_Resources.deraumere << std::endl;
            std::cout << "\tSibur: " << LastTileresearch_Resources.sibur << std::endl;
            std::cout << "\tMendiane: " << LastTileresearch_Resources.mendiane << std::endl;
            std::cout << "\tPhiras: " << LastTileresearch_Resources.phiras << std::endl;
            std::cout << "\tThystame: " << LastTileresearch_Resources.thystame << std::endl;
        }
    }
}
