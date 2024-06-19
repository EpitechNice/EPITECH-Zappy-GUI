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
        class IScene {
            public:
                virtual ~IScene() = default;

                virtual void start() = 0;
                virtual void destroy() = 0;
                virtual void update() = 0;
                virtual void update(bool isGameReady) = 0;
                virtual void draw3D() = 0;
                virtual void draw2D() = 0;
                virtual std::string nextScene() = 0;
                virtual bool isReady() = 0;
                virtual void resize() = 0;
        };
    }
}

#endif /* !ISCENE_HPP_ */
