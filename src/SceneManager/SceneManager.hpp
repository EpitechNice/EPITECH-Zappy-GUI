/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SceneManager
*/

#ifndef SCENE_MANAGER_HPP_
    #define SCENE_MANAGER_HPP_

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

                void destroy();

                void run();

            protected:
            private:
                bool _isDestroyed;
                std::unordered_map<std::string, std::shared_ptr<Zappy::GUI::IScene>> _scenes;
                std::string _currentScene;
                std::string _nextScene;

                std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
        };
    }
}

#endif /* !SCENE_MANAGER_HPP_ */
