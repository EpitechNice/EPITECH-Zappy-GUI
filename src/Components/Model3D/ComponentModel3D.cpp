/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentModel
*/

#include "ComponentModel3D.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Model3D::Model3D(std::string path, Vector3 pos, float scale, Vector3 rotationAxis, float angle)
                : _pos(pos), _scale(scale), _rotationAxis(rotationAxis), _angle(angle), _isDestroyed(false)
            {
                std::string modelPath = "assets/models/" + path + ".gltf";
                _model = LoadModel(modelPath.c_str());
            }

            Model3D::~Model3D()
            {
                destroy();
            }

            void Model3D::destroy()
            {
                if (_isDestroyed)
                    return;
                UnloadModel(_model);
                _isDestroyed = true;
            }


            void Model3D::draw()
            {
                DrawModelEx(_model, _pos, _rotationAxis, _angle, (Vector3){_scale, _scale, _scale}, WHITE);
            }


            void Model3D::setOnPosY(float y)
            {
                BoundingBox box = GetModelBoundingBox(_model);
                float modelHeight = box.max.y - box.min.y;
                _pos.y = y + modelHeight / 2 * _scale;
            }

            void Model3D::setPos(Vector3 pos)
            {
                _pos = pos;
            }
        }
    }
}