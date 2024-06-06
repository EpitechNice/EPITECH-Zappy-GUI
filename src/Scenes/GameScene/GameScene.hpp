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
    #include "ComponentTileMap.hpp"
    #include "ComponentRessources.hpp"
    #include "Ressources.hpp"

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
                    std::shared_ptr<Zappy::GUI::Component::Ressources> _ressources;
                    std::unique_ptr<Zappy::GUI::Component::TileMap> _tileMap;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>> _crossPointer;
                    bool _cursor;
            };
        }
    }
}

#endif /* !SCENE_GAME_HPP_ */
