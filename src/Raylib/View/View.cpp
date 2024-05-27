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
            View::View(
                Vector3 position,
                Vector3 target,
                Vector3 up,
                float fovy,
                CameraMode mode
            )
                : _position(position), _target(target), _up(up), _fovy(fovy), _mode(mode)
            {
                _camera = (Camera){
                    .position = position,
                    .target = target,
                    .up = up,
                    .fovy = fovy,
                    .projection = CAMERA_PERSPECTIVE
                };
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

            int View::getMode() const
            {
                return _mode;
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

            void View::setMode(CameraMode mode)
            {
                _mode = mode;
            }



            void View::update()
            {
                UpdateCamera(&_camera, _mode);
            }
        }
    }
}