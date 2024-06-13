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
            close(_fd);
            _state = DISCONNECT;
        }

        void Server::_connect()
        {
            _fd = socket(AF_INET, SOCK_STREAM, 0);
            if (_fd == -1)
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);

            _socketAddress.sin_family = AF_INET;
            _socketAddress.sin_port = htons(_port);
            _socketAddress.sin_addr.s_addr = std::stoi(_address);

            if (connect(_fd, (struct sockaddr *)&_socketAddress, sizeof(_socketAddress)) == -1) {
                shutdown();
                throw Exceptions::ConnexionServeurFail("Connection to server failed", _address, _port);
            }
             _state = CONNECTED;
            //looplose(_fd);
            _fd = -1;
            _state = DOWN;
        }

        void Server::_loop()
        {
            // Loop to get the data from the server
        }

        void Server::_disconnect()
        {
            // Disconnect from the server
            _state = DOWN;
        }
    }
}