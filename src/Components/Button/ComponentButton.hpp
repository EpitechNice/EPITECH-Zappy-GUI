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
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Button: public AComponent {
                public:
                    typedef enum {
                        NONE = -1,
                        DEFAULT,
                        HOVER,
                        CLICKED
                    } State;

                    Button(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);

                    void draw() override;
                    void setPosX(float x) override;
                    void modPosX(float x) override;
                    void setPosY(float Y) override;
                    void modPosY(float y) override;
                    void setSizeX(float x) override;
                    void setSizeY(float y) override;
                    void setColor(Color color) override;

                    void enableBubble();
                    void disableBubble();
                    bool isHover() const;
                    bool isClickedWihoutSong() const;
                    bool isClicked() const;
                    bool isClicked(std::string textButton);
                    void setText(std::string text);
                    std::string getText() const;
                    void setState(State state);

                protected:
                private:
                    float _initialSizeX;
                    float _initialSizeY;

                    std::pair<float, float> _textPos;
                    State _state;
                    int _pressEffect = 6;
                    int _hoverEffect = 2;
                    bool _bubble;
                    time_t _lastClick;

                    std::unique_ptr<RoundedRectangle> _blackStroke;
                    std::unique_ptr<RoundedRectangle> _upEffect;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<RoundedRectangle> _topButton;
                    std::unique_ptr<RoundedRectangle> _reflexioneffect;
                    std::unique_ptr<Circle> _circle;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Text> _textStroke;

                    void _updateState();
                    void _modState(State oldState);
                    void _changeSize(float sizeX, float sizeY);
            };
        }
    }
}

#endif /* !COMPONENT_BUTTON_HPP_ */
