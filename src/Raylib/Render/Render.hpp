/*
** EPITECH PROJECT, 2024
** gui
** File description:
** Render
*/

#ifndef RENDER_HPP_
    #define RENDER_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <memory>

    #include "View.hpp"
    #include <iostream>
    #include "SoundManager.hpp"
    #include "I18nHelper.hpp"
    #include "FontManager.hpp"
    #include "ModelManager.hpp"
    #include "TextureManager.hpp"
    #include "Path.hpp"

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            /**
             * @brief A class to manage the rendering
             */
            class Render {
                public:
                    /**
                     * @brief Construct a new Render object
                     *
                     * @param height The height of the window
                     * @param width The width of the window
                     * @param fps The fps of the window
                     */
                    Render(int height = 600, int width = 800, int fps = 60);
                    ~Render();

                    /**
                     * @brief Destroy the window
                     *
                     * @warning After the destruction of the window, you won't be able to use it anymore
                     */
                    void destroy();

                    /**
                     * @brief Get the view
                     *
                     * @return `std::shared_ptr<View>` The view
                     */
                    std::shared_ptr<View> view() const;

                    /**
                     * @brief Get the height of the window
                     *
                     * @return `int` The height of the window
                     */
                    int getHeight() const;

                    /**
                     * @brief Get the width of the window
                     *
                     * @return `int` The width of the window
                     */
                    int getWidth() const;

                    /**
                     * @brief Get the dimensions of the window
                     *
                     * @return `std::pair<int, int>` The dimensions of the window
                     */
                    int getFps() const;

                    /**
                     * @brief Get the volume of the music
                     *
                     * @return `float` The volume of the music
                     */
                    float getVolumeMusique() const;

                    /**
                     * @brief Get the volume of the sound effect
                     *
                     * @return `float` The volume of the sound effect
                     */
                    float getEffetSonore() const;

                    /**
                     * @brief Set the height of the window
                     *
                     * @param height The new height
                     */
                    void setHeight(int height);

                    /**
                     * @brief Set the width of the window
                     *
                     * @param width The new width
                     */
                    void setWidth(int width);

                    /**
                     * @brief Set the dimensions of the window
                     *
                     * @param height The new height
                     * @param width The new width
                     */
                    void setDimensions(int height, int width);

                    /**
                     * @brief Set the fps of the window
                     *
                     * @param fps The new fps
                     */
                    void setFps(int fps);

                    /**
                     * @brief Display the loading screen
                     */
                    void displayLoadingScreen();

                protected:
                private:
                    int _height;
                    int _width;
                    int _fps;

                    std::string _pathMusiquePrincipal;
                    sf::Music _musiquePrincipal;

                    bool _isDestroyed;
                    Image _icon;
                    std::shared_ptr<View> _view;
            };
        }
    }
}

#endif /* !RENDER_HPP_ */
