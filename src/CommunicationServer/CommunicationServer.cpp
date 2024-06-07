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
            : serverAddress(address), serverPort(port), sockfd(-1), running(false) {
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
                } else {
                    sendCommand();
                }
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
                std::cout << "Response from server: " << buffer << std::endl;
                sendCommand();
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
    }
}