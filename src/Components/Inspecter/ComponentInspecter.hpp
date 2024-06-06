/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentInspecter
*/

#ifndef COMPONENT_INSPECTER_HPP_
    #define COMPONENT_INSPECTER_HPP_

    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <memory>
    #include <tuple>

    #include "ComponentRectangle.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentButtonClassic.hpp"
    #include "ComponentCircle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Inspecter {
                public:
                    Inspecter();
                    ~Inspecter();

                    void destroy();

                    void update();

                    void draw();

                    bool mouseIsOn() const;

                protected:
                private:
                    bool _isDestroyed;
                    bool _open;
                    int _width;
                    int _screenWidth;
                    std::pair<float, float> _buttonSize;

                    std::unique_ptr<Rectangle> _rectTopBackground;
                    std::unique_ptr<Rectangle> _rectTop;
                    std::unique_ptr<Rectangle> _rectMid;
                    std::unique_ptr<Rectangle> _rectBot;
                    std::unique_ptr<Button> _openButton;

                    void _setInspecterOpen();
                    void _setInspecterClose();
            };
        }
    }
}

#endif /* !COMPONENTINSPECTER_HPP_ */
