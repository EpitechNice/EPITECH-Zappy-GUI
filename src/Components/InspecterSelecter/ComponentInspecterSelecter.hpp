/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** InspecterSelecter
*/

#ifndef COMPONENT_INSPECTER_SELECTER_HPP_
    #define COMPONENT_INSPECTER_SELECTER_HPP_

    #include <iostream>
    #include <memory>
    #include <raylib.h>

    #include "Players.hpp"
    #include "ComponentRoundedRectangle.hpp"
    #include "ComponentText.hpp"
    #include "ComponentCircle.hpp"
    #include "AComponent.hpp"
    #include "Ref.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class InspecterSelecter: public AComponent {
                public:
                    InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Players> player);
                    InspecterSelecter(std::pair<int, int> pos, int width, std::shared_ptr<Zappy::GUI::Ressources::Eggs> egg);

                    void draw() override;
                    void modPosX(float x) override;
                    void modPosY(float y) override;
                    void setPosX(float x) override;
                    void setPosY(float y) override;

                    void update();
                    void setSelected(bool selected);
                    bool isClicked() const;
                    bool isPlayer() const;
                    std::shared_ptr<Zappy::GUI::Ressources::Players> getPlayer() const;
                    std::shared_ptr<Zappy::GUI::Ressources::Eggs> getEgg() const;

                protected:
                private:
                    typedef enum {
                        NONE,
                        HOVER,
                        CLICKED,
                        SELECTED,
                    } State;

                    std::shared_ptr<Zappy::GUI::Ressources::Players> _player;
                    std::shared_ptr<Zappy::GUI::Ressources::Eggs> _egg;
                    std::unique_ptr<RoundedRectangle> _background;
                    std::unique_ptr<Text> _text;
                    std::unique_ptr<Circle> _team;
                    State _state = NONE;
            };
        }
    }
}

#endif /* !COMPONENT_INSPECTER_SELECTER_HPP_ */
