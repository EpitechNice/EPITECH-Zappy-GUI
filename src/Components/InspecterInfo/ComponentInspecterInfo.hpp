/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterInfo
*/

#ifndef COMPONENT_INSPECTER_INFO_HPP_
    #define COMPONENT_INSPECTER_INFO_HPP_

    #include <memory>
    #include <vector>
    #include <iostream>

    #include "Players.hpp"
    #include "Ressources.hpp"
    #include "ComponentTextBox.hpp"
    #include "ComponentCircle.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterInfo {
                public:
                    InspecterInfo(std::pair<int, int> pos, std::pair<int, int> size);
                    ~InspecterInfo();

                    void destroy();

                    void draw();

                    void modPosX(int x);

                    void setInfo(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _noPlayerSelected;
                    std::shared_ptr<Zappy::GUI::Ressources::Players> _player;
                    std::unique_ptr<Zappy::GUI::Component::Circle> _circle;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _name;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _food;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _linemate;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _deraumere;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _sibur;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _mendiane;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _phiras;
                    std::unique_ptr<Zappy::GUI::Component::TextBox> _thystame;
                    bool _isDestroyed;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_INFO_HPP_ */
