/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButton
*/

#ifndef COMPONENT_BUTTON_HPP_
    #define COMPONENT_BUTTON_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentCircle.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "../Sfml/SoundManager/SoundManager.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Button {
                public:
                    typedef enum {
                        DEFAULT,
                        HOVER,
                        CLICKED
                    } State;

                    Button(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);
                    ~Button();

                    void destroy();
                    void draw();
                    bool isClicked(std::string textButton);
                    bool isClickedWihoutSong();

                    void setSize(const std::pair<float, float>& size);
                    void setPos(const std::pair<float, float>& Pos);

                    std::pair<float, float> getSize() const;
                    std::pair<float, float> getPos() const;
                    std::string getText() const;

                    void changeColor(Color color);
                    void changePos(const std::pair<float, float>& newPos);
                    void changeSize(const std::pair<float, float>& newSize);

                    void _updateState();
                    void _modState(State oldState);

                protected:
                private:
                    std::pair<float, float> _pos;
                    std::pair<float, float> _size;
                    std::pair<float, float> _textPos;
                    Color _color;
                    State _state;
                    int _pressEffect = 6;
                    int _hoverEffect = 2;
                    bool _isDestroyed;

                    std::unique_ptr<RoundedRectangle> _blackStroke;
                    std::unique_ptr<RoundedRectangle> _upEffect;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<RoundedRectangle> _topButton;
                    std::unique_ptr<RoundedRectangle> _reflexioneffect;
                    std::unique_ptr<Circle> _circle;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Text> _textStroke;

            };
        }
    }
}

#endif /* !COMPONENT_BUTTON_HPP_ */
