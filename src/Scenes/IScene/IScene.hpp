/*
** EPITECH PROJECT, 2024
** gui
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
    #define ISCENE_HPP_

    #include <string>

namespace Zappy {
    namespace GUI {
        /**
         * @brief IScene class
         */
        class IScene {
            public:
                virtual ~IScene() = default;

                /**
                 * @brief Start the scene
                 */
                virtual void start() = 0;

                /**
                 * @brief Destroy the scene
                 *
                 * @warning After the destruction of the scene, you won't be able to use it anymore
                 */
                virtual void destroy() = 0;

                /**
                 * @brief Update the scene
                 */
                virtual void update() = 0;

                /**
                 * @brief Update the scene
                 *
                 * @param isGameReady If the game is ready
                 */
                virtual void update(bool isGameReady) = 0;

                /**
                 * @brief Draw the 3D objects of the scene
                 */
                virtual void draw3D() = 0;

                /**
                 * @brief Draw the 2D objects of the scene
                 */
                virtual void draw2D() = 0;

                /**
                 * @brief Get the next scene
                 *
                 * @return `std::string` The next scene
                 */
                virtual std::string nextScene() = 0;

                /**
                 * @brief Check if the scene is ready
                 *
                 * @return `bool` If the scene is ready
                 */
                virtual bool isReady() = 0;

                /**
                 * @brief Resize the scene
                 */
                virtual void resize() = 0;
        };
    }
}

#endif /* !ISCENE_HPP_ */
