/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Server
*/

#include "Server.hpp"
#include <chrono>
#include <thread>

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

        void Server::setRessources(std::shared_ptr<Zappy::GUI::Ressources::Ressources> ressources)
        {
            _ressources = ressources;
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

            std::this_thread::sleep_for(std::chrono::seconds(5));
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
            _ressources->mapSet = true;
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