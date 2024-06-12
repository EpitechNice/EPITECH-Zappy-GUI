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
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Skybox : public AComponent {
                public:
                    Skybox(std::string name, float size = 1000);
                    Skybox(Color color, float size = 1000);

                    void destroy() override;
                    void draw() override;

                    void update(std::shared_ptr<Zappy::GUI::Raylib::Render> render);

                protected:
                private:
                    typedef struct {
                        Texture2D texture;
                        Mesh mesh;
                        Model model;
                        Vector3 position;
                        Vector3 rotation;
                    } Plane;

                    std::vector<Plane> _planes;
                    void _createSkybox(std::vector<Texture2D> textures, float size);
            };
        }
    }
}

#endif /* !COMPONENTSKYBOX_HPP_ */
