/*
** EPITECH PROJECT, 2024
** gui
** File description:
** DisplayCreditScene
*/

#ifndef SCENE_DISPLAYCREDITSCENE_HPP_
    #define SCENE_DISPLAYCREDITSCENE_HPP_

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
             * @brief CreditScene class
             */
            class CreditScene : public AScene {
                public:
                    /**
                     * @brief CreditScene constructor
                     *
                     * @param render The render
                     * @param text The text
                     * @param sceneNbr The scene number
                     */
                    CreditScene(std::shared_ptr<Zappy::GUI::Raylib::Render> render, std::string text, int sceneNbr);

                    /**
                     * @brief Destroy the CreditScene object
                     *
                     * @warning After the destruction of the CreditScene object, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the CreditScene object
                     */
                    void update() override;

                    /**
                     * @brief Draw the 2D objects of the CreditScene object
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the CreditScene object
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
                    int _sceneNbr;
                    std::unique_ptr<Zappy::GUI::Component::Background2D> _background;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::Button>, std::string> _backButton;
                    std::pair<std::unique_ptr<Zappy::GUI::Component::TextBox>, std::string> _text;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_DISPLAYCREDITSCENE_HPP_ */
