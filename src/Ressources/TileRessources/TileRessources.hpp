/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** TileRessources
*/

#ifndef TILE_RESSOURCES_HPP_
    #define TILE_RESSOURCES_HPP_

    #include "Players.hpp"
    #include "Eggs.hpp"
    #include <vector>
    #include <memory>

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            /**
             * @brief TileRessources class
             */
            class TileRessources {
                public:
                    /**
                     * @brief TileRessources constructor
                     *
                     * @param x The x position of the tile
                     * @param y The y position of the tile
                     */
                    TileRessources(int x, int y);
                    ~TileRessources() = default;

                    /**
                     * @brief Get the X position of the tile
                     *
                     * @return `int` The X position of the tile
                     */
                    int getX() const;

                    /**
                     * @brief Get the Y position of the tile
                     *
                     * @return `int` The Y position of the tile
                     */
                    int getY() const;

                    /**
                     * @brief Get the food on the tile
                     *
                     * @return `int` The food on the tile
                     */
                    int getFood() const;

                    /**
                     * @brief Set the food on the tile
                     *
                     * @param food The food on the tile
                     */
                    void setFood(int food);

                    /**
                     * @brief Check if the tile has food
                     *
                     * @return `bool` True if the tile has food, false otherwise
                     */
                    bool hasFood() const;

                    /**
                     * @brief Get the linemate on the tile
                     *
                     * @return `int` The linemate on the tile
                     */
                    int getLinemate() const;

                    /**
                     * @brief Set the linemate on the tile
                     *
                     * @param linemate The linemate on the tile
                     */
                    void setLinemate(int linemate);

                    /**
                     * @brief Check if the tile has linemate
                     *
                     * @return `bool` True if the tile has linemate, false otherwise
                     */
                    bool hasLinemate() const;

                    /**
                     * @brief Get the deraumere on the tile
                     *
                     * @return `int` The deraumere on the tile
                     */
                    int getDeraumere() const;

                    /**
                     * @brief Set the deraumere on the tile
                     *
                     * @param deraumere The deraumere on the tile
                     */
                    void setDeraumere(int deraumere);

                    /**
                     * @brief Check if the tile has deraumere
                     *
                     * @return `bool` True if the tile has deraumere, false otherwise
                     */
                    bool hasDeraumere() const;

                    /**
                     * @brief Get the sibur on the tile
                     *
                     * @return `int` The sibur on the tile
                     */
                    int getSibur() const;

                    /**
                     * @brief Set the sibur on the tile
                     *
                     * @param sibur The sibur on the tile
                     */
                    void setSibur(int sibur);

                    /**
                     * @brief Check if the tile has sibur
                     *
                     * @return `bool` True if the tile has sibur, false otherwise
                     */
                    bool hasSibur() const;

                    /**
                     * @brief Get the mendiane on the tile
                     *
                     * @return `int` The mendiane on the tile
                     */
                    int getMendiane() const;

                    /**
                     * @brief Set the mendiane on the tile
                     *
                     * @param mendiane The mendiane on the tile
                     */
                    void setMendiane(int mendiane);

                    /**
                     * @brief Check if the tile has mendiane
                     *
                     * @return `bool` True if the tile has mendiane, false otherwise
                     */
                    bool hasMendiane() const;

                    /**
                     * @brief Get the phiras on the tile
                     *
                     * @return `int` The phiras on the tile
                     */
                    int getPhiras() const;

                    /**
                     * @brief Set the phiras on the tile
                     *
                     * @param phiras The phiras on the tile
                     */
                    void setPhiras(int phiras);

                    /**
                     * @brief Check if the tile has phiras
                     *
                     * @return `bool` True if the tile has phiras, false otherwise
                     */
                    bool hasPhiras() const;

                    /**
                     * @brief Get the thystame on the tile
                     *
                     * @return `int` The thystame on the tile
                     */
                    int getThystame() const;

                    /**
                     * @brief Set the thystame on the tile
                     *
                     * @param thystame The thystame on the tile
                     */
                    void setThystame(int thystame);

                    /**
                     * @brief Check if the tile has thystame
                     *
                     * @return `bool` True if the tile has thystame, false otherwise
                     */
                    bool hasThystame() const;

                    /**
                     * @brief Get the players on the tile
                     *
                     * @return `std::vector<std::shared_ptr<Players>>` The players on the tile
                     */
                    std::vector<std::shared_ptr<Players>> getPlayers() const;

                    /**
                     * @brief Clear the players on the tile
                     */
                    void clearPlayers();

                    /**
                     * @brief Register a player
                     *
                     * @param player The player to register
                     */
                    void addPlayer(std::shared_ptr<Players> player);

                    /**
                     * @brief Check if the tile has players
                     *
                     * @return `bool` True if the tile has players, false otherwise
                     */
                    bool hasPlayers() const;

                    /**
                     * @brief Get the eggs on the tile
                     *
                     * @return `std::vector<std::shared_ptr<Eggs>>` The eggs on the tile
                     */
                    std::vector<std::shared_ptr<Eggs>> getEggs() const;

                    /**
                     * @brief Clear the eggs on the tile
                     */
                    void clearEggs();

                    /**
                     * @brief Register an egg
                     *
                     * @param egg The egg to register
                     */
                    void addEgg(std::shared_ptr<Eggs> egg);

                    /**
                     * @brief Check if the tile has eggs
                     *
                     * @return `bool` True if the tile has eggs, false otherwise
                     */
                    bool hasEggs() const;

                protected:
                private:
                    int _x;
                    int _y;
                    int _food;
                    int _linemate;
                    int _deraumere;
                    int _sibur;
                    int _mendiane;
                    int _phiras;
                    int _thystame;
                    std::vector<std::shared_ptr<Players>> _players;
                    std::vector<std::shared_ptr<Eggs>> _eggs;
            };
        }
    }
}

#endif /* !TILE_RESSOURCES_HPP_ */
