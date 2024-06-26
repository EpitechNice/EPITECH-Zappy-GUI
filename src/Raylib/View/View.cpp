/*
** EPITECH PROJECT, 2024
** gui
** File description:
** View
*/

#include "View.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            View::View(Vector3 position, Vector3 target, Vector3 up, float fovy)
                : _position(position), _target(target), _up(up), _fovy(fovy), _mouseFollowing(true)
            {
                _camera = (Camera){
                    .position = position,
                    .target = target,
                    .up = up,
                    .fovy = fovy,
                    .projection = CAMERA_PERSPECTIVE
                };
                _enable = true;
                _immersiveFlag = false;
            }



            Camera View::getCamera() const
            {
                return _camera;
            }

            Vector3 View::getPosition() const
            {
                return _position;
            }

            Vector3 View::getTarget() const
            {
                return _target;
            }

            Vector3 View::getUp() const
            {
                return _up;
            }

            float View::getFovy() const
            {
                return _fovy;
            }

            bool View::isMouseFollowing() const
            {
                return _mouseFollowing;
            }



            void View::setPosition(Vector3 position)
            {
                _position = position;
                _camera.position = position;
            }

            void View::modPosition(Vector3 position)
            {
                _position = Vector3Add(_position, position);
                _camera.position = _position;
            }

            void View::setTarget(Vector3 target)
            {
                _target = target;
                _camera.target = target;
            }

            void View::modTarget(Vector3 target)
            {
                _target = Vector3Add(_target, target);
                _camera.target = _target;
            }

            void View::setUp(Vector3 up)
            {
                _up = up;
                _camera.up = up;
            }

            void View::modUp(Vector3 up)
            {
                _up = Vector3Add(_up, up);
                _camera.up = _up;
            }

            void View::setFovy(float fovy)
            {
                _fovy = fovy;
                _camera.fovy = fovy;
            }

            void View::modFovy(float fovy)
            {
                _fovy += fovy;
                _camera.fovy = _fovy;
            }

            void View::setMouseFollowing(bool mouseFollowing)
            {
                _mouseFollowing = mouseFollowing;
            }


            void View::enableCamera()
            {
                _enable = true;
            }

            void View::disableCamera()
            {
                _enable = false;
            }


            void View::update()
            {
                if (!_enable || _immersiveFlag) return;

                int dash = (IsKeyDown(KEY_LEFT_SHIFT)) ? _dash : 1;
                if (IsKeyDown(KEY_W)) _moveFront(_speed * dash);
                if (IsKeyDown(KEY_A)) _moveSide(-_speed * dash);
                if (IsKeyDown(KEY_S)) _moveFront(-_speed * dash);
                if (IsKeyDown(KEY_D)) _moveSide(_speed * dash);

                if (IsKeyDown(KEY_SPACE)) _moveUp(_speed * dash);
                if (IsKeyDown(KEY_LEFT_CONTROL)) _moveUp(-_speed * dash);

                if (IsKeyDown(KEY_DOWN)) _lookUp(-_angle);
                if (IsKeyDown(KEY_UP)) _lookUp(_angle);
                if (IsKeyDown(KEY_RIGHT)) _lookSide(-_angle);
                if (IsKeyDown(KEY_LEFT)) _lookSide(_angle);

                if (_mouseFollowing) {
                    Vector2 mouse = GetMouseDelta();
                    _lookSide(-mouse.x * _sensitivity);
                    _lookUp(-mouse.y * _sensitivity);
                }

                _setFacingDirection();
            }

            View::Direction View::getFacingDirection() const
            {
                return _facingDirection;
            }

            void View::setImmersiveFlag(bool immersiveFlag)
            {
                _immersiveFlag = immersiveFlag;
            }

            bool View::getImmersiveFlag() const
            {
                return _immersiveFlag;
            }


            Vector3 View::_getFront()
            {
                return Vector3Normalize(Vector3Subtract(_target, _position));
            }

            Vector3 View::_getUp()
            {
                return Vector3Normalize(_up);
            }

            Vector3 View::_getSide()
            {
                return Vector3Normalize(Vector3CrossProduct(_getFront(), _getUp()));
            }

            void View::_moveFront(float speed)
            {
                Vector3 front = Vector3Scale(_getFront(), speed);
                setPosition(Vector3Add(_position, front));
                setTarget(Vector3Add(_target, front));
            }

            void View::_moveUp(float speed)
            {
                Vector3 up = Vector3Scale(_getUp(), speed);
                setPosition(Vector3Add(_position, up));
                setTarget(Vector3Add(_target, up));
            }

            void View::_moveSide(float speed)
            {
                Vector3 side = Vector3Scale(_getSide(), speed);
                setPosition(Vector3Add(_position, side));
                setTarget(Vector3Add(_target, side));
            }

            void View::_lookUp(float speed)
            {
                Vector3 right = _getSide();
                setTarget(Vector3Add(_position, Vector3RotateByAxisAngle(Vector3Subtract(_target, _position), right, speed)));
            }

            void View::_lookSide(float speed)
            {
                Vector3 targetPos = Vector3Subtract(_target, _position);
                targetPos = Vector3RotateByAxisAngle(targetPos, _getUp(), speed);
                setTarget(Vector3Add(_position, targetPos));
            }

            void View::_setFacingDirection()
            {
                Vector3 front = _getFront();

                if (front.x > 0.5f)
                    _facingDirection = SOUTH;
                else if (front.x < -0.5f)
                    _facingDirection = NORTH;
                else if (front.z > 0.5f)
                    _facingDirection = EAST;
                else if (front.z < -0.5f)
                    _facingDirection = WEST;
            }
        }
    }
}