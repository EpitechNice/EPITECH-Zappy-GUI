/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SceneManager
*/

#include "SceneManager.hpp"

namespace Zappy {
    namespace GUI {
        SceneManager::SceneManager()
        {
            _scenes["game"] = std::make_shared<Zappy::GUI::Scene::Game>();
            _scenes["menu"] = std::make_shared<Zappy::GUI::Scene::Menu>();
            _scenes["option"] = std::make_shared<Zappy::GUI::Scene::Option>();
            _currentScene = "menu";
            _nextScene = "menu";

            _render = std::make_shared<Zappy::GUI::Raylib::Render>(600, 800, 60);
        }

        SceneManager::~SceneManager()
        {
        }

        void SceneManager::run()
        {
            while (_currentScene != "end") {
                _scenes[_currentScene]->start();
                while (!WindowShouldClose() && _currentScene != "end") {
                    _scenes[_currentScene]->event();
                    _render->view()->update();

                    BeginDrawing();
                    ClearBackground(RAYWHITE);
                    BeginMode3D(_render->view()->getCamera());
                    _scenes[_currentScene]->draw3D();
                    EndMode3D();
                    _scenes[_currentScene]->draw2D();
                    EndDrawing();
                    _nextScene = _scenes[_currentScene]->nextScene();
                    if (_currentScene != _nextScene)
                        break;
                }
                if (_currentScene == _nextScene)
                    _currentScene = "end";
                else
                    _currentScene = _nextScene;
            }
        }
    }
}