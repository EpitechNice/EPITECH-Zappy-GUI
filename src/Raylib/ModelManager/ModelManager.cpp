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
                _models.clear();
                _refs.clear();

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
                for (auto &model : models)
                    getModel(model);
            }

            ModelManager::~ModelManager()
            {
                destroy();
            }

            void ModelManager::destroy()
            {
                if (_isDestroyed) return;
                unload();
                _isDestroyed = true;
            }

            Model ModelManager::getModel(std::string &fileName)
            {
                if (_models.find(fileName) == _models.end()) {
                    std::string modelPath = Zappy::GUI::Path::get()->path() + "models/" + fileName + ".gltf";
                    Model model = LoadModel(modelPath.c_str());
                    _models[fileName] = model;
                    _refs.push_back(fileName);
                    return model;
                }
                return _models[fileName];
            }

            void ModelManager::unload()
            {
                for (auto &model : _models)
                    UnloadModel(model.second);
                _models.clear();
            }

            void ModelManager::reload()
            {
                for (auto &ref: _refs) {
                    std::string modelPath = Zappy::GUI::Path::get()->path() + "models/" + ref + ".gltf";
                    Model model = LoadModel(modelPath.c_str());
                    _models[ref] = model;
                }
            }
        }
    }
}