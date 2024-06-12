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
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterInfo: public AComponent {
                public:
                    InspecterInfo(std::pair<int, int> pos, std::pair<int, int> size);

                    void draw() override;
                    void modPosX(float x) override;

                    void setInfo(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                protected:
                private:
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
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_INFO_HPP_ */
