/*
** EPITECH PROJECT, 2024
** gui
** File description:
** SoundOption
*/

#ifndef SCENE_SOUNDOPTION_HPP_
    #define SCENE_SOUNDOPTION_HPP_

    #include <memory>

    #include "AScene.hpp"
    #include "ComponentBackground2D.hpp"
    #include "ComponentButton.hpp"
    #include "Render.hpp"
    #include "SoundManager.hpp"
    #include "ComponentVolumeSection.hpp"

namespace Zappy {
    namespace GUI {
        namespace Scene {
            /**
             * @brief SoundOption class
             */
            class SoundOption : public AScene {
                public:
                    /**
                     * @brief SoundOption constructor
                     *
                     * @param render The render
                     */
                    SoundOption(std::shared_ptr<Zappy::GUI::Raylib::Render> render);
                    ~SoundOption() = default;

                    /**
                     * @brief Destroy the SoundOption object
                     *
                     * @warning After the destruction of the SoundOption object, you won't be able to use it anymore
                     */
                    void destroy() override;

                    /**
                     * @brief Update the SoundOption object
                     */
                    void update() override;

                    /**
                     * @brief Draw the 2D objects of the SoundOption object
                     */
                    void draw2D() override;

                    /**
                     * @brief Resize the SoundOption object
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
                    std::unique_ptr<Zappy::GUI::Component::VolumeSection> _music;
                    std::unique_ptr<Zappy::GUI::Component::VolumeSection> _sound;
                    Zappy::GUI::I18n::SupportedLocale _lang;
            };
        }
    }
}

#endif /* !SCENE_SOUNDOPTION_HPP_ */
