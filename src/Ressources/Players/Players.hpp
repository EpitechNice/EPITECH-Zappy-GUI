/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Players
*/

#ifndef RESSOURCES_PLAYERS_HPP_
    #define RESSOURCES_PLAYERS_HPP_

    #include <raylib.h>

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            class Players {
                public:
                    Players(int id, int x, int y, Color team);
                    ~Players() = default;

                    int getId() const;

                    int getX() const;
                    void setX(int x);

                    int getY() const;
                    void setY(int y);

                    int getLinemate() const;
                    void setLinemate(int linemate);

                    int getDeraumere() const;
                    void setDeraumere(int deraumere);

                    int getSibur() const;
                    void setSibur(int sibur);

                    int getMendiane() const;
                    void setMendiane(int mendiane);

                    int getPhiras() const;
                    void setPhiras(int phiras);

                    int getThystame() const;
                    void setThystame(int thystame);

                    int getFood() const;
                    void setFood(int food);

                    Color getTeam() const;

                protected:
                private:
                    int _id;
                    int _x;
                    int _y;
                    int _linemate;
                    int _deraumere;
                    int _sibur;
                    int _mendiane;
                    int _phiras;
                    int _thystame;
                    int _food;
                    Color _team;
            };
        }
    }
}

#endif /* !RESSOURCES_PLAYERS_HPP_ */
