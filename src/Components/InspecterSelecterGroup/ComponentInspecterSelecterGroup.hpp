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

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecterGroup {
                public:
                    InspecterSelecterGroup(std::pair<int, int> pos, int width);
                    ~InspecterSelecterGroup();

                    void destroy();

                    void update(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    void draw();

                    void reset(std::shared_ptr<Zappy::GUI::Component::InspecterInfo> info);

                    void addPlayer(std::shared_ptr<Zappy::GUI::Ressources::Players> player);

                    void modPosX(int x);
                    void setPosX(int x);
                    void setPosY(int y);

                    std::pair<int, int> getSize() const;
                    std::pair<int, int> getPos() const;

                protected:
                private:
                    std::pair<int, int> _pos;
                    std::pair<int, int> _size;
                    std::vector<std::shared_ptr<InspecterSelecter>> _players;
                    bool _isDestroyed = false;
                    int _selected = -1;
                    bool _justSelect = false;
            };
        }
    }

}


#endif /* !COMPONENT_INSPECTER_SELECTER_GROUP_HPP_ */
