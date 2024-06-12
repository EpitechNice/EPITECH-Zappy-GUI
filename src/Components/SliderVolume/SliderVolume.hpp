/*
** EPITECH PROJECT, 2024
** gui
** File description:
** ComponentSliderVolume
*/

#ifndef COMPONENT_SLIDERVOLUME_HPP_
    #define COMPONENT_SLIDERVOLUME_HPP_

    #include <raylib.h>
    #include <raymath.h>
    #include <string>
    #include <vector>
    #include <memory>

    #include "ColorManager.hpp"
    #include "ComponentText.hpp"
    #include "ComponentRectangle.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class SliderVolume: public AComponent {
                public:
                    SliderVolume(std::pair<float, float> pos, float width, float height, std::string name);

                    void draw() override;

                    void update();
                    void setActive(bool active);
                    void setValue(float value);
                    bool getActive() const;
                    float getValue() const;
                    std::string getName() const;

                private:
                    bool _isDrag;
                    bool _active;
                    std::string _name;
                    std::unique_ptr<Component::Rectangle> _background;
                    std::unique_ptr<Component::Rectangle> _value;
            };
        }
    }
}

#endif /* !COMPONENT_SLIDERVOLUME_HPP_ */
