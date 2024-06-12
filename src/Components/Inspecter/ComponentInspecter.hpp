/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentInspecter
*/

#ifndef COMPONENT_INSPECTER_HPP_
    #define COMPONENT_INSPECTER_HPP_

    #include <raylib.h>
    #include <string>
    #include <vector>
    #include <memory>
    #include <tuple>

    #include "ComponentRectangle.hpp"
    #include "ComponentButton.hpp"
    #include "ComponentButtonClassic.hpp"
    #include "ComponentCircle.hpp"
    #include "ComponentInspecterSelecterGroupDraggable.hpp"
    #include "Ressources.hpp"
    #include "ComponentInspecterInfo.hpp"
    #include "ComponentInspecterInfoTile.hpp"
    #include "AComponent.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            class Inspecter: public AComponent {
                public:
                    Inspecter();

                    void destroy() override;
                    void draw() override;

                    void update(std::pair<int, int> selectedTile);
                    bool mouseIsOn() const;
                    void open();
                    void close();

                protected:
                private:
                    typedef enum {
                        NAME = 0,
                        BUTTON = 1,
                    } TabsIndex;
                    bool _open;
                    int _screenWidth;
                    int _tabsIndex;
                    std::pair<int, int> _selectedTile;

                    std::unique_ptr<Rectangle> _rectTopBackground;
                    std::unique_ptr<Rectangle> _rectTop;
                    std::unique_ptr<Rectangle> _rectMid;
                    std::unique_ptr<Rectangle> _rectBot;
                    std::unique_ptr<Button> _openButton;
                    std::vector<std::tuple<std::string, std::unique_ptr<ButtonClassic>>> _tabs;
                    std::unique_ptr<InspecterSelecterGroupDraggable> _selecters;
                    std::shared_ptr<InspecterInfo> _infos;
                    std::unique_ptr<InspecterInfoTile> _infosTile;

                    void _setInspecterOpen();
                    void _setInspecterClose();
                    void _updateTabs();
                    void _updateTabs(int index);
            };
        }
    }
}

#endif /* !COMPONENTINSPECTER_HPP_ */
