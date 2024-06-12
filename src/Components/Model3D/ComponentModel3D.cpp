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
            {
                _posX = pos.x;
                _posY = pos.y;
                _posZ = pos.z;
                _scale = scale;
                _rotationAxis = rotationAxis;
                _angle = angle;

                std::string modelPath = "assets/models/" + path + ".gltf";
                _model = LoadModel(modelPath.c_str());
            }

            void Model3D::destroy()
            {
                if (_isDestroyed) return;
                UnloadModel(_model);
                _isDestroyed = true;
            }


            void Model3D::draw()
            {
                DrawModelEx(_model, { _posX, _posY, _posZ }, _rotationAxis, _angle, { _scale, _scale, _scale }, WHITE);
            }


            void Model3D::setOnPosY(float y)
            {
                BoundingBox box = GetModelBoundingBox(_model);
                _posY =  y + (box.max.y - box.min.y) / 2 * _scale;
            }
        }
    }
}