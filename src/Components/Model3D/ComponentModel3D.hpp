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
            /**
             * @brief Model3D component
             */
            class Model3D: public AComponent {
                public:
                    /**
                     * @brief Construct a new Model3D object
                     *
                     * @param path Path to the model
                     * @param pos Position of the model
                     * @param scale Scale of the model
                     * @param rotationAxis Rotation axis of the model. Default is {0, 1, 0}
                     * @param angle Angle of the model. Default is 0
                     *
                     * @warning The font will be loaded using the ModelManager. So it must be in the 'assets/models/' folder and it must be a '.gltf' file
                     * @warning This function should be called in the raylib context
                     */
                    Model3D(std::string path, Vector3 pos, float scale, Vector3 rotationAxis = {0, 1, 0}, float angle = 0);

                    /**
                     * @brief Draw the model
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the model
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Set the position of the model on th y value on the Y axis
                     *
                     * @param y The new position on the Y axis
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void setOnPosY(float y);

                protected:
                private:
                    Model _model;
                    float _scale;
                    Vector3 _rotationAxis;
                    float _angle;
                    std::string _path;
            };
        }
    }
}

#endif /* !COMPONENT_MODEL_3D_HPP_ */
