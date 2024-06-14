/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** ComponentInspecterSelecterGroup
*/

#ifndef COMPONENT_INSPECTER_SELECTER_GROUP_HPP_
    #define COMPONENT_INSPECTER_SELECTER_GROUP_HPP_

    #include <vector>

    #include "ComponentInspecterSelecter.hpp"
    #include "ComponentInspecterInfo.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecterGroup: public AComponent {
                public:
                    InspecterSelecterGroup(std::pair<int, int> pos, int width);

                    void draw() override;
                    void modPosX(float x) override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;

                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);
                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);
                    void addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player);
                    void addEgg(std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                protected:
                private:
                    std::vector<std::shared_ptr<InspecterSelecter>> _selecters;
                    int _selected = -1;
            };
        }
    }

}


#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_HPP_ */
