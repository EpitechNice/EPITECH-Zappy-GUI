/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** IComponent
*/

#ifndef INTERFACE_COMPONENT_HPP_
    #define INTERFACE_COMPONENT_HPP_

    #include <iostream>

namespace Zappy {
    namespace GUI {
        namespace Component {
            class IComponent {
                public:
                    virtual ~IComponent() = default;

                    virtual std::pair<int, int> getPos() const = 0;
                    virtual std::pair<int, int> getSize() const = 0;

                    virtual void destroy() = 0;
                    virtual void update() = 0;
                    virtual void draw() = 0;

                    virtual void setPos(std::pair<int, int> pos) = 0;
                    virtual void setPosX(int x) = 0;
                    virtual void setPosY(int y) = 0;
                    virtual void modPosX(int x) = 0;
                    virtual void modPosY(int y) = 0;
                protected:
                private:
            };
        }
    }
}


#endif /* !INTERFACE_COMPONENT_HPP_ */
