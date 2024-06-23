/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ModelManager
*/

#ifndef MODEL_MANAGER_HPP_
    #define MODEL_MANAGER_HPP_

    #include <raylib.h>
    #include <unordered_map>
    #include <string>
    #include <vector>

    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            /**
             * @brief ModelManager class
             *
             * @note This class is a singleton
             */
            class ModelManager {
                public:
                    /**
                     * @brief Get the ModelManager instance
                     */
                    static ModelManager *get();

                    /**
                     * @brief Get a model
                     *
                     * @param fileName The model file name
                     *
                     * @return `model` The model
                     *
                     * @note This function will load the model if it's not already loaded
                     */
                    Model getModel(std::string &fileName);

                    /**
                     * @brief Destroy the ModelManager instance
                     *
                     * @warning After the destruction of the instance, you won't be able to use it anymore
                     */
                    void destroy();

                    /**
                     * @brief Unload all the models
                     *
                     * @note This function do not clear the references
                     */
                    void unload();

                    /**
                     * @brief Reload all the models from the references
                     */
                    void reload();

                private:
                    ModelManager();
                    ~ModelManager();

                    bool _isDestroyed = false;
                    std::unordered_map<std::string, Model> _models;
                    std::vector<std::string> _refs;
            };
        }
    }
}

#endif /* !MODEL_MANAGER_HPP_ */
