/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentModel
*/

#ifndef COMPONENT_MODEL_3D_HPP_
    #define COMPONENT_MODEL_3D_HPP_

    #include <raylib.h>
    #include <string>
    #include <memory>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Model3D {
                public:
                    Model3D(std::string path, Vector3 pos, float scale, Vector3 rotationAxis = {0, 1, 0}, float angle = 0);
                    ~Model3D();

                    void destroy();

                    void draw();

                    void setOnPosY(float y);
                    void setPos(Vector3 pos);
                protected:
                private:
                    Model _model;
                    Vector3 _pos;
                    float _scale;
                    Vector3 _rotationAxis;
                    float _angle;
                    bool _isDestroyed;
            };
        }
    }
}

#endif /* !COMPONENT_MODEL_3D_HPP_ */
