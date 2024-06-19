/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Credit
*/

#ifndef SCENE_CREDITSCENE_HPP_
    #define SCENE_CREDITSCENE_HPP_

    #include <memory>
    #include <chrono>
    #include <vector>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief Credit class
             */
            class Credit : public AScene {
                public:
                    /**
                     * @brief Credit constructor
                     *
                     * @param render The render
                     */
                    Credit(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Credit() = default;

                    /**
                     * @brief Destroy the Credit object
                     *
                     * @warning After the destruction of the Credit object, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the Credit object
                     */
                    void update() override;

                    /**
                     * @brief Draw the 2D objects of the Credit object
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the Credit object
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
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string>> _generalButtons;
                    std::vector<std::pair<float, float>> _buttonsPositions;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_CREDITSCENE_HPP_ */
