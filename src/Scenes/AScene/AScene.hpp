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
        class AScene : public IScene {
            public:
                AScene() = default;
                ~AScene() = default;

                void start() override;
                void destroy() override;
                void update() override;
                void update(bool isGameReady) override;
                void draw3D() override;
                void draw2D() override;
                std::string nextScene() override;
                bool isReady() override;

            protected:
            private:
        };
    }
}

#endif /* !ASCENE_HPP_ */
