/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Game
*/

#ifndef SCENE_GAME_HPP_
    #define SCENE_GAME_HPP_

    #include <raylib.h>
    #include <rlgl.h>
    #include <memory>
    #include <vector>

    #include "AScene.hpp"
    #include "ComponentSkybox.hpp"
    #include "ComponentChatbox.hpp"
    #include "ComponentTile.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Game : public AScene {
                public:
                    Game(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Game() = default;

                    void start() override;
                    void destroy() override;
                    void update() override;
                    void event() override;
                    void draw3D() override;
                    void draw2D() override;

                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Skybox> _skybox;
                    std::unique_ptr<Zappy::GUI::Component::Skybox> _borderbox;
                    std::unique_ptr<Zappy::GUI::Component::Chatbox> _chatbox;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    std::vector<std::unique_ptr<Zappy::GUI::Component::Tile>> _tiles;
                    bool _cursor;
            };
        }
    }
}

#endif /* !SCENE_GAME_HPP_ */
