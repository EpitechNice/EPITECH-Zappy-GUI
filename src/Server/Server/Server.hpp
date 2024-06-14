/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Server
*/

#ifndef SERVER_HPP_
    #define SERVER_HPP_

    #include <string>

    #include "Ref.hpp"

namespace Zappy {
    namespace Server {
        class Server {
            public:
                Server(const std::string &address, int port);
                ~Server() = default;

                void run();
                void shutdown();

                void setInOut(); // set the in and out namepipes -> shared ptr
                void setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources);

            protected:
            private:
                typedef enum {
                    TRY_CONNECT,
                    CONNECTED,
                    DISCONNECT,
                    DOWN
                } State;

                std::string _address;
                int _port;
                State _state;
                int _fd;
                std::shared_ptr<Zappy::GUI::Ressources::Ressources> _ressources;

                // namepipe in
                // namepipe out

                void _connect();
                void _loop();
                void _disconnect();
        };
    }
}

#endif /* !SERVER_HPP_ */
