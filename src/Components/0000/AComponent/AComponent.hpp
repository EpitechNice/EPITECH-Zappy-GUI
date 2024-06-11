/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** AComponent
*/

#ifndef ABSTRACT_COMPONENT_HPP_
    #define ABSTRACT_COMPONENT_HPP_

    #include <iostream>
    #include <IComponent.hpp>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class AComponent : IComponent {
                public:
                    AComponent() = default;
                    AComponent(std::pair<float, float> pos, std::pair<float, float> size);
                    ~AComponent();

                    void destroy();
                    void update();
                    void draw();

                    std::pair<float, float> getPos() const;
                    float getPosX() const;
                    float getPosY() const;

                    void setPos(std::pair<float, float> pos);
                    void setPosX(float x);
                    void setPosY(float y);
                    void modPosX(float x);
                    void modPosY(float y);


                    std::pair<float, float> getSize() const;
                    float getSizeX() const;
                    float getSizeY() const;

                    void setSize(std::pair<float, float> size);
                    void setSizeX(float x);
                    void setSizeY(float y);
                    void modSizeX(float x);
                    void modSizeY(float y);

                protected:
                    bool _isDestroyed = false;
                    float _posX = 0;
                    float _posY = 0;
                    float _sizeX = 0;
                    float _sizeY = 0;

                private:
            };
        }
    }
}

#endif /* !ABSTRACT_COMPONENT_HPP_ */
