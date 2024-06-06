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
                        Vector3 position = (Vector3){ -7.04f, 11.11f, -27.61f },
                        Vector3 target = (Vector3){-7.03f, 10.26f, -22.33f},
                        Vector3 up = (Vector3){0.0f, 1.0f, 0.0f},
                        float fovy = 45.0f
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

                    void disableCamera();
                    void enableCamera();

                    void update();

                private:
                    Camera _camera;
                    Vector3 _position;
                    Vector3 _target;
                    Vector3 _up;
                    float _fovy;
                    bool _mouseFollowing;
                    bool _enable;

                    float _speed = 0.60f;
                    float _angle = 0.10f;
                    float _dash = 2.0f;
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
