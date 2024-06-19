/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Players
*/

#ifndef RESSOURCES_PLAYERS_HPP_
    #define RESSOURCES_PLAYERS_HPP_

    #include <raylib.h>
    #include <string>

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            /**
             * @brief Players class
             */
            class Players {
                public:
                    /**
                     * @brief Players constructor
                     *
                     * @param id The id of the player
                     * @param x The x position of the player
                     * @param y The y position of the player
                     * @param team The team of the player
                     */
                    Players(int id, int x, int y, std::string team);
                    ~Players() = default;

                    /**
                     * @brief Get the id of the player
                     *
                     * @return `int` The id of the player
                     */
                    int getId() const;

                    /**
                     * @brief Get the X position of the player
                     *
                     * @return `int` The X position of the player
                     */
                    int getX() const;

                    /**
                     * @brief Set the X position of the player
                     *
                     * @param x The X position of the player
                     */
                    void setX(int x);

                    /**
                     * @brief Get the Y position of the player
                     *
                     * @return `int` The Y position of the player
                     */
                    int getY() const;

                    /**
                     * @brief Set the Y position of the player
                     *
                     * @param y The Y position of the player
                     */
                    void setY(int y);

                    /**
                     * @brief Get the linemate in the player inventory
                     *
                     * @return `int` The linemate in the player inventory
                     */
                    int getLinemate() const;

                    /**
                     * @brief Set the linemate in the player inventory
                     *
                     * @param linemate The linemate in the player inventory
                     */
                    void setLinemate(int linemate);

                    /**
                     * @brief Get the deraumere in the player inventory
                     *
                     * @return `int` The deraumere in the player inventory
                     */
                    int getDeraumere() const;

                    /**
                     * @brief Set the deraumere in the player inventory
                     *
                     * @param deraumere The deraumere in the player inventory
                     */
                    void setDeraumere(int deraumere);

                    /**
                     * @brief Get the sibur in the player inventory
                     *
                     * @return `int` The sibur in the player inventory
                     */
                    int getSibur() const;

                    /**
                     * @brief Set the sibur in the player inventory
                     *
                     * @param sibur The sibur in the player inventory
                     */
                    void setSibur(int sibur);

                    /**
                     * @brief Get the mendiane in the player inventory
                     *
                     * @return `int` The mendiane in the player inventory
                     */
                    int getMendiane() const;

                    /**
                     * @brief Set the mendiane in the player inventory
                     *
                     * @param mendiane The mendiane in the player inventory
                     */
                    void setMendiane(int mendiane);

                    /**
                     * @brief Get the phiras in the player inventory
                     *
                     * @return `int` The phiras in the player inventory
                     */
                    int getPhiras() const;

                    /**
                     * @brief Set the phiras in the player inventory
                     *
                     * @param phiras The phiras in the player inventory
                     */
                    void setPhiras(int phiras);

                    /**
                     * @brief Get the thystame in the player inventory
                     *
                     * @return `int` The thystame in the player inventory
                     */
                    int getThystame() const;

                    /**
                     * @brief Set the thystame in the player inventory
                     *
                     * @param thystame The thystame in the player inventory
                     */
                    void setThystame(int thystame);

                    /**
                     * @brief Get the food in the player inventory
                     *
                     * @return `int` The food in the player inventory
                     */
                    int getFood() const;

                    /**
                     * @brief Set the food in the player inventory
                     *
                     * @param food The food in the player inventory
                     */
                    void setFood(int food);

                    /**
                     * @brief Get the team of the player
                     *
                     * @return `std::string` The team of the player
                     */
                    std::string getTeam() const;

                    /**
                     * @brief Get the level of the player
                     *
                     * @return `int` The level of the player
                     */
                    int getLvl() const;

                    /**
                     * @brief Set the level of the player
                     *
                     * @param lvl The level of the player
                     */
                    void setLvl(int lvl);

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
                    std::string _team;
                    int _lvl;
            };
        }
    }
}

#endif /* !RESSOURCES_PLAYERS_HPP_ */
