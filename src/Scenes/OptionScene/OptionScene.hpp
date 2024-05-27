/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Option
*/

#ifndef SCENE_OPTION_HPP_
    #define SCENE_OPTION_HPP_

#include "AScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Option : public AScene {
                public:
                    Option() = default;
                    ~Option() = default;

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

#endif /* !SCENE_OPTION_HPP_ */
