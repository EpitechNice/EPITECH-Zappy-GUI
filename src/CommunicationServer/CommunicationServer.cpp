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
            std::cout << "response serveur:" << responseValue << std::endl;
            // size_t pos1 = responseValue.find(' ');
            // size_t pos2 = responseValue.find(' ', pos1 + 1);
            // int x = std::stoi(responseValue.substr(pos1 + 1, pos2 - pos1 - 1));
            // int y = std::stoi(responseValue.substr(pos2 + 1));
        }

        void ServerCommunication::handleCommandMct(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            // int mapHeight = Ressources::Ressources::get()->tileRessources.size();
            // int mapWidth = Ressources::Ressources::get()->tileRessources[0].size();

        }

        void ServerCommunication::handleCommandTna(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPnw(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPpo(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPlv(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPin(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPex(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPbc(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPic(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPie(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPfk(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPdr(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPgt(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandPdi(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandEnw(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandEbo(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSgt(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSst(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSeg(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSmg(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSuc(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandSbp(const std::string& responseValue)
        {
            std::cout << "response serveur:" << responseValue << std::endl;
            //todo
        }

        void ServerCommunication::handleCommandEdi(const std::string& responseValue)
        {
            std::cout << "response serveur: " << responseValue << std::endl;
            // Implement your handling logic here
        }
    }
}
