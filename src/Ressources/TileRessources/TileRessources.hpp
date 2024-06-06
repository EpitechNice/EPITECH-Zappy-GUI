/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TileRessources
*/

#ifndef TILE_RESSOURCES_HPP_
    #define TILE_RESSOURCES_HPP_

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            class TileRessources {
                public:
                    TileRessources();
                    ~TileRessources() = default;

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

                    int getPlayer() const;
                    void setPlayer(int player);
                    bool hasPlayer() const;

                protected:
                private:
                    int _food;
                    int _egg;
                    int _linemate;
                    int _deraumere;
                    int _sibur;
                    int _mendiane;
                    int _phiras;
                    int _thystame;
                    int _player;
            };
        }
    }
}

#endif /* !TILE_RESSOURCES_HPP_ */
