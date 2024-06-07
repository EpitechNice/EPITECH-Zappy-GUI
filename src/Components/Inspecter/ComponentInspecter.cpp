/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentInspecter
*/

#include "ComponentInspecter.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Inspecter::Inspecter()
                : _isDestroyed(false)
            {
                int height = GetScreenHeight();
                _screenWidth = GetScreenWidth();
                _width = _screenWidth / 3;
                int heightPart = height / 8;
                int heightPartMini = heightPart / 4;

                _rectTopBackground = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, 0), std::make_pair(_width, heightPart), (Color){68, 69, 64, 255});
                _rectTop = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, heightPart - heightPartMini), std::make_pair(_width, heightPartMini), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, 0), std::make_pair(_width, height), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _width, height - heightPart), std::make_pair(_width, heightPart), (Color){112, 108, 79, 255});
                _rectTopBackground->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), "<", 30, SKYBLUE);
                _openButton->disableBubble();
                _buttonSize = _openButton->getSize();
                _openButton->setPos(std::make_pair(_screenWidth - 8 - _buttonSize.first, height / 2 - _buttonSize.second / 2));
                _open = false;

                std::vector<std::string> names = {
                    "Select",
                    "Inspect",
                };
                int gap = 5;
                int width = (_width - 40 - gap * (names.size() - 1)) / names.size();
                int heightButton = heightPart - heightPartMini;
                int y = _screenWidth + 20;
                for (auto &name : names) {
                    _tabs.push_back(std::make_tuple(
                        name,
                        std::make_unique<ButtonClassic>(std::make_pair(y, heightPartMini), std::make_pair(width, heightButton), name, 20, (Color){55, 56, 40, 255})
                    ));
                    y += width + gap;
                }
                _tabsIndex = 0;
                std::get<BUTTON>(_tabs[_tabsIndex])->setColor((Color){112, 108, 79, 255});
                std::get<BUTTON>(_tabs[_tabsIndex])->disableState();

                _selecters = std::make_unique<InspecterSelecterGroupDraggable>(std::make_pair(_screenWidth + 20, heightPartMini + heightButton + 20), std::make_pair(_width - 40, height - heightPart - heightPartMini - heightButton - 40));
                for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                    _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);
            }

            Inspecter::~Inspecter()
            {
                destroy();
            }


            void Inspecter::destroy()
            {
                if (_isDestroyed)
                    return;
                _openButton->destroy();
                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->destroy();
                _selecters->destroy();
            }


            void Inspecter::draw()
            {
                _rectMid->draw();
                _selecters->draw();
                _rectTopBackground->draw();
                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->draw();
                _rectTop->draw();
                _rectBot->draw();
                _openButton->draw();
            }

            void Inspecter::update(std::pair<int, int> selectedTile)
            {
                if (_selectedTile != selectedTile) {
                    _selectedTile = selectedTile;
                    _selecters->reset();
                    if (_selectedTile.first == -1 || _selectedTile.second == -1)
                        for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                            _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);
                    else
                        for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                            if (Zappy::GUI::Ressources::Ressources::get()->players[i]->getX() == _selectedTile.first && Zappy::GUI::Ressources::Ressources::get()->players[i]->getY() == _selectedTile.second)
                                _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);
                }
                _updateTabs();
                _selecters->update();
                if (_openButton->isClicked())
                    (_open) ? _setInspecterClose() : _setInspecterOpen();
            }

            bool Inspecter::mouseIsOn() const
            {
                bool isOn = _openButton->isHover() || _openButton->isClicked();
                if (_open)
                    isOn = GetMouseX() > _screenWidth - _width ? true : isOn;
                return isOn;
            }

            void Inspecter::open()
            {
                if (!_open)
                    _setInspecterOpen();
            }

            void Inspecter::close()
            {
                if (_open)
                    _setInspecterClose();
            }


            void Inspecter::_setInspecterOpen()
            {
                _rectTopBackground->setPosX(_screenWidth - _width);
                _rectTop->setPosX(_screenWidth - _width);
                _rectMid->setPosX(_screenWidth - _width);
                _rectBot->setPosX(_screenWidth - _width);
                _openButton->setPosX(_screenWidth - _width - 8 - _buttonSize.first);
                _openButton->setText(">");

                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->modPosX(-_width);

                _selecters->modPosX(-_width);

                _open = true;
            }

            void Inspecter::_setInspecterClose()
            {
                _rectTopBackground->setPosX(_screenWidth);
                _rectTop->setPosX(_screenWidth);
                _rectMid->setPosX(_screenWidth);
                _rectBot->setPosX(_screenWidth);
                _openButton->setPosX(_screenWidth - 8 - _buttonSize.first);
                _openButton->setText("<");

                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->modPosX(_width);

                _selecters->modPosX(_width);

                _open = false;
            }


            void Inspecter::_updateTabs()
            {
                for (std::size_t i = 0; i < _tabs.size(); i++) {
                    if (std::get<BUTTON>(_tabs[i])->isClicked()) {
                        std::get<BUTTON>(_tabs[_tabsIndex])->setColor((Color){55, 56, 40, 255});
                        std::get<BUTTON>(_tabs[_tabsIndex])->enableState();
                        _tabsIndex = i;
                        std::get<BUTTON>(_tabs[_tabsIndex])->setColor((Color){112, 108, 79, 255});
                        std::get<BUTTON>(_tabs[_tabsIndex])->disableState();
                    }
                }
            }
        }
    }
}