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
    #include "../Sfml/SoundManager/SoundManager.hpp"
namespace Zappy {
    namespace GUI {
        typedef enum {
            FRANCAIS,
            ANGLAIS,
            ESPAGNOL,
            MANDARIN,
        } Langue;
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
                    Langue getLangue() const;


                    void setHeight(int height);
                    void setWidth(int width);
                    void setDimensions(int height, int width);
                    void setFps(int fps);
                    void setVolumeMusique(float volumeMusique);
                    void setEffetSonore(float effetSonore);
                    void setLangue(Langue langue);

                protected:
                private:
                    int _height;
                    int _width;
                    int _fps;

                    std::string _pathMusiquePrincipal;
                    sf::Music _musiquePrincipal;

                    Langue _langue;
                    bool _isDestroyed;
                    Image _icon;
                    std::shared_ptr<View> _view;
            };
        }
    }
}

#endif /* !RENDER_HPP_ */
