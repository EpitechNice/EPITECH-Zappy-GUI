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
    #include "ComponentInspecter.hpp"
    #include "ComponentTileMap.hpp"
    #include "ComponentRessources.hpp"
    #include "Ref.hpp"
    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief Game class
             */
            class Game : public AScene {
                public:
                    /**
                     * @brief Game constructor
                     *
                     * @param render The render
                     */
                    Game(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Game() = default;

                    /**
                     * @brief Start the Game Scene
                     */
                    void start() override;

                    /**
                     * @brief Destroy the Game Scene
                     *
                     * @warning After the destruction of the Game Scene, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the Game Scene
                     */
                    void update() override;

                    /**
                     * @brief Draw the 3D objects of the Game Scene
                     */
                    void draw3D() override;

                    /**
                     * @brief Draw the 2D objects of the Game Scene
                     */
                    void draw2D() override;

                    /**
                     * @brief Check if the Game Scene is ready
                     *
                     * @return `bool` If the Game Scene is ready
                     */
                    bool isReady() override;

                    /**
                     * @brief Get the next scene
                     *
                     * @return `std::string` The next scene
                     */
                    std::string nextScene() override;

                    /**
                     * @brief Resize the Game Scene
                     */
                    void resize() override;

                    /**
                     * @brief Create the map
                     *
                     * @param size The size of the map
                     */
                    void createMap(std::pair<int, int> size);

                protected:
                private:
                    bool _isReady = false;
                    std::unique_ptr<Zappy::GUI::Component::Skybox> _skybox;
                    std::unique_ptr<Zappy::GUI::Component::Skybox> _borderbox;
                    std::unique_ptr<Zappy::GUI::Component::Chatbox> _chatbox;
                    std::shared_ptr<Zappy::GUI::Component::Inspecter> _inspecter;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    std::shared_ptr<Zappy::GUI::Component::Ressources> _ressources;
                    std::unique_ptr<Zappy::GUI::Component::TileMap> _tileMap;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Rectangle>, std::unique_ptr<Zappy::GUI::Component::Rectangle>> _crossPointer;
                    bool _cursor;

                    std::unique_ptr<Zappy::GUI::Component::Text> _north;
                    std::unique_ptr<Zappy::GUI::Component::Text> _east;
                    std::unique_ptr<Zappy::GUI::Component::Text> _south;
                    std::unique_ptr<Zappy::GUI::Component::Text> _west;
            };
        }
    }
}

#endif /* !SCENE_GAME_HPP_ */
