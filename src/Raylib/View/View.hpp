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
                    [[ nodiscard ]] bool isMouseFollowing() const;

                    void setPosition(Vector3 position);
                    void modPosition(Vector3 position);
                    void setTarget(Vector3 target);
                    void modTarget(Vector3 target);
                    void setUp(Vector3 up);
                    void modUp(Vector3 up);
                    void setFovy(float fovy);
                    void modFovy(float fovy);
                    void setMouseFollowing(bool mouseFollowing);

                    void update();

                private:
                    Camera _camera;
                    Vector3 _position;
                    Vector3 _target;
                    Vector3 _up;
                    float _fovy;
                    bool _mouseFollowing;

                    float _speed = 0.15f;
                    float _angle = 0.05f;
                    float _dash = 4.0f;
                    float _sensitivity = 0.003f;


                    Vector3 _getFront();
                    Vector3 _getUp();
                    Vector3 _getSide();
                    void _moveFront(float speed);
                    void _moveSide(float speed);
                    void _moveUp(float speed);
                    void _lookUp(float speed);
                    void _lookSide(float speed);
            };
        }
    }
}

#endif /* !VIEW_HPP_ */
