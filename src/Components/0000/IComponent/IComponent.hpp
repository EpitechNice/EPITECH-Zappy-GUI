/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** IComponent
*/

#ifndef INTERFACE_COMPONENT_HPP_
    #define INTERFACE_COMPONENT_HPP_

    #include <raylib.h>
    #include <iostream>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class IComponent {
                public:
                    virtual ~IComponent() = default;

                    virtual void destroy() = 0;
                    virtual void update() = 0;
                    virtual void draw() = 0;


                    virtual float getPosX() const = 0;
                    virtual float getPosY() const = 0;
                    virtual float getPosZ() const = 0;

                    virtual void setPosX(float x) = 0;
                    virtual void setPosY(float y) = 0;
                    virtual void setPosZ(float z) = 0;
                    virtual void modPosX(float x) = 0;
                    virtual void modPosY(float y) = 0;
                    virtual void modPosZ(float z) = 0;


                    virtual float getSizeX() const = 0;
                    virtual float getSizeY() const = 0;
                    virtual float getSizeZ() const = 0;

                    virtual void setSizeX(float x) = 0;
                    virtual void setSizeY(float y) = 0;
                    virtual void setSizeZ(float z) = 0;
                    virtual void modSizeX(float x) = 0;
                    virtual void modSizeY(float y) = 0;
                    virtual void modSizeZ(float z) = 0;

                    virtual Color getColor() const = 0;
                    virtual void setColor(Color color) = 0;

                protected:
                private:
            };
        }
    }
}


#endif /* !INTERFACE_COMPONENT_HPP_ */
