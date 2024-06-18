/*
** EPITECH PROJECT, 2024
** SharedMemory
** File description:
** Server
*/

#include "SharedMemory.hpp"
#include <iostream>

namespace Zappy
{
    namespace Server
    {
        void SharedMemory::addCommand(const std::string& command)
        {
            {
                std::lock_guard<std::mutex> lock(_mutex);
                _commandList.push_back(command);
            }
            _condVar.notify_one();
        }

        std::string SharedMemory::getCommand()
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _condVar.wait(lock, [this] { return !_commandList.empty(); });

            if (!_commandList.empty()) {
                std::string command = _commandList.front();
                _commandList.pop_front();
                return command;
            }
            return "";
        }

        bool SharedMemory::hasCommands()
        {
            std::lock_guard<std::mutex> lock(_mutex);
            return !_commandList.empty();
        }

        void SharedMemory::lockMutex()
        {
            std::lock_guard<std::mutex> lock(_mutex);
        }

        void SharedMemory::unlockMutex()
        {
            std::lock_guard<std::mutex> unlock(_mutex);
        }
    }
}