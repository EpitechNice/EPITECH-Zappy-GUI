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

            //commands
            void handleCommandMsz(const std::string& responseValue);
            void handleCommandBct(const std::string& responseValue);
            void handleCommandMct(const std::string& responseValue);
            void handleCommandTna(const std::string& responseValue);
            void handleCommandPnw(const std::string& responseValue);
            void handleCommandPpo(const std::string& responseValue);
            void handleCommandPlv(const std::string& responseValue);
            void handleCommandPin(const std::string& responseValue);
            void handleCommandPex(const std::string& responseValue);
            void handleCommandPbc(const std::string& responseValue);
            void handleCommandPic(const std::string& responseValue);
            void handleCommandPie(const std::string& responseValue);
            void handleCommandPfk(const std::string& responseValue);
            void handleCommandPdr(const std::string& responseValue);
            void handleCommandPgt(const std::string& responseValue);
            void handleCommandPdi(const std::string& responseValue);
            void handleCommandEnw(const std::string& responseValue);
            void handleCommandEbo(const std::string& responseValue);
            void handleCommandEdi(const std::string& responseValue);
            void handleCommandSgt(const std::string& responseValue);
            void handleCommandSst(const std::string& responseValue);
            void handleCommandSeg(const std::string& responseValue);
            void handleCommandSmg(const std::string& responseValue);
            void handleCommandSuc(const std::string& responseValue);
            void handleCommandSbp(const std::string& responseValue);

            void setMapSizeCallback(std::function<void(int, int)> callback) { mapSizeCallback = callback; }

        private:
            void handleServerMessages();

            std::string serverAddress;
            int serverPort;
            int sockfd;
            bool running;

            std::queue<std::string> commandQueue;
            std::mutex commandQueueMutex;
            std::condition_variable commandQueueNotEmpty;

            std::function<void(int, int)> mapSizeCallback;

            std::unordered_map<std::string, std::function<void(const std::string&)>> commandHandlers = {
                {"msz", [this](const std::string& responseValue) { handleCommandMsz(responseValue); }},
                {"bct", [this](const std::string& responseValue) { handleCommandBct(responseValue); }},
                {"mct", [this](const std::string& responseValue) { handleCommandMct(responseValue); }},
                {"tna", [this](const std::string& responseValue) { handleCommandTna(responseValue); }},
                {"pnw", [this](const std::string& responseValue) { handleCommandPnw(responseValue); }},
                {"ppo", [this](const std::string& responseValue) { handleCommandPpo(responseValue); }},
                {"plv", [this](const std::string& responseValue) { handleCommandPlv(responseValue); }},
                {"pin", [this](const std::string& responseValue) { handleCommandPin(responseValue); }},
                {"pex", [this](const std::string& responseValue) { handleCommandPex(responseValue); }},
                {"pbc", [this](const std::string& responseValue) { handleCommandPbc(responseValue); }},
                {"pic", [this](const std::string& responseValue) { handleCommandPic(responseValue); }},
                {"pie", [this](const std::string& responseValue) { handleCommandPie(responseValue); }},
                {"pfk", [this](const std::string& responseValue) { handleCommandPfk(responseValue); }},
                {"pdr", [this](const std::string& responseValue) { handleCommandPdr(responseValue); }},
                {"pgt", [this](const std::string& responseValue) { handleCommandPgt(responseValue); }},
                {"pdi", [this](const std::string& responseValue) { handleCommandPdi(responseValue); }},
                {"enw", [this](const std::string& responseValue) { handleCommandEnw(responseValue); }},
                {"ebo", [this](const std::string& responseValue) { handleCommandEbo(responseValue); }},
                {"edi", [this](const std::string& responseValue) { handleCommandEdi(responseValue); }},
                {"sgt", [this](const std::string& responseValue) { handleCommandSgt(responseValue); }},
                {"sst", [this](const std::string& responseValue) { handleCommandSst(responseValue); }},
                {"seg", [this](const std::string& responseValue) { handleCommandSeg(responseValue); }},
                {"smg", [this](const std::string& responseValue) { handleCommandSmg(responseValue); }},
                {"suc", [this](const std::string& responseValue) { handleCommandSuc(responseValue); }},
                {"sbp", [this](const std::string& responseValue) { handleCommandSbp(responseValue); }},
            };
        };
    }
}

#endif /* !SCENE_CONECTSERVER_HPP_ */
