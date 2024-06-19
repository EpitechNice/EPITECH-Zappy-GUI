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
    #include <unordered_map>

    #include "TileRessources.hpp"
    #include "Players.hpp"
    #include "Eggs.hpp"

namespace Zappy {
    namespace GUI {
        namespace Ressources {
            /**
             * @brief Ressources class
             */
            class Ressources {
                public:
                    /**
                     * @brief Ressources constructor
                     */
                    Ressources();
                    ~Ressources() = default;

                    /**
                     * @brief Set all the registered player on the map based on their position
                     */
                    void setPlayerOnMap();

                    /**
                     * @brief Register a player
                     *
                     * @param player The player to register
                     */
                    void addPlayer(std::shared_ptr<Players> player);

                    /**
                     * @brief Remove a player
                     *
                     * @param id The id of the player to remove
                     */
                    void removePlayer(int id);

                    /**
                     * @brief Set all the registered egg on the map based on their position
                     */
                    void setEggOnMap();

                    /**
                     * @brief Register an egg
                     *
                     * @param egg The egg to register
                     */
                    void addEgg(std::shared_ptr<Eggs> egg);

                    /**
                     * @brief Remove an egg
                     *
                     * @param id The id of the egg to remove
                     */
                    void removeEgg(int id);

                    /**
                     * @brief A table that represent the map
                     */
                    std::vector<std::vector<std::shared_ptr<TileRessources>>> tileRessources;

                    /**
                     * @brief All the registered players
                     */
                    std::vector<std::shared_ptr<Players>> players;

                    /**
                     * @brief All the registered eggs
                     */
                    std::vector<std::shared_ptr<Eggs>> eggs;

                    /**
                     * @brief The teams color
                     */
                    std::unordered_map<std::string, Color> teamsColor;

                    /**
                     * @brief Register a team
                     *
                     * @param teamName The name of the team
                     */
                    void addTeam(std::string teamName);

                    /**
                     * @brief Get a player from his id
                     *
                     * @param id The id of the player
                     *
                     * @return `std::shared_ptr<Players>` The player. `nullptr` if the player doesn't exist
                     */
                    std::shared_ptr<Players> getPlayerFromId(int id) const;

                    /**
                     * @brief Get an egg from his id
                     *
                     * @param id The id of the egg
                     *
                     * @return `std::shared_ptr<Eggs>` The egg. `nullptr` if the egg doesn't exist
                     */
                    std::shared_ptr<Eggs> getEggFromId(int id) const;

                    /**
                     * @brief Get a tile from his position
                     *
                     * @param posX The x position of the tile
                     * @param posY The y position of the tile
                     *
                     * @return `std::shared_ptr<TileRessources>` The tile. `nullptr` if the tile doesn't exist
                     */
                    std::shared_ptr<Zappy::GUI::Ressources::TileRessources> getTileFromPos(int posX, int posY) const;

                    /**
                     * @brief Get the dimensions of the map
                     *
                     * @return `std::pair<int, int>` The dimensions of the map
                     */
                    std::pair<int, int> getMapDimensions() const;

                    /**
                     * @brief A boolean that represent if the map is set
                     */
                    bool mapSet = false;

                    std::vector<std::tuple<std::string, std::string, std::string>> logs;

                protected:
                private:
            };
        }
    }
}

#endif /* !RESSOURCES_HPP_ */
