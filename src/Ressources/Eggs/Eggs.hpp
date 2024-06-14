/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Eggs
*/

#ifndef RESSOURCES_EGGS_HPP_
    #define RESSOURCES_EGGS_HPP_

    #include <raylib.h>
    #include <string>

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            class Eggs {
                public:
                    Eggs(int id, int x, int y, std::string team);
                    ~Eggs() = default;

                    int getId() const;

                    int getX() const;
                    void setX(int x);

                    int getY() const;
                    void setY(int y);

                    std::string getTeam() const;

                protected:
                private:
                    int _id;
                    int _x;
                    int _y;
                    std::string _team;
            };
        }
    }
}

#endif /* !RESSOURCES_EGGS_HPP_ */
