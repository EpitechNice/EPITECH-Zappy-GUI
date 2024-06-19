/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Menu
*/

#ifndef SCENE_MENU_HPP_
    #define SCENE_MENU_HPP_

    #include <memory>
    #include <vector>
    #include <string>
    #include <tuple>

    #include "AScene.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentImage.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief Menu class
             */
            class Menu : public AScene {
                public:
                    /**
                     * @brief Menu constructor
                     *
                     * @param render The render
                     */
                    Menu(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Menu() = default;

                    /**
                     * @brief Start the Menu Scene
                     */
                    void start() override;

                    /**
                     * @brief Destroy the Menu Scene
                     *
                     * @warning After the destruction of the Menu Scene, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the Menu Scene
                     */
                    void draw3D() override;

                    /**
                     * @brief Draw the 2D objects of the Menu Scene
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the Menu Scene
                     */
                    void resize() override;

                    /**
                     * @brief Get the next scene
                     *
                     * @return `std::string` The next scene
                     */
                    std::string nextScene() override;

                    /**
                     * @brief Update the Menu Scene
                     */
                    void update(bool isGameReady);

                protected:
                private:
                    bool _isGameReady;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string>> _buttons;
                    std::unique_ptr<Zappy::GUI::Component::Image> _logo;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_MENU_HPP_ */
