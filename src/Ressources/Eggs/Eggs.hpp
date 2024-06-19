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
            /**
             * @brief Eggs class
             */
            class Eggs {
                public:
                    /**
                     * @brief Eggs constructor
                     *
                     * @param id The id of the egg
                     * @param x The x position of the egg
                     * @param y The y position of the egg
                     * @param team The team of the egg
                     */
                    Eggs(int id, int x, int y, std::string team);
                    ~Eggs() = default;

                    /**
                     * @brief Get the id of the egg
                     *
                     * @return `int` The id of the egg
                     */
                    int getId() const;

                    /**
                     * @brief Get the X position of the egg
                     *
                     * @return `int` The X position of the egg
                     */
                    int getX() const;

                    /**
                     * @brief Set the X position of the egg
                     *
                     * @param x The X position of the egg
                     */
                    void setX(int x);

                    /**
                     * @brief Get the Y position of the egg
                     *
                     * @return `int` The Y position of the egg
                     */
                    int getY() const;

                    /**
                     * @brief Set the Y position of the egg
                     *
                     * @param y The Y position of the egg
                     */
                    void setY(int y);

                    /**
                     * @brief Get the team of the egg
                     *
                     * @return `std::string` The team of the egg
                     */
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
