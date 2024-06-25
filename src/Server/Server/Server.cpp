/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Server
*/

#include "Server.hpp"

namespace Zappy {
    namespace Server {
        Server::Server(const std::string &address, int port)
        {
            _address = address;
            _port = port;
            _state = TRY_CONNECT;
            _fd = -1;
            _mszCommandReceived = false;
            _commands = std::make_shared<Zappy::Server::Commands>();
            _sharedMemory = std::make_shared<SharedMemory>();
            _commands->setSharedMemory(_sharedMemory);
        }

        void Server::setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources)
        {
            _ressources = ressources;
            _commands->setRessources(_ressources);
        }

        std::shared_ptr<SharedMemory> Server::getSharedMemory()
        {
            return _sharedMemory;
        }

        void Server::run()
        {
            while (_state != DOWN) {
                if (_state == TRY_CONNECT)
                    _connect();
                if (_state == RECONNECT)
                    _reconnect();
                if (_state == CONNECTED)
                    _loop();
                if (_state == DISCONNECT)
                    _disconnect();
                if (_state == DOWN)
                    return;
            }
        }

        void Server::shutdown()
        {
            if (_state != DOWN && _state != DISCONNECT)
                _state = DISCONNECT;
        }

        void Server::_connect()
        {
            if (_fd == -1) {
                _fd = socket(AF_INET, SOCK_STREAM, 0);
                if (_fd == -1) throw Exceptions::ConnexionServeurFail("Failed to create socket", _address, _port);
            }
            _socketAddress.sin_family = AF_INET;
            _socketAddress.sin_port = htons(_port);
            inet_pton(AF_INET, _address.c_str(), &_socketAddress.sin_addr);
            if (connect(_fd, (struct sockaddr *)&_socketAddress, sizeof(_socketAddress)) == -1) return;
            _state = CONNECTED;
            std::string initRequest = "GRAPHIC\n";
            int tmp = write(_fd, initRequest.c_str(), initRequest.size());
            if (tmp == -1) {
                _disconnect();
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
            }
            _sharedMemory->addCommand("msz");
            if (_reconnection) {
                _ressources->logs.push_back(std::make_tuple("Server reconnected !", "Server", "Server"));
                _reconnection = false;
            }
        }

        void Server::_disconnect()
        {
            _closeFd();
            _state = DOWN;
        }

        void Server::_closeFd()
        {
            if (_fd != -1) {
                close(_fd);
                _fd = -1;
            }
        }

        void Server::_loop()
        {
            fd_set readfds;
            struct timeval tv;
            int max_fd = _fd;

            FD_ZERO(&readfds);
            FD_SET(_fd, &readfds);
            tv.tv_sec = 1;
            tv.tv_usec = 0;
            int activity = select(max_fd + 1, &readfds, NULL, NULL, &tv);
            if (activity == -1) {
                _state = RECONNECT;
                return;
            }
            _readServer(readfds);
            _writeServer();

            if (!_ressources->mapSet)
                _sharedMemory->addCommand("msz");
        }

        void Server::_addResponse(const std::string &request)
        {
            std::unique_lock<std::mutex> lock(_responseQueueMutex);
            _responseQueue.push(request);
            _responseQueueNotEmpty.notify_one();
        }

        void Server::_handleResponse(const std::string& buffer)
        {
            std::string command = buffer.substr(0, 3);
            auto commandHandler = _commandHandlers.find(command);
            if (commandHandler != _commandHandlers.end())
                commandHandler->second(buffer);
        }

        void Server::_readServer(fd_set readfds)
        {
            if (FD_ISSET(_fd, &readfds)) {
                char buffer[1024] = {0};
                ssize_t valread = read(_fd, buffer, 1024);
                std::string response(buffer, valread);
                if (valread == 0) {
                    _state = RECONNECT;
                    return;
                }
                if (response.empty()) return;
                _responseBuffer += response;
                std::vector<std::string> responses = Zappy::GUI::split(_responseBuffer, "\n");
                _responseBuffer.clear();
                if (response.size() > 0 && response.back() != '\n') {
                    _responseBuffer = responses.back();
                    responses.pop_back();
                }
                for (const auto &tmp : responses) {
                    if (tmp.empty()) continue;
                    _addResponse(tmp);
                    _handleResponse(tmp);
                }
            }
        }

        void Server::_writeServer()
        {
            if (!_sharedMemory->hasCommands()) return;

            std::string command = _sharedMemory->getCommand();
            while (!command.empty()) {
                int tmp = write(_fd, command.c_str(), command.size());
                if (tmp == -1) {
                    _state = RECONNECT;
                    return;
                }
                command = _sharedMemory->getCommand();
            }
        }

        void Server::_reconnect()
        {
            _closeFd();
            _ressources->logs.push_back(std::make_tuple("Server disconnected", "Server", "Server"));
            _state = TRY_CONNECT;
            _reconnection = true;
        }
    }
}