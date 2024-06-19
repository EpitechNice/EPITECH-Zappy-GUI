/*
** EPITECH PROJECT, 2024
** gui
** File description:
** HelperScene
*/

#ifndef SCENE_HELPERSCENE_HPP_
    #define SCENE_HELPERSCENE_HPP_

    #include <memory>
    #include <chrono>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentTextBox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief HelperScene class
             */
            class HelperScene : public AScene {
                public:
                    /**
                     * @brief HelperScene constructor
                     *
                     * @param render The render
                     * @param text The text
                     */
                    HelperScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text);
                    HelperScene() = default;

                    /**
                     * @brief Destroy the HelperScene object
                     *
                     * @warning After the destruction of the HelperScene object, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the HelperScene object
                     */
                    void update() override;

                    /**
                     * @brief Draw the 2D objects of the HelperScene object
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the HelperScene object
                     */
                    void resize() override;

                    /**
                     * @brief Get the next scene
                     *
                     * @return `std::string` The next scene
                     */
                    std::string nextScene() override;

                protected:
                private:
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::TextBox>, std::string> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_HELPERSCENE_HPP_ */
