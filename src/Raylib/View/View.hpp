/*
** EPITECH PROJECT, 2024
** gui
** File description:
** View
*/

#ifndef VIEW_HPP_
    #define VIEW_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <iostream>

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class View {
                public:
                    View(
                        Vector3 position = (Vector3){ 0.0f, 0.0f, 5.0f },
                        Vector3 target = (Vector3){0.0f, 0.0f, 0.0f},
                        Vector3 up = (Vector3){0.0f, 1.0f, 0.0f},
                        float fovy = 45.0f,
                        CameraMode mode = CAMERA_FREE
                    );
                    ~View() = default;

                    [[ nodiscard ]] Camera getCamera() const;
                    [[ nodiscard ]] Vector3 getPosition() const;
                    [[ nodiscard ]] Vector3 getTarget() const;
                    [[ nodiscard ]] Vector3 getUp() const;
                    [[ nodiscard ]] float getFovy() const;
                    [[ nodiscard ]] int getMode() const;

                    void setPosition(Vector3 position);
                    void modPosition(Vector3 position);
                    void setTarget(Vector3 target);
                    void modTarget(Vector3 target);
                    void setUp(Vector3 up);
                    void modUp(Vector3 up);
                    void setFovy(float fovy);
                    void modFovy(float fovy);
                    void setMode(CameraMode mode);

                    void update();

                private:
                    Camera _camera;
                    Vector3 _position;
                    Vector3 _target;
                    Vector3 _up;
                    float _fovy;
                    CameraMode _mode;
            };
        }
    }
}

#endif /* !VIEW_HPP_ */
