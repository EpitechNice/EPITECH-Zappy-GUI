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
            {
                _screenWidth = GetScreenWidth();
                _sizeX = _screenWidth / 3;
                _sizeY = GetScreenHeight();
                int heightPart = _sizeY / 8;
                int heightPartMini = heightPart / 4;

                _rectTopBackground = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _sizeX, 0), std::make_pair(_sizeX, heightPart), (Color){68, 69, 64, 255});
                _rectTop = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _sizeX, heightPart - heightPartMini), std::make_pair(_sizeX, heightPartMini), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _sizeX, 0), std::make_pair(_sizeX, _sizeY), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(_screenWidth + _sizeX, _sizeY - heightPart), std::make_pair(_sizeX, heightPart), (Color){112, 108, 79, 255});
                _rectTopBackground->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), "<", 30, SKYBLUE);
                _openButton->disableBubble();
                _openButton->setPosX(_screenWidth - 8 - _openButton->getSizeX());
                _openButton->setPosY(_sizeY / 2 - _openButton->getSizeY() / 2);
                _open = false;

                std::vector<std::string> names = {
                    "Select",
                    "Inspect",
                    "Tile",
                };
                int gap = 5;
                int width = (_sizeX - 40 - gap * (names.size() - 1)) / names.size();
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

                _selecters = std::make_unique<InspecterSelecterGroupDraggable>(std::make_pair(_screenWidth + 20, heightPartMini + heightButton + 20), std::make_pair(_sizeX - 40, _sizeY - heightPart - heightPartMini - heightButton - 40));
                for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                    _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);

                _infos = std::make_shared<InspecterInfo>(std::make_pair(_screenWidth + 20, heightPartMini + heightButton + 20), std::make_pair(_sizeX - 40, _sizeY - heightPart - heightPartMini - heightButton - 40));
                _infosTile = std::make_unique<InspecterInfoTile>(std::make_pair(_screenWidth + 20, heightPartMini + heightButton + 20), std::make_pair(_sizeX - 40, _sizeY - heightPart - heightPartMini - heightButton - 40));
            }


            void Inspecter::destroy()
            {
                if (_isDestroyed) return;
                _openButton->destroy();
                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->destroy();
                _selecters->destroy();
                _infos->destroy();
                _infosTile->destroy();
            }


            void Inspecter::draw()
            {
                _rectMid->draw();
                if (_tabsIndex == 0)
                    _selecters->draw();
                else if (_tabsIndex == 1)
                    _infos->draw();
                else
                    _infosTile->draw();
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
                    _selecters->reset(_infos);
                    _updateTabs(0);
                    if (_selectedTile.first == -1 || _selectedTile.second == -1) {
                        _infosTile->setInfo(nullptr);
                        for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                            _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);
                    } else {
                        _infosTile->setInfo(Zappy::GUI::Ressources::Ressources::get()->tileRessources[_selectedTile.first][_selectedTile.second]);
                        for (std::size_t i = 0; i < Zappy::GUI::Ressources::Ressources::get()->players.size(); i++)
                            if (Zappy::GUI::Ressources::Ressources::get()->players[i]->getX() == _selectedTile.first && Zappy::GUI::Ressources::Ressources::get()->players[i]->getY() == _selectedTile.second)
                                _selecters->addSelecter(Zappy::GUI::Ressources::Ressources::get()->players[i]);
                    }
                }
                _updateTabs();
                if (_tabsIndex == 0)
                    _selecters->update(_infos);
                if (_openButton->isClicked())
                    (_open) ? _setInspecterClose() : _setInspecterOpen();
            }

            bool Inspecter::mouseIsOn() const
            {
                bool isOn = _openButton->isHover() || _openButton->isClicked();
                if (_open)
                    isOn = GetMouseX() > _screenWidth - _sizeX ? true : isOn;
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
                _rectTopBackground->setPosX(_screenWidth - _sizeX);
                _rectTop->setPosX(_screenWidth - _sizeX);
                _rectMid->setPosX(_screenWidth - _sizeX);
                _rectBot->setPosX(_screenWidth - _sizeX);
                _openButton->setPosX(_screenWidth - _sizeX - 8 - _openButton->getSizeX());
                _openButton->setText(">");

                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->modPosX(-_sizeX);

                _selecters->modPosX(-_sizeX);
                _infos->modPosX(-_sizeX);
                _infosTile->modPosX(-_sizeX);

                _open = true;
            }

            void Inspecter::_setInspecterClose()
            {
                _rectTopBackground->setPosX(_screenWidth);
                _rectTop->setPosX(_screenWidth);
                _rectMid->setPosX(_screenWidth);
                _rectBot->setPosX(_screenWidth);
                _openButton->setPosX(_screenWidth - 8 - _openButton->getSizeX());
                _openButton->setText("<");

                for (auto &tab : _tabs)
                    std::get<BUTTON>(tab)->modPosX(_sizeX);

                _selecters->modPosX(_sizeX);
                _infos->modPosX(_sizeX);
                _infosTile->modPosX(_sizeX);

                _open = false;
            }


            void Inspecter::_updateTabs()
            {
                for (std::size_t i = 0; i < _tabs.size(); i++)
                    if (std::get<BUTTON>(_tabs[i])->isClicked())
                        _updateTabs(i);
            }

            void Inspecter::_updateTabs(int index)
            {
                std::get<BUTTON>(_tabs[_tabsIndex])->setColor((Color){55, 56, 40, 255});
                std::get<BUTTON>(_tabs[_tabsIndex])->enableState();
                _tabsIndex = index;
                std::get<BUTTON>(_tabs[_tabsIndex])->setColor((Color){112, 108, 79, 255});
                std::get<BUTTON>(_tabs[_tabsIndex])->disableState();
            }
        }
    }
}