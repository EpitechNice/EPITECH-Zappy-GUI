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

    #include "Exceptions.hpp"
    #include "Mutex.hpp"
    #include "Commands.hpp"

namespace Zappy {
    namespace Server {
        class Server {
            public:
                Server(const std::string &address, int port);
                ~Server() = default;

                void run();
                void shutdown();

                void setInOut(); // set the in and out namepipes -> shared ptr

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
                Commands commandsInstance;

                std::queue<std::string> _requestQueue;
                Mutex _requestQueueMutex;
                std::condition_variable _requestQueueNotEmpty;
                std::queue<std::string> _responseQueue;
                Mutex _responseQueueMutex;
                std::condition_variable _responseQueueNotEmpty;

                // namepipe in
                // namepipe out

                void _connect();
                void _loop();
                void _handleResponse(const std::string& buffer);
                void _disconnect();
                void _addRequest(const std::string &request);
                void _addResponse(const std::string &request);

                std::unordered_map<std::string, std::function<void(const std::string&)>> _commandHandlers = {
                    {"msz", [this](const std::string& responseValue) { commandsInstance.handleCommandMsz(responseValue); }},
                    {"bct", [this](const std::string& responseValue) { commandsInstance.handleCommandBct(responseValue); }},
                    {"tna", [this](const std::string& responseValue) { commandsInstance.handleCommandTna(responseValue); }},
                    {"pnw", [this](const std::string& responseValue) { commandsInstance.handleCommandPnw(responseValue); }},
                    {"ppo", [this](const std::string& responseValue) { commandsInstance.handleCommandPpo(responseValue); }},
                    {"plv", [this](const std::string& responseValue) { commandsInstance.handleCommandPlv(responseValue); }},
                    {"pin", [this](const std::string& responseValue) { commandsInstance.handleCommandPin(responseValue); }},
                    {"pex", [this](const std::string& responseValue) { commandsInstance.handleCommandPex(responseValue); }},
                    {"pbc", [this](const std::string& responseValue) { commandsInstance.handleCommandPbc(responseValue); }},
                    {"pic", [this](const std::string& responseValue) { commandsInstance.handleCommandPic(responseValue); }},
                    {"pie", [this](const std::string& responseValue) { commandsInstance.handleCommandPie(responseValue); }},
                    {"pfk", [this](const std::string& responseValue) { commandsInstance.handleCommandPfk(responseValue); }},
                    {"pdr", [this](const std::string& responseValue) { commandsInstance.handleCommandPdr(responseValue); }},
                    {"pgt", [this](const std::string& responseValue) { commandsInstance.handleCommandPgt(responseValue); }},
                    {"pdi", [this](const std::string& responseValue) { commandsInstance.handleCommandPdi(responseValue); }},
                    {"enw", [this](const std::string& responseValue) { commandsInstance.handleCommandEnw(responseValue); }},
                    {"ebo", [this](const std::string& responseValue) { commandsInstance.handleCommandEbo(responseValue); }},
                    {"edi", [this](const std::string& responseValue) { commandsInstance.handleCommandEdi(responseValue); }},
                    {"sgt", [this](const std::string& responseValue) { commandsInstance.handleCommandSgt(responseValue); }},
                    {"sst", [this](const std::string& responseValue) { commandsInstance.handleCommandSst(responseValue); }},
                    {"seg", [this](const std::string& responseValue) { commandsInstance.handleCommandSeg(responseValue); }},
                    {"smg", [this](const std::string& responseValue) { commandsInstance.handleCommandSmg(responseValue); }},
                    {"suc", [this](const std::string& responseValue) { commandsInstance.handleCommandSuc(responseValue); }},
                    {"sbp", [this](const std::string& responseValue) { commandsInstance.handleCommandSbp(responseValue); }},
                };
        };
    }
}

#endif /* !SERVER_HPP_ */
