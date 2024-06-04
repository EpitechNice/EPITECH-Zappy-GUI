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
                : _height(height), _width(width), _fps(fps), _langue(FRANCAIS), _pathMusiquePrincipal("assets/Musique/ClashofTekMainMusic.wav"), _isDestroyed(false)
            {
                InitWindow(width, height, "Zappy");
                SetTargetFPS(fps);
                _icon = LoadImage("assets/img/clash_of_tek_logo.png");
                SetWindowIcon(_icon);
                _view = std::make_shared<View>();
                Sfml::SoundManager::getInstance().setMusique(_pathMusiquePrincipal);
                Sfml::SoundManager::getInstance().playgeneralSound();
            }

            Render::~Render()
            {
                destroy();
            }

            void Render::destroy()
            {
                if (!_isDestroyed) {
                    _musiquePrincipal.stop();
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

            Langue Render::getLangue() const{
                return _langue;
            }

            void Render::setHeight(int height)
            {
                _height = height;
                SetWindowSize(_width, _height);
            }

            void Render::setWidth(int width)
            {
                _width = width;
                SetWindowSize(_width, _height);
            }

            void Render::setDimensions(int height, int width)
            {
                _height = height;
                _width = width;
                SetWindowSize(_width, _height);
                _icon = LoadImage("assets/img/clash_of_tek_logo.png");
                SetWindowIcon(_icon);
                _view = std::make_shared<View>();
            }


            void Render::setFps(int fps)
            {
                _fps = fps;
                SetTargetFPS(_fps);
            }

            void Render::setLangue(Langue langue){
                _langue = langue;
            }
        }
    }
}