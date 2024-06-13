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
            // Connect to the server
            _state = CONNECTED;
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