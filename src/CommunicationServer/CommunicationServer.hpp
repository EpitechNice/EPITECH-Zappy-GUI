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
#include <unordered_map>
#include <functional>

#include "Command/BctCommand/BctCommand.hpp"
#include "Command/MszCommand/MszCommand.hpp"

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
            void handleResponse(const std::string& buffer);

        private:
            void handleServerMessages();

            std::string serverAddress;
            int serverPort;
            int sockfd;
            bool running;

            std::queue<std::string> commandQueue;
            std::mutex commandQueueMutex;
            std::condition_variable commandQueueNotEmpty;

            std::unordered_map<std::string, std::function<void(const std::string&)>> commandHandlers = {
                {"msz", [this](const std::string& value) { Zappy::GUI::MszCommand(value).parseCommand(value); }},
                {"bct", [this](const std::string& value) { Zappy::GUI::BctCommand(value).parseCommand(value); }},
            };
        };
    }
}

#endif /* !SCENE_CONECTSERVER_HPP_ */
