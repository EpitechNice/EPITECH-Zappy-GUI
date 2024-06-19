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
    #include "CreditScene.hpp"
    #include "HelperScene.hpp"
    #include "DisplayCreditScene/DisplayCreditScene.hpp"
    #include "SoundOption/SoundOptionScene.hpp"
    #include "ResolutionOption/ResolutionOptionScene.hpp"

namespace Zappy {
    namespace GUI {
        /**
         * @brief SceneManager class
         */
        class SceneManager {
            public:
                /**
                 * @brief Construct a new SceneManager object
                 */
                SceneManager();
                ~SceneManager();

                /**
                 * @brief Destroy the SceneManager object
                 *
                 * @warning After the destruction of the SceneManager, you won't be able to use it anymore
                 */
                void destroy();

                /**
                 * @brief Game loop
                 */
                void run();

            protected:
            private:
                bool _isDestroyed;
                std::unordered_map<std::string, std::shared_ptr<Zappy::GUI::IScene>> _scenes;
                std::string _currentScene;
                std::string _nextScene;

                std::shared_ptr<Zappy::GUI::Raylib::Render> _render;

                /**
                 * @brief Used to call the resize method of each scenes
                 */
                void _resize();
        };
    }
}

#endif /* !SCENE_MANAGER_HPP_ */
