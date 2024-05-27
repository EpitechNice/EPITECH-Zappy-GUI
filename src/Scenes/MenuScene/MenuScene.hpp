/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Menu
*/

#ifndef SCENE_MENU_HPP_
    #define SCENE_MENU_HPP_

    #include "AScene.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            class Menu : public AScene {
                public:
                    Menu() = default;
                    ~Menu() = default;

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

#endif /* !SCENE_MENU_HPP_ */
