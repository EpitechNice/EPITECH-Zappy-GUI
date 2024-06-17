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
            _commands = std::make_shared<Zappy::Server::Commands>();
            _address = address;
            _port = port;
            _state = TRY_CONNECT;
        }

        void Server::setInOut()
        {
            // Set the in and out namepipes -> shared ptr
        }

        void Server::setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources)
        {
            _ressources = ressources;
            _commands->setRessources(_ressources);
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

        void Server::_loop()
        {
            fd_set readfds, writefds;
            struct timeval tv;
            int max_fd = _fd;
            bool mszCommandReceived = false;

            while (_state == CONNECTED) {
                FD_ZERO(&readfds);
                FD_ZERO(&writefds);

                FD_SET(_fd, &readfds);
                FD_SET(_fd, &writefds);

                tv.tv_sec = 1;
                tv.tv_usec = 0;

                select(max_fd + 1, &readfds, &writefds, NULL, &tv);
                if (FD_ISSET(_fd, &readfds)) {
                    char buffer[1024] = {0};
                    int valread = read(_fd, buffer, sizeof(buffer));
                    if (valread > 0) {
                        std::string response(buffer, valread);
                        if (!mszCommandReceived) {
                            if (response.find("msz") == 0) {
                                mszCommandReceived = true;
                                _addResponse(response);
                                _handleResponse(response);
                            }
                        } else {
                            _addResponse(response);
                            _handleResponse(response);
                        }
                    }
                }
                if (FD_ISSET(_fd, &writefds)) {
                    std::lock_guard<Mutex> lock(_requestQueueMutex);
                    if (!_requestQueue.empty()) {
                        std::string request = _requestQueue.front();
                        _requestQueue.pop();
                        send(_fd, request.c_str(), request.size(), 0);
                    }
                }
            }
        }

        void Server::_handleResponse(const std::string& buffer)
        {
            std::string command = buffer.substr(0, 3);
            std::string responseValue = buffer.substr(3);

            auto it = _commandHandlers.find(command);
            if (it != _commandHandlers.end()) {
                it->second(responseValue);
            }
        }

        void Server::_disconnect()
        {
            close(_fd);
            _state = DOWN;
        }

        void Server::_addRequest(const std::string &request)
        {
            std::lock_guard<Mutex> lock(_requestQueueMutex);
            _requestQueue.push(request);
            _requestQueueNotEmpty.notify_one();
        }

        void Server::_addResponse(const std::string &response)
        {
            std::lock_guard<Mutex> lock(_responseQueueMutex);
            _responseQueue.push(response);
            _responseQueueNotEmpty.notify_one();
        }
    }
}