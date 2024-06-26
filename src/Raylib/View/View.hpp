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
            /**
             * @brief View class. This class is used to manage the camera
             */
            class View {
                public:
                    /**
                     * @brief Construct a new View object
                     *
                     * @param position The position of the camera. Default is (-7.04f, 11.11f, -27.61f)
                     * @param target The target of the camera. Default is (-7.03f, 10.26f, -22.33f)
                     * @param up The up of the camera. Default is (0.0f, 1.0f, 0.0f)
                     * @param fovy The fovy of the camera. Default is 45.0f
                     */
                    View(
                        Vector3 position = (Vector3){ -7.04f, 11.11f, -27.61f },
                        Vector3 target = (Vector3){-7.03f, 10.26f, -22.33f},
                        Vector3 up = (Vector3){0.0f, 1.0f, 0.0f},
                        float fovy = 45.0f
                    );
                    ~View() = default;

                    /**
                     * @brief Get the camera
                     *
                     * @return `Camera` The camera
                     */
                    [[ nodiscard ]] Camera getCamera() const;

                    /**
                     * @brief Get the position of the camera
                     *
                     * @return `Vector3` The position of the camera
                     */
                    [[ nodiscard ]] Vector3 getPosition() const;

                    /**
                     * @brief Get the target of the camera
                     *
                     * @return `Vector3` The target of the camera
                     */
                    [[ nodiscard ]] Vector3 getTarget() const;

                    /**
                     * @brief Get the up of the camera
                     *
                     * @return `Vector3` The up of the camera
                     */
                    [[ nodiscard ]] Vector3 getUp() const;

                    /**
                     * @brief Get the fovy of the camera
                     *
                     * @return `float` The fovy of the camera
                     */
                    [[ nodiscard ]] float getFovy() const;

                    /**
                     * @brief Get if the camera is following the mouse
                     *
                     * @return `bool` True if the camera is following the mouse, false otherwise
                     */
                    [[ nodiscard ]] bool isMouseFollowing() const;

                    /**
                     * @brief Set the position of the camera
                     *
                     * @param position The new position of the camera
                     */
                    void setPosition(Vector3 position);

                    /**
                     * @brief Mod the position of the camera
                     *
                     * @param position The position to add to the current position
                     */
                    void modPosition(Vector3 position);

                    /**
                     * @brief Set the target of the camera
                     *
                     * @param target The new target of the camera
                     */
                    void setTarget(Vector3 target);

                    /**
                     * @brief Mod the target of the camera
                     *
                     * @param target The target to add to the current target
                     */
                    void modTarget(Vector3 target);

                    /**
                     * @brief Set the up of the camera
                     *
                     * @param up The new up of the camera
                     */
                    void setUp(Vector3 up);

                    /**
                     * @brief Mod the up of the camera
                     *
                     * @param up The up to add to the current up
                     */
                    void modUp(Vector3 up);

                    /**
                     * @brief Set the fovy of the camera
                     *
                     * @param fovy The new fovy of the camera
                     */
                    void setFovy(float fovy);

                    /**
                     * @brief Mod the fovy of the camera
                     *
                     * @param fovy The fovy to add to the current fovy
                     */
                    void modFovy(float fovy);

                    /**
                     * @brief Set if the camera is following the mouse
                     *
                     * @param mouseFollowing True if the camera is following the mouse, false otherwise
                     */
                    void setMouseFollowing(bool mouseFollowing);

                    /**
                     * @brief Disable the camera
                     */
                    void disableCamera();

                    /**
                     * @brief Enable the camera
                     */
                    void enableCamera();

                    /**
                     * @brief Update the camera
                     */
                    void update();

                    typedef enum {
                        NORTH,
                        EAST,
                        SOUTH,
                        WEST
                    } Direction;

                    /**
                     * @brief Get the facing direction of the camera
                     *
                     * @return `Direction` The facing direction of the camera
                     */
                    [[ nodiscard ]] Direction getFacingDirection() const;

                private:
                    Camera _camera;
                    Vector3 _position;
                    Vector3 _target;
                    Vector3 _up;
                    float _fovy;
                    bool _mouseFollowing;
                    bool _enable;
                    Direction _facingDirection = NORTH;

                    float _speed = 0.60f;
                    float _angle = 0.10f;
                    float _dash = 2.0f;
                    float _sensitivity = 0.003f;

                    /**
                     * @brief Get the front movement of the camera
                     */
                    Vector3 _getFront();

                    /**
                     * @brief Get the up movement of the camera
                     */
                    Vector3 _getUp();

                    /**
                     * @brief Get the side movement of the camera
                     */
                    Vector3 _getSide();

                    /**
                     * @brief Move the camera front
                     *
                     * @param speed The speed of the movement
                     */
                    void _moveFront(float speed);

                    /**
                     * @brief Move the camera side
                     *
                     * @param speed The speed of the movement
                     */
                    void _moveSide(float speed);

                    /**
                     * @brief Move the camera up
                     *
                     * @param speed The speed of the movement
                     */
                    void _moveUp(float speed);

                    /**
                     * @brief Look up
                     *
                     * @param speed The speed of the movement
                     */
                    void _lookUp(float speed);

                    /**
                     * @brief Look down
                     *
                     * @param speed The speed of the movement
                     */
                    void _lookSide(float speed);

                    /**
                     * @brief Set the facing direction of the camera
                     */
                    void _setFacingDirection();
            };
        }
    }
}

#endif /* !VIEW_HPP_ */
