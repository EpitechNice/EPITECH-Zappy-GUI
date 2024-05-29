/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentButton
*/

#ifndef COMPONENT_BUTTON_CLASSIC_HPP_
    #define COMPONENT_BUTTON_CLASSIC_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentCircle.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class ButtonClassic {
                public:
                    typedef enum {
                        NONE = -1,
                        DEFAULT,
                        HOVER,
                        CLICKED
                    } State;

                    ButtonClassic(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);
                    ~ButtonClassic();

                    void destroy();

                    void draw();

                    std::pair<float, float> getSize() const;
                    bool isClicked() const;

                    void modPosX(float x);
                    void setPosX(float x);
                    void setPos(std::pair<float, float> pos);

                    void enableTextStroke();
                    void disableTextStroke();

                    void enableState();
                    void disableState();

                    void setColor(Color color);

                protected:
                private:
                    std::pair<float, float> _pos;
                    std::pair<float, float> _size;
                    std::pair<float, float> _textPos;
                    Color _color;
                    State _state;
                    bool _textStrokeVisible;
                    bool _stateEnabled;
                    bool _isDestroyed;
                    time_t _lastClick;

                    std::unique_ptr<RoundedRectangle> _button;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Text> _textStroke;

                    void _updateState();
                    void _modState(State oldState);
            };
        }
    }
}

#endif /* !COMPONENT_BUTTON_CLASSIC_HPP_ */
