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
        }

        void Server::setInOut()
        {
            // Set the in and out namepipes -> shared ptr
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
            _loop();
            _fd = -1;
            _state = DOWN;

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
                                addResponse(response);
                            }
                        } else
                            addResponse(response);
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

        void Server::_disconnect()
        {
            close(_fd);
            _state = DOWN;
        }

        void Server::addRequest(const std::string &request)
        {
            std::lock_guard<Mutex> lock(_requestQueueMutex);
            _requestQueue.push(request);
            _requestQueueNotEmpty.notify_one();
        }

        void Server::addResponse(const std::string &response)
        {
            std::lock_guard<Mutex> lock(_responseQueueMutex);
            _responseQueue.push(response);
            _responseQueueNotEmpty.notify_one();
        }
    }
}