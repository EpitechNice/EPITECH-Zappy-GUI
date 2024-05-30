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
    #include "ComponentCircle.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class SliderVolume {
                public:
                    SliderVolume(std::pair<float, float> pos, float width, float height, std::string name);
                    ~SliderVolume();

                    void destroy();
                    void draw();

                    bool isClicked();
                    void event();
                    void updateValue();

                    void setStatut(bool statut) { _statut = statut; }
                    void setValue(float value) { _value = value; }
                    void setWidth(float width) { _width = width; }
                    void setHeight(float height) { _height = height; }

                    bool getStatut() const { return _statut; };
                    float getValue() const;
                    float getWidth() const { return _width; }
                    float getHeight() const { return _height; }
                    std::string getName() const { return _name; }
                    std::pair<float, float> getPos() const {return _pos; }

                private:
                    std::pair<float, float> _pos;
                    float _width;
                    float _height;
                    float _value;
                    bool _isDragging;
                    bool _isDestroyed;
                    bool _statut;
                    std::string _name;
            };
        }
    }
}

#endif /* !COMPONENT_SLIDERVOLUME_HPP_ */
