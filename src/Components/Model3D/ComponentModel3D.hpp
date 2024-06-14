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

    #include "AComponent.hpp"
    #include "ModelManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Model3D: public AComponent {
                public:
                    Model3D(std::string path, Vector3 pos, float scale, Vector3 rotationAxis = {0, 1, 0}, float angle = 0);

                    void draw() override;

                    void setOnPosY(float y);
                protected:
                private:
                    Model _model;
                    float _scale;
                    Vector3 _rotationAxis;
                    float _angle;
            };
        }
    }
}

#endif /* !COMPONENT_MODEL_3D_HPP_ */
