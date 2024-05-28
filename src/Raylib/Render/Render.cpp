/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Render
*/

#include "Render.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            Render::Render(int height, int width, int fps)
                : _height(height), _width(width), _fps(fps), _isDestroyed(false)
            {
                InitWindow(width, height, "Zappy");
                SetTargetFPS(fps);
                _icon = LoadImage("assets/img/clash_of_tek_logo.png");
                SetWindowIcon(_icon);
                _view = std::make_shared<View>();
            }

            Render::~Render()
            {
                destroy();
            }

            void Render::destroy()
            {
                if (!_isDestroyed) {
                    UnloadImage(_icon);
                    CloseWindow();
                    _isDestroyed = true;
                }
            }


            std::shared_ptr<View> Render::view() const
            {
                return _view;
            }

            int Render::getHeight() const
            {
                return _height;
            }

            int Render::getWidth() const
            {
                return _width;
            }

            int Render::getFps() const
            {
                return _fps;
            }



            void Render::setHeight(int height)
            {
                _height = height;
                CloseWindow();
                InitWindow(_width, _height, "Zappy");
            }

            void Render::setWidth(int width)
            {
                _width = width;
                CloseWindow();
                InitWindow(_width, _height, "Zappy");
            }

            void Render::setDimensions(int height, int width)
            {
                _height = height;
                _width = width;
                CloseWindow();
                InitWindow(_width, _height, "Zappy");
            }

            void Render::setFps(int fps)
            {
                _fps = fps;
                SetTargetFPS(_fps);
            }
        }
    }
}