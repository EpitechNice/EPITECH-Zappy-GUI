/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <string>
    #include <memory>
    #include <iostream>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <queue>
    #include <cstring>
    #include <condition_variable>
    #include <unordered_map>
    #include <functional>
    #include <chrono>
    #include <thread>


    #include "Exceptions.hpp"
    #include "Mutex.hpp"
    #include "Commands.hpp"
    #include "SharedMemory.hpp"
    #include "Ref.hpp"

namespace Zappy {
    namespace Server {
        class Server {
            public:
                Server(const std::string &address, int port);
                ~Server() = default;

                void run();
                void shutdown();

                void setInOut(); // set the in and out namepipes -> shared ptr
                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);
                std::shared_ptr<SharedMemory> getSharedMemory();

            protected:
            private:
                typedef enum {
                    TRY_CONNECT,
                    CONNECTED,
                    DISCONNECT,
                    DOWN
                } State;

                struct sockaddr_in _socketAddress;
                std::string _address;
                int _port;
                State _state;
                int _fd;
                bool _mszCommandReceived;
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;
                std::shared_ptr<Zappy::Server::Commands> _commands;

                std::queue<std::string> _responseQueue;
                std::mutex _responseQueueMutex;
                std::condition_variable _responseQueueNotEmpty;
                std::shared_ptr<SharedMemory> _sharedMemory;
                std::thread _sendThread;

                // namepipe in
                // namepipe out

                void _connect();
                void _disconnect();
                void _loop();
                void _addResponse(const std::string &request);
                void _handleResponse(const std::string& buffer);
                void _sendRequest();

                std::unordered_map<std::string, std::function<void(const std::string&)>> _commandHandlers = {
                    {"msz", [this](const std::string& responseValue) { _commands->handleCommandMsz(responseValue); }},
                    {"bct", [this](const std::string& responseValue) { _commands->handleCommandBct(responseValue); }},
                    {"tna", [this](const std::string& responseValue) { _commands->handleCommandTna(responseValue); }},
                    {"pnw", [this](const std::string& responseValue) { _commands->handleCommandPnw(responseValue); }},
                    {"ppo", [this](const std::string& responseValue) { _commands->handleCommandPpo(responseValue); }},
                    {"plv", [this](const std::string& responseValue) { _commands->handleCommandPlv(responseValue); }},
                    {"pin", [this](const std::string& responseValue) { _commands->handleCommandPin(responseValue); }},
                    {"pex", [this](const std::string& responseValue) { _commands->handleCommandPex(responseValue); }},
                    {"pbc", [this](const std::string& responseValue) { _commands->handleCommandPbc(responseValue); }},
                    {"pic", [this](const std::string& responseValue) { _commands->handleCommandPic(responseValue); }},
                    {"pie", [this](const std::string& responseValue) { _commands->handleCommandPie(responseValue); }},
                    {"pfk", [this](const std::string& responseValue) { _commands->handleCommandPfk(responseValue); }},
                    {"pdr", [this](const std::string& responseValue) { _commands->handleCommandPdr(responseValue); }},
                    {"pgt", [this](const std::string& responseValue) { _commands->handleCommandPgt(responseValue); }},
                    {"pdi", [this](const std::string& responseValue) { _commands->handleCommandPdi(responseValue); }},
                    {"enw", [this](const std::string& responseValue) { _commands->handleCommandEnw(responseValue); }},
                    {"ebo", [this](const std::string& responseValue) { _commands->handleCommandEbo(responseValue); }},
                    {"edi", [this](const std::string& responseValue) { _commands->handleCommandEdi(responseValue); }},
                    {"sgt", [this](const std::string& responseValue) { _commands->handleCommandSgt(responseValue); }},
                    {"sst", [this](const std::string& responseValue) { _commands->handleCommandSst(responseValue); }},
                    {"seg", [this](const std::string& responseValue) { _commands->handleCommandSeg(responseValue); }},
                    {"smg", [this](const std::string& responseValue) { _commands->handleCommandSmg(responseValue); }},
                    {"suc", [this](const std::string& responseValue) { _commands->handleCommandSuc(responseValue); }},
                    {"sbp", [this](const std::string& responseValue) { _commands->handleCommandSbp(responseValue); }},
                };
        };
    }
}

#endif /* !SERVER_HPP_ */
