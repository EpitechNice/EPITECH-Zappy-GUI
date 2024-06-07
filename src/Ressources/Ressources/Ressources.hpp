/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Ressources
*/

#ifndef RESSOURCES_HPP_
    #define RESSOURCES_HPP_

    #include <memory>
    #include <vector>

    #include "TileRessources.hpp"
    #include "Players.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            class Ressources {
                public:
                    static Ressources *get();
                    ~Ressources() = default;

                    void setPlayerOnMap();
                    void addPlayer(std::shared_ptr<Players> player);

                    std::vector<std::vector<std::shared_ptr<TileRessources>>> tileRessources;
                    std::vector<std::shared_ptr<Players>> players;

                    std::shared_ptr<Players> getPlayerFromId(int id) const;

                protected:
                private:
                    Ressources();
            };
        }
    }
}

#endif /* !RESSOURCES_HPP_ */
