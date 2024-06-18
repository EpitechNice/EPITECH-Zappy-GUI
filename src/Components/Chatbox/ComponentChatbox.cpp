/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** ComponentChatbox
*/

#include "ComponentChatbox.hpp"

namespace Zappy {
    namespace GUI {
        namespace Component {
            Chatbox::Chatbox()
            {
                _sizeX = GetScreenWidth() / 3;
                _sizeY = GetScreenHeight();
                int _sizeYPart = _sizeY / 8;
                int _sizeYPartMini = _sizeYPart / 4;

                _rectTopBackground = std::make_unique<Rectangle>(std::make_pair(-_sizeX, 0), std::make_pair(_sizeX, _sizeYPart), (Color){68, 69, 64, 255});
                _rectTop = std::make_unique<Rectangle>(std::make_pair(-_sizeX, _sizeYPart - _sizeYPartMini), std::make_pair(_sizeX, _sizeYPartMini), (Color){112, 108, 79, 255});
                _rectMid = std::make_unique<Rectangle>(std::make_pair(-_sizeX, 0), std::make_pair(_sizeX, _sizeY), (Color){68, 69, 64, 255});
                _rectBot = std::make_unique<Rectangle>(std::make_pair(-_sizeX, _sizeY - _sizeYPart), std::make_pair(_sizeX, _sizeYPart), (Color){112, 108, 79, 255});
                _rectTopBackground->setStroke(1, BLACK);
                _rectMid->setStroke(3, BLACK);
                _rectBot->setStroke(1, BLACK);

                _openButton = std::make_pair(std::make_unique<Button>(std::make_pair(0, 0), std::make_pair(-5, -40), ">", 30, ORANGE), "");

                std::pair<float, float> buttonSize = {_openButton.first->getSizeX(), _openButton.first->getSizeY()};
                _openButton.first->setPosX(8);
                _openButton.first->setPosY(_sizeY / 2 - buttonSize.second / 2);
                _notifCircle = std::make_unique<Circle>(std::make_pair( _openButton.first->getSizeX() + _openButton.first->getPosX(), _openButton.first->getPosY()), 4, RED);

                std::vector<std::string> names = {
                    "Server",
                    "Global",
                };
                int gap = 5;
                int width = (_sizeX - 40 - gap * (names.size() - 1)) / names.size();
                int _sizeYButton = _sizeYPart - _sizeYPartMini;
                int y = -_sizeX * 2 + 20;
                for (auto &name : names) {
                    _chats.push_back(std::make_tuple(
                        name,
                        std::make_unique<ButtonClassic>(std::make_pair(y, _sizeYPartMini), std::make_pair(width, _sizeYButton), name, 20, (Color){55, 56, 40, 255}),
                        std::make_unique<TextGroupDraggable>(std::make_pair(-_sizeX + 10, _sizeYPart + 10), std::make_pair(_sizeX - 20, _sizeY - _sizeYPart * 2), 20),
                        std::make_unique<Circle>(std::make_pair(y + width, _sizeYPartMini), 4, (Color){255, 0, 0, 255}),
                        0
                    ));
                    y += width + gap;
                }
                _chatIndex = 0;
                std::get<BUTTON>(_chats[_chatIndex])->setColor((Color){112, 108, 79, 255});
                std::get<BUTTON>(_chats[_chatIndex])->disableState();
                _open = false;
                _hasNotif = false;

                setRef();
                _refSizeX = _sizeX / _refWidth * 100;
            }


            void Chatbox::draw()
            {
                _rectMid->draw();
                std::get<TEXT_GROUP>(_chats[_chatIndex])->draw();
                _rectTopBackground->draw();
                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->draw();
                    if (std::get<NOTIF_COUNT>(chat) > 0)
                        std::get<NOTIF>(chat)->draw();
                }
                _rectTop->draw();
                _rectBot->draw();
                _openButton.first->draw();
                if (_hasNotif && !_open)
                    _notifCircle->draw();
            }

            void Chatbox::resize()
            {
                setRef();
                _sizeX = _refSizeX * _refWidth / 100;
                _sizeY = _refHeight;

                _rectTopBackground->resize();
                _rectTop->resize();
                _rectMid->resize();
                _rectBot->resize();
                _openButton.first->resize();
                _notifCircle->resize();
                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->resize();
                    std::get<TEXT_GROUP>(chat)->resize();
                    std::get<NOTIF>(chat)->resize();
                    std::get<NOTIF>(chat)->setPosX(std::get<BUTTON>(chat)->getPosX() + std::get<BUTTON>(chat)->getSizeX());
                }
            }

            void Chatbox::update()
            {
                _updateChatbox();
                std::get<TEXT_GROUP>(_chats[_chatIndex])->update();
                if (_openButton.first->isClicked(_openButton.second))
                    (_open) ? _setChatboxClose() : _setChatboxOpen();

                if (IsKeyReleased(KEY_ENTER)) {
                    std::vector<std::string> names = {
                        "Aeliondw",
                        "Arnaud",
                        "Dan13615",
                        "Dragusheen",
                        "H4rdeol",
                        "Tech0ne",
                    };
                    std::vector<std::string> messages = {
                        "Hello everyone! How are you doing?",
                        "I think we should go to the north, or maybe the east ?... No ! The west ! AHH I don't know !",
                        "I'm going to the south, I need some wood !",
                        "Can someone give me some food ? I'm starving !",
                        "UwU",
                    };
                    int randomName = rand() % names.size();
                    int randomMessage = rand() % messages.size();
                    int randomChat = rand() % _chats.size();
                    addMessage(messages[randomMessage], names[randomName], std::get<NAME>(_chats[randomChat]));
                }
            }

            void Chatbox::addMessage(const std::string &message, const std::string &name, const std::string &tabName)
            {
                _hasNotif = true;
                for (std::size_t i = 0; i < _chats.size(); i++) {
                    if (std::get<NAME>(_chats[i]) == tabName) {
                        std::get<TEXT_GROUP>(_chats[i])->addText(name, message, 5, (Color){207, 205, 164, 255});
                        if ((int)i != _chatIndex)
                            std::get<NOTIF_COUNT>(_chats[i])++;
                        break;
                    }
                }
            }

            bool Chatbox::mouseIsOn() const
            {
                bool isOn = _openButton.first->isHover() || _openButton.first->isClicked();
                if (_open)
                    isOn = GetMouseX() < _sizeX ? true : isOn;
                return isOn;
            }


            void Chatbox::_setChatboxOpen()
            {
                _rectTopBackground->setPosX(0);
                _rectTop->setPosX(0);
                _rectMid->setPosX(0);
                _rectBot->setPosX(0);
                _openButton.first->setPosX(_sizeX + 8);
                _openButton.first->setText("<");

                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->modPosX(_sizeX * 2);
                    std::get<TEXT_GROUP>(chat)->setPosX(10);
                    std::get<NOTIF>(chat)->modPosX(_sizeX * 2);
                }
                _open = true;
                _hasNotif = false;
            }

            void Chatbox::_setChatboxClose()
            {
                _rectTopBackground->setPosX(-_sizeX * 2);
                _rectTop->setPosX(-_sizeX * 2);
                _rectMid->setPosX(-_sizeX * 2);
                _rectBot->setPosX(-_sizeX * 2);
                _openButton.first->setPosX(8);
                _openButton.first->setText(">");

                for (auto &chat : _chats) {
                    std::get<BUTTON>(chat)->modPosX(-_sizeX * 2);
                    std::get<TEXT_GROUP>(chat)->setPosX(-_sizeX * 2 + 10);
                    std::get<NOTIF>(chat)->modPosX(-_sizeX * 2);
                }
                _open = false;
                for (auto &chat : _chats)
                    if (std::get<NOTIF_COUNT>(chat) > 0)
                        _hasNotif = true;
            }


            void Chatbox::_updateChatbox()
            {
                int newIndex = _chatIndex;
                for (std::size_t i = 0; i < _chats.size(); i++)
                    if (std::get<BUTTON>(_chats[i])->isClicked())
                        newIndex = i;
                if (newIndex != _chatIndex) {
                    _chatIndex = newIndex;
                    for (auto &chat : _chats) {
                        std::get<BUTTON>(chat)->enableState();
                        std::get<BUTTON>(chat)->setColor((Color){55, 56, 40, 255});
                    }
                    std::get<BUTTON>(_chats[_chatIndex])->disableState();
                    std::get<BUTTON>(_chats[_chatIndex])->setColor((Color){112, 108, 79, 255});
                    std::get<NOTIF_COUNT>(_chats[_chatIndex]) = 0;
                }
            }
        }
    }
}