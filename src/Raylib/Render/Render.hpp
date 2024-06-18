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

namespace Zappy {
    namespace GUI {
        namespace Raylib {
            class Render {
                public:
                    Render(int height = 600, int width = 800, int fps = 60);
                    ~Render();

                    void destroy();

                    std::shared_ptr<View> view() const;
                    int getHeight() const;
                    int getWidth() const;
                    int getFps() const;
                    float getVolumeMusique() const;
                    float getEffetSonore() const;


                    void setHeight(int height);
                    void setWidth(int width);
                    void setDimensions(int height, int width);
                    void setFps(int fps);
                    void setVolumeMusique(float volumeMusique);
                    void setEffetSonore(float effetSonore);

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
