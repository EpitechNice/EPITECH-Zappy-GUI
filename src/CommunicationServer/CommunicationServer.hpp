/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ConnectServer
*/

#ifndef SCENE_CONECTSERVER_HPP_
    #define SCENE_CONECTSERVER_HPP_

#include <sstream>
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <thread>
#include <queue>
#include <map>
#include <mutex>
#include <condition_variable>
#include <unordered_map>
#include <functional>

#include "TileRessources.hpp"
#include "ComponentTileMap.hpp"
#include "Ressources.hpp"

namespace Zappy {
    namespace GUI {
        class ServerCommunication {

            struct LastTileresearch_Resources {
                int food;
                int linemate;
                int deraumere;
                int sibur;
                int mendiane;
                int phiras;
                int thystame;
            };

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

            void handleCommandMsz(const std::string& info);
            void handleCommandBct(const std::string& info);

            std::pair<int, int> getSizeWorld() { return _sizeWorld; };

        private:
            void handleServerMessages();

            std::string serverAddress;
            int serverPort;
            int sockfd;
            bool running;

            std::queue<std::string> commandQueue;
            std::mutex commandQueueMutex;
            std::condition_variable commandQueueNotEmpty;

            std::pair<int, int> _sizeWorld;

            std::unordered_map<std::string, std::function<void(const std::string&)>> commandHandlers = {
                {"msz", [this](const std::string& value) { handleCommandMsz(value); }},
                {"bct", [this](const std::string& value) { handleCommandBct(value); }},
            };
        };
    }
}

#endif /* !SCENE_CONECTSERVER_HPP_ */
