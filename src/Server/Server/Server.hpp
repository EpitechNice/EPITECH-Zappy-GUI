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
    #include "Utils.hpp"

namespace Zappy {
    namespace Server {
        /**
         * @brief Server class
         */
        class Server {
            public:
                /**
                 * @brief Server constructor
                 *
                 * @param address IP address of the server
                 * @param port Port number of the server
                 */
                Server(const std::string &address, int port);
                ~Server() = default;

                /**
                 * @brief Run the server
                 *
                 * @brief Manages connection, reconnection, loop and disconnection depending on the server state
                 */
                void run();

                /**
                 * @brief Shutdown the server
                 */
                void shutdown();

                /**
                 * @brief Set the resources for the server
                 *
                 * @param ressources Shared pointer to the resources
                 */
                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);

                /**
                 * @brief Get the shared memory object
                 *
                 * @return Shared pointer to the shared memory
                 */
                std::shared_ptr<SharedMemory> getSharedMemory();

            protected:
            private:
                typedef enum {
                    TRY_CONNECT,
                    CONNECTED,
                    RECONNECT,
                    DISCONNECT,
                    DOWN
                } State;

                struct sockaddr_in _socketAddress;
                std::string _address;
                int _port;
                State _state;
                int _fd;
                bool _mszCommandReceived;
                bool _reconnection = false;
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;
                std::shared_ptr<Zappy::Server::Commands> _commands;

                std::queue<std::string> _responseQueue;
                std::mutex _responseQueueMutex;
                std::condition_variable _responseQueueNotEmpty;
                std::shared_ptr<SharedMemory> _sharedMemory;
                std::thread _sendThread;

                std::string _responseBuffer;

                /**
                 * @brief Connect to the server
                 */
                void _connect();

                /**
                 * @brief Disconnect from the server
                 */
                void _disconnect();

                /**
                 * @brief Close the socket file descriptor
                 */
                void _closeFd();

                /**
                 * @brief Server main loop
                 *
                 * @brief contains the main loop for reading from and writing to the server.
                 */
                void _loop();

                /**
                 * @brief Add a response to the response queue
                 *
                 * @param request The response to add
                 */
                void _addResponse(const std::string &request);

                /**
                 * @brief Handle a response from the server
                 *
                 * @param buffer The response buffer
                 */
                void _handleResponse(const std::string& buffer);

                /**
                 * @brief Read from the server
                 *
                 * @param readfds The set of file descriptors to read from
                 */
                void _readServer(fd_set readfds);

                /**
                 * @brief Write to the server
                 */
                void _writeServer();

                /**
                 * @brief Reconnect to the server
                 */
                void _reconnect();

                /**
                 * @brief Map of command handlers
                 */
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
