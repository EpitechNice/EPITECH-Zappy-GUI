/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Game
*/

#ifndef SCENE_GAME_HPP_
    #define SCENE_GAME_HPP_

    #include "AScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Game : public AScene {
                public:
                    Game() = default;
                    ~Game() = default;

                    void start() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
            };
        }
    }
}

#endif /* !SCENE_GAME_HPP_ */
