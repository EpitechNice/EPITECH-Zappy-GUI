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
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class ButtonClassic: public AComponent {
                public:
                    typedef enum {
                        NONE = -1,
                        DEFAULT,
                        HOVER,
                        CLICKED
                    } State;

                    ButtonClassic(std::pair<float, float> pos, std::pair<float, float> size, std::string text, int textSize, Color color);

                    void draw() override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;
                    void modPosX(float x) override;
                    void modPosY(float y) override;
                    void setColor(Color color) override;

                    bool isClicked() const;
                    void enableTextStroke();
                    void disableTextStroke();
                    void enableState();
                    void disableState();

                protected:
                private:
                    State _state;
                    bool _textStrokeVisible;
                    bool _stateEnabled;
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
