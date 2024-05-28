/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSkybox
*/

#ifndef COMPONENTSKYBOX_HPP_
    #define COMPONENTSKYBOX_HPP_

    #include <raylib.h>
    #include <rlgl.h>
    #include <raymath.h>
    #include <vector>
    #include <string>
    #include <memory>

    #include "Render.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Skybox {
                public:
                    Skybox(std::string name, float size = 1000);
                    Skybox(Color color, float size = 1000);
                    ~Skybox() = default;

                    void destroy();

                    void update(std::shared_ptr<Zappy::GUI::Raylib::Render> render);

                    void draw();

                protected:
                private:
                    typedef struct {
                        Texture2D texture;
                        Mesh mesh;
                        Model model;
                        Vector3 position;
                        Vector3 rotation;
                        float size;
                    } Plane;

                    float _size;
                    bool _isDestroyed;
                    std::vector<Plane> _planes;
            };
        }
    }
}

#endif /* !COMPONENTSKYBOX_HPP_ */
