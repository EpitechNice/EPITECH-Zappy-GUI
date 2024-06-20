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
                : _height(height), _width(width), _fps(fps), _pathMusiquePrincipal("assets/Musique/ClashofTekMainMusic.wav"), _isDestroyed(false)
            {
                InitWindow(width, height, "Clash Of Tek");
                displayLoadingScreen();
                SetTargetFPS(fps);
                _icon = LoadImage("assets/img/clash_of_tek_logo.png");
                SetWindowIcon(_icon);
                _view = std::make_shared<View>();
                Sfml::SoundManager::getInstance().setMusique(_pathMusiquePrincipal);
                Sfml::SoundManager::getInstance().playgeneralSound();
                ModelManager::get();
                FontManager::get();
                TextureManager::get();
            }

            Render::~Render()
            {
                destroy();
            }

            void Render::destroy()
            {
                if (_isDestroyed) return;
                _musiquePrincipal.stop();
                ModelManager::get()->destroy();
                FontManager::get()->destroy();
                TextureManager::get()->destroy();
                UnloadImage(_icon);
                CloseWindow();
                _isDestroyed = true;
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
                setDimensions(height, _width);
            }

            void Render::setWidth(int width)
            {
                setDimensions(_height, width);
            }

            void Render::setDimensions(int height, int width)
            {
                _height = height;
                _width = width;
                FontManager::get()->unload();
                ModelManager::get()->unload();
                TextureManager::get()->unload();
                CloseWindow();
                InitWindow(_width, _height, "Clash Of Tek");
                displayLoadingScreen();
                TextureManager::get()->reload();
                ModelManager::get()->reload();
                FontManager::get()->reload();
            }

            void Render::setFps(int fps)
            {
                _fps = fps;
                SetTargetFPS(_fps);
            }

            void Render::displayLoadingScreen()
            {
                BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Loading assets...", _width / 2 - 100, _height / 2 - 10, 20, BLACK);
                EndDrawing();
            }
        }
    }
}