/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ConnectServer
*/

#ifndef SCENE_CONECTSERVER_HPP_
    #define SCENE_CONECTSERVER_HPP_

#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace Zappy {
    namespace GUI {
        class ServerCommunication {
        public:
            ServerCommunication(const std::string& address, int port);
            ~ServerCommunication();

            bool connectToServer();
            void closeConnection();
            void startCommunication();

            void addCommand(const std::string& command);
            void sendCommand();
            void receiveAndProcessResponse();

        private:
            void handleServerMessages();

            std::string serverAddress;
            int serverPort;
            int sockfd;
            bool running;

            std::queue<std::string> commandQueue;
            std::mutex commandQueueMutex;
            std::condition_variable commandQueueNotEmpty;
        };
    }
}

#endif /* !SCENE_CONECTSERVER_HPP_ */
