/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TileRessources
*/

#ifndef TILE_RESSOURCES_HPP_
    #define TILE_RESSOURCES_HPP_

    #include "Players.hpp"
    #include <vector>
    #include <memory>

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            class TileRessources {
                public:
                    TileRessources(int x, int y);
                    ~TileRessources() = default;

                    int getX() const;
                    int getY() const;

                    int getFood() const;
                    void setFood(int food);
                    bool hasFood() const;

                    int getEgg() const;
                    void setEgg(int egg);
                    bool hasEgg() const;

                    int getLinemate() const;
                    void setLinemate(int linemate);
                    bool hasLinemate() const;

                    int getDeraumere() const;
                    void setDeraumere(int deraumere);
                    bool hasDeraumere() const;

                    int getSibur() const;
                    void setSibur(int sibur);
                    bool hasSibur() const;

                    int getMendiane() const;
                    void setMendiane(int mendiane);
                    bool hasMendiane() const;

                    int getPhiras() const;
                    void setPhiras(int phiras);
                    bool hasPhiras() const;

                    int getThystame() const;
                    void setThystame(int thystame);
                    bool hasThystame() const;

                    std::vector<std::shared_ptr<Players>> getPlayers() const;
                    void clearPlayers();
                    void addPlayer(std::shared_ptr<Players> player);
                    bool hasPlayers() const;

                protected:
                private:
                    int _x;
                    int _y;
                    int _food;
                    int _egg;
                    int _linemate;
                    int _deraumere;
                    int _sibur;
                    int _mendiane;
                    int _phiras;
                    int _thystame;
                    std::vector<std::shared_ptr<Players>> _players;
            };
        }
    }
}

#endif /* !TILE_RESSOURCES_HPP_ */
