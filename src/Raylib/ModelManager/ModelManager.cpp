/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ModelManager
*/

#include "ModelManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            ModelManager *ModelManager::get()
            {
                static ModelManager instance;
                return &instance;
            }

            ModelManager::ModelManager()
            {
                std::vector<std::string> models = {
                    "Food/scene",
                    "Egg/scene",
                    "Rocks/rock_1/rock",
                    "Rocks/rock_2/rock",
                    "Rocks/rock_3/rock",
                    "Rocks/rock_4/rock",
                    "Rocks/rock_5/rock",
                    "Rocks/rock_6/rock",
                    "Zappy/scene"
                };
                for (auto &model : models) {
                    getModel(model);
                }
            }

            ModelManager::~ModelManager()
            {
                destroy();
            }

            Model ModelManager::getModel(std::string &fileName)
            {
                if (_models.find(fileName) == _models.end()) {
                    std::string modelPath = "assets/models/" + fileName + ".gltf";
                    Model model = LoadModel(modelPath.c_str());
                    _models[fileName] = model;
                    return model;
                }
                return _models[fileName];
            }

            void ModelManager::destroy()
            {
                if (_isDestroyed) return;
                for (auto &model : _models) {
                    UnloadModel(model.second);
                }
                _isDestroyed = true;
            }
        }
    }
}