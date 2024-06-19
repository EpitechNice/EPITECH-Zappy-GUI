/*
** EPITECH PROJECT, 2024
** gui
** File description:
** AScene
*/

#ifndef ASCENE_HPP_
    #define ASCENE_HPP_

    #include "IScene.hpp"
    #include "Render.hpp"

namespace Zappy {
    namespace GUI {
        /**
         * @brief AScene class
         */
        class AScene : public IScene {
            public:
                AScene() = default;
                ~AScene() = default;

                /**
                 * @brief Start the scene
                 */
                void start() override;

                /**
                 * @brief Destroy the scene
                 *
                 * @warning After the destruction of the scene, you won't be able to use it anymore
                 */
                void destroy() override;

                /**
                 * @brief Update the scene
                 */
                void update() override;

                /**
                 * @brief Update the scene
                 *
                 * @param isGameReady If the game is ready
                 */
                void update(bool isGameReady) override;

                /**
                 * @brief Draw the 3D objects of the scene
                 */
                void draw3D() override;

                /**
                 * @brief Draw the 2D objects of the scene
                 */
                void draw2D() override;

                /**
                 * @brief Get the next scene
                 *
                 * @return `std::string` The next scene
                 */
                std::string nextScene() override;

                /**
                 * @brief Check if the scene is ready
                 *
                 * @return `bool` If the scene is ready
                 */
                bool isReady() override;

                /**
                 * @brief Resize the scene
                 */
                void resize() override;

            protected:
            private:
        };
    }
}

#endif /* !ASCENE_HPP_ */
