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
            if (_state == TRY_CONNECT)
                _connect();
            if (_state == CONNECTED)
                _loop();
            if (_state == DISCONNECT)
                _disconnect();
            if (_state == DOWN)
                return;
        }

        void Server::shutdown()
        {
            if (_state != DOWN && _state != DISCONNECT)
                _state = DISCONNECT;
        }

        void Server::_connect()
        {
            _fd = socket(AF_INET, SOCK_STREAM, 0);
            if (_fd == -1)
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
            _socketAddress.sin_family = AF_INET;
            _socketAddress.sin_port = htons(_port);
            inet_pton(AF_INET, _address.c_str(), &_socketAddress.sin_addr);
            if (connect(_fd, (struct sockaddr *)&_socketAddress, sizeof(_socketAddress)) == -1) {
                _disconnect();
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
            }
            _state = CONNECTED;
            std::string initRequest = "GRAPHIC\r\n";
            int tmp = write(_fd, initRequest.c_str(), initRequest.size());
            if (tmp == -1) {
                _disconnect();
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
            }
            _sharedMemory->addCommand("msz\r\n");
            _loop();
        }

        void Server::_disconnect()
        {
            if (_fd != -1) {
                close(_fd);
                _fd = -1;
            }
            _state = DOWN;
        }

        void Server::_loop()
        {
            fd_set readfds;
            struct timeval tv;
            int max_fd = _fd;

            while (_state == CONNECTED) {
                FD_ZERO(&readfds);
                FD_SET(_fd, &readfds);
                tv.tv_sec = 1;
                tv.tv_usec = 0;
                int activity = select(max_fd + 1, &readfds, NULL, NULL, &tv);
                if (activity == -1) {
                    _disconnect();
                    throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
                }
                _readServer(readfds);
                _writeServer();
            }
        }

        void Server::_initRessources(int mapHeight, int mapWidth)
        {
            for (int i = 0; i < mapWidth; i++) {
                std::vector<std::shared_ptr<Zappy::GUI::Ressources::TileRessources>> line;
                for (int j = 0; j < mapHeight; j++) {
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tile = std::make_shared<Zappy::GUI::Ressources::TileRessources>(i, j);
                    line.push_back(tile);
                }
                _ressources->tileRessources.push_back(line);
            }
            _ressources->mapSet = true;
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
            std::string responseValue = buffer.substr(3);

            if (command == "msz") {
                int _heightWorld, _widthWorld;
                std::istringstream iss(responseValue);
                iss >> _heightWorld >> _widthWorld >> std::ws;
                if (iss.fail() || !iss.eof()) {
                    auto commandHandler = _commandHandlers.find("suc");
                    if (commandHandler != _commandHandlers.end())
                        commandHandler->second(responseValue);
                    return;
                }
                auto commandHandler = _commandHandlers.find("msz");
                if (commandHandler != _commandHandlers.end())
                    commandHandler->second(responseValue);
                _initRessources(_heightWorld, _widthWorld);
            } else {
                auto commandHandler = _commandHandlers.find(command);
                if (commandHandler != _commandHandlers.end())
                    commandHandler->second(responseValue);
            }
        }

        void Server::_readServer(fd_set readfds)
        {
            if (FD_ISSET(_fd, &readfds)) {
                char buffer[1024] = {0};
                ssize_t valread = read(_fd, buffer, 1024);
                std::string response(buffer, valread);
                if (valread == 0) Exceptions::ConnexionServeurFail("Connection to server was closed unexpectedly", _address, _port);
                _addResponse(response);
                _handleResponse(response);
            }
        }

        void Server::_writeServer()
        {
            if (!_sharedMemory->hasCommands()) return;

            std::string command = _sharedMemory->getCommand();
            while (!command.empty()) {
                int tmp = write(_fd, command.c_str(), command.size());
                if (tmp == -1) {
                    _disconnect();
                    throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
                }
                command = _sharedMemory->getCommand();
            }
        }
    }
}