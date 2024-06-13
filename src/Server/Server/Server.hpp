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

    #include "Exceptions.hpp"
    #include "Mutex.hpp"

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
                void _disconnect();
                void addRequest(const std::string &request);
                void addResponse(const std::string &request);
        };
    }
}

#endif /* !SERVER_HPP_ */
