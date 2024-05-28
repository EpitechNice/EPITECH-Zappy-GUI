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
            : _isDestroyed(false)
        {
            _render = std::make_shared<Zappy::GUI::Raylib::Render>(600, 1200, 60);

            _scenes["game"] = std::make_shared<Zappy::GUI::Scene::Game>(_render);
            _scenes["menu"] = std::make_shared<Zappy::GUI::Scene::Menu>(_render);
            _scenes["credits"] = std::make_shared<Zappy::GUI::Scene::Credit>(_render);
            _scenes["credit1"] = std::make_shared<Zappy::GUI::Scene::CreditScene>(_render, "texte 1\n exemple de crédit blablaBlaBleabelz\n yjjdssk,x,dcdsdqsxdscdcf\nouzhpuxhaocxysidjcqad\n", 1);
            _scenes["credit2"] = std::make_shared<Zappy::GUI::Scene::CreditScene>(_render, "texte 2\n exemple de crédit blablaBlaBleabelz\n yjjdssk,x,dcdsdqsxdscdcf\nouzhpuxhaocxysidjcqad\n", 2);
            _scenes["credit3"] = std::make_shared<Zappy::GUI::Scene::CreditScene>(_render, "texte 3\n exemple de crédit blablaBlaBleabelz\n yjjdssk,x,dcdsdqsxdscdcf\nouzhpuxhaocxysidjcqad\n", 3);
            _scenes["option"] = std::make_shared<Zappy::GUI::Scene::Option>(_render);
            _scenes["soundSetting"] = std::make_shared<Zappy::GUI::Scene::SoundOption>(_render);
            _scenes["resolutionSetting"] = std::make_shared<Zappy::GUI::Scene::ResolutionOption>(_render);
            _currentScene = "menu";
            _nextScene = "menu";
        }

        SceneManager::~SceneManager()
        {
            destroy();
        }

        void SceneManager::destroy()
        {
            if (_isDestroyed)
                return;
            for (auto &scene : _scenes)
                scene.second->destroy();
            _render->destroy();
            _isDestroyed = true;
        }

        void SceneManager::run()
        {
            while (_currentScene != "end") {
                _scenes[_currentScene]->start();
                while (!WindowShouldClose() && _currentScene != "end") {
                    _scenes[_currentScene]->event();
                    _scenes[_currentScene]->update();
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
                if (_currentScene == _nextScene || _nextScene == "end")
                    _currentScene = "end";
                else {
                    if (_scenes.find(_nextScene) != _scenes.end())
                        _currentScene = _nextScene;
                    else {
                        std::cerr << "Scene " << _nextScene << " not found" << std::endl;
                        _nextScene = _currentScene;
                    }
                }
            }
        }
    }
}