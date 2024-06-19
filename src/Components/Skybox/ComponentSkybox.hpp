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
    #include "TextureManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            /**
             * @brief Skybox component
             */
            class Skybox : public AComponent {
                public:
                    /**
                     * @brief Construct a new Skybox object
                     *
                     * @param visible Visibility of the skybox. Default is true
                     * @param size Size of the skybox. Default is 1000
                     *
                     * @warning The skybox will be loaded using the TextureManager. So it must be in the 'assets/skybox/' folder.
                     * @warning This function should be called in the raylib context
                     */
                    Skybox(bool visible = true, float size = 1000);

                    /**
                     * @brief Destroy the Skybox object
                     *
                     * @warning This function should be called in the raylib context
                     * @warning After calling this function, the object should not be used anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Draw the skybox
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void draw() override;

                    /**
                     * @brief Resize the skybox
                     *
                     * @warning This function should be called in the raylib context
                     */
                    void resize() override;

                    /**
                     * @brief Update the skybox
                     *
                     * @param render Render object
                     */
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

                    bool _visible;
                    float _size;
                    std::vector<Plane> _planes;
                    void _createSkybox(std::vector<Texture2D> textures, float size);
            };
        }
    }
}

#endif /* !COMPONENTSKYBOX_HPP_ */
