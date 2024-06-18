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
        }

        // Server::~Server()
        // {
        // }


        void Server::setInOut()
        {
            // Set the in and out namepipes -> shared ptr
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
                throw Exceptions::ConnectionServerFail("Connection to server failed", _address, _port);
            _socketAddress.sin_family = AF_INET;
            _socketAddress.sin_port = htons(_port);
            inet_pton(AF_INET, _address.c_str(), &_socketAddress.sin_addr);
            if (connect(_fd, (struct sockaddr *)&_socketAddress, sizeof(_socketAddress)) == -1) {
                _disconnect();
                throw Exceptions::ConnectionServerFail("Connection to server failed", _address, _port);
            }
            _state = CONNECTED;
            std::string initRequest = "GRAPHIC\r\n";
            send(_fd, initRequest.c_str(), initRequest.size(), 0);

            for (int i = 0; i < 10; i++) {
                std::vector<std::shared_ptr<Zappy::GUI::Ressources::TileRessources>> line;
                for (int j = 0; j < 10; j++) {
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> tile = std::make_shared<Zappy::GUI::Ressources::TileRessources>(i, j);
                    tile->setLinemate(rand() % 2);
                    tile->setDeraumere(rand() % 2);
                    tile->setSibur(rand() % 2);
                    tile->setMendiane(rand() % 2);
                    tile->setPhiras(rand() % 2);
                    tile->setThystame(rand() % 2);
                    line.push_back(tile);
                }
                _ressources->tileRessources.push_back(line);
            }

            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(1, 0, 0, "team1"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(2, 0, 0, "team2"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(3, 1, 0, "team3"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(4, 0, 1, "team2"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(5, 1, 1, "team1"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(6, 1, 1, "team4"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(7, 1, 1, "team2"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(8, 4, 3, "team1"));
            _ressources->addPlayer(std::make_shared<Zappy::GUI::Ressources::Players>(9, 1, 0, "team3"));

            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(1, 0, 0, "team1"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(2, 0, 0, "team2"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(3, 1, 0, "team3"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(4, 0, 1, "team2"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(5, 1, 1, "team1"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(6, 1, 1, "team4"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(7, 1, 1, "team2"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(8, 4, 3, "team1"));
            _ressources->addEgg(std::make_shared<Zappy::GUI::Ressources::Eggs>(9, 1, 0, "team3"));

            _ressources->mapSet = true;

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
                    throw Exceptions::ConnectionServerFail("Connection to server failed", _address, _port);
                }
                if (FD_ISSET(_fd, &readfds)) {
                    char buffer[1024] = {0};
                    ssize_t valread = read(_fd, buffer, 1024);
                    std::string response(buffer, valread);
                    if (valread == 0) {
                        std::cerr << "server close connexion" << std::endl;
                        _disconnect();
                        break;
                    }
                    if (!_mszCommandReceived) {
                        if (response.find("msz") == 0) {
                            _mszCommandReceived = true;
                            _addResponse(response);
                            _handleResponse(response);
                        }
                    } else {
                        _addResponse(response);
                        _handleResponse(response);
                    }
                }
                if (_sharedMemory->hasCommands()) {
                    std::string command = _sharedMemory->getCommand();
                    write(_fd, command.c_str(), command.size());
                }
            }
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

            auto commandHandler = _commandHandlers.find(command);
            if (commandHandler != _commandHandlers.end()) {
                commandHandler->second(responseValue);
            }
        }
    }
}