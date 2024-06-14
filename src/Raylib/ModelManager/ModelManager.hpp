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

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class ModelManager {
                public:
                    static ModelManager *get();

                    Model getModel(std::string &fileName);
                    void destroy();

                private:
                    ModelManager();
                    ~ModelManager();

                    bool _isDestroyed = false;
                    std::unordered_map<std::string, Model> _models;
            };
        }
    }
}

#endif /* !MODEL_MANAGER_HPP_ */
