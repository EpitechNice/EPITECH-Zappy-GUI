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
                    void update() override;
                    void draw() override;

                    std::pair<float, float> getPos() const override;
                    float getPosX() const override;
                    float getPosY() const override;

                    void setPos(float x, float y) override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;
                    void modPosX(float x) override;
                    void modPosY(float y) override;


                    std::pair<float, float> getSize() const override;
                    float getSizeX() const override;
                    float getSizeY() const override;

                    void setSize(float x, float y) override;
                    void setSizeX(float x) override;
                    void setSizeY(float y) override;
                    void modSizeX(float x) override;
                    void modSizeY(float y) override;

                    Color getColor() const override;
                    void setColor(Color color) override;

                protected:
                    bool _isDestroyed = false;
                    float _posX = 0;
                    float _posY = 0;
                    float _sizeX = 0;
                    float _sizeY = 0;
                    Color _color = WHITE;

                private:
            };
        }
    }
}

#endif /* !ABSTRACT_COMPONENT_HPP_ */
