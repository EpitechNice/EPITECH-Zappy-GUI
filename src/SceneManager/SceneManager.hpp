/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
    #define SCENEMANAGER_HPP_

    #include <unordered_map>
    #include <string>
    #include <iostream>
    #include <memory>

    #include "Render.hpp"
    #include "IScene.hpp"
    #include "GameScene.hpp"
    #include "MenuScene.hpp"
    #include "OptionScene.hpp"

namespace Zappy {
    namespace GUI {
        class SceneManager {
            public:
                SceneManager();
                ~SceneManager();

                void run();

            protected:
            private:
                std::unordered_map<std::string, std::shared_ptr<Zappy::GUI::IScene>> _scenes;
                std::string _currentScene;
                std::string _nextScene;

                std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
        };
    }
}

#endif /* !SCENEMANAGER_HPP_ */
