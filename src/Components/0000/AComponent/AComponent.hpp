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
            class AComponent: public IComponent {
                public:
                    AComponent() = default;
                    ~AComponent();

                    void destroy() override;
                    void draw() override;
                    void resize() override;

                    void setRef() override;

                    float getPosX() const override;
                    float getPosY() const override;
                    float getPosZ() const override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;
                    void setPosZ(float z) override;
                    void modPosX(float x) override;
                    void modPosY(float y) override;
                    void modPosZ(float z) override;

                    float getSizeX() const override;
                    float getSizeY() const override;
                    float getSizeZ() const override;
                    void setSizeX(float x) override;
                    void setSizeY(float y) override;
                    void setSizeZ(float z) override;
                    void modSizeX(float x) override;
                    void modSizeY(float y) override;
                    void modSizeZ(float z) override;

                    Color getColor() const override;
                    void setColor(Color color) override;

                protected:
                    bool _isDestroyed = false;
                    float _posX = 0;
                    float _posY = 0;
                    float _posZ = 0;
                    float _sizeX = 0;
                    float _sizeY = 0;
                    float _sizeZ = 0;
                    Color _color = WHITE;

                    float _refSizeX = -1;
                    float _refSizeY = -1;
                    float _refPosX = -1;
                    float _refPosY = -1;
                    float _refHeight = -1;
                    float _refWidth = -1;

                private:
            };
        }
    }
}

#endif /* !ABSTRACT_COMPONENT_HPP_ */
