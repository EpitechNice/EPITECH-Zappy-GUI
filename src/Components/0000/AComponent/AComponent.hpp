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
                    AComponent(std::pair<int, int> pos, std::pair<int, int> size);
                    ~AComponent();

                    std::pair<int, int> getPos() const;
                    std::pair<int, int> getSize() const;

                    void setPos(std::pair<int, int> pos);
                    void setPosX(int x);
                    void setPosY(int y);
                    void modPosX(int x);
                    void modPosY(int y);

                    void destroy();
                    void update();
                    void draw();

                protected:
                    bool _isDestroyed = false;
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;

                private:
            };
        }
    }
}

#endif /* !ABSTRACT_COMPONENT_HPP_ */
