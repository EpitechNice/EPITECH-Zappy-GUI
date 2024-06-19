/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Option
*/

#ifndef SCENE_OPTION_HPP_
    #define SCENE_OPTION_HPP_

    #include <memory>
    #include <chrono>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "I18nHelper.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief Option class
             */
            class Option : public AScene {
                public:
                    /**
                     * @brief Option constructor
                     *
                     * @param render The render
                     */
                    Option(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~Option() = default;

                    /**
                     * @brief Start the Option Scene
                     */
                    void start() override;

                    /**
                     * @brief Destroy the Option Scene
                     *
                     * @warning After the destruction of the Option Scene, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the Option Scene
                     */
                    void update() override;

                    /**
                     * @brief Draw the 2D objects of the Option Scene
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the Option Scene
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
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, std::string, std::string, std::pair<float, float>>> _generalButtons;
                    std::tuple<std::unique_ptr<Zappy::GUI::Component::Text>, std::string, std::pair<float, float>> _text;
                    std::vector<std::tuple<std::unique_ptr<Zappy::GUI::Component::Button>, Zappy::GUI::I18n::SupportedLocale, std::string, std::pair<float, float>>> _languageButtons;
                    std::shared_ptr<Zappy::GUI::Raylib::Render> _render;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_OPTION_HPP_ */
