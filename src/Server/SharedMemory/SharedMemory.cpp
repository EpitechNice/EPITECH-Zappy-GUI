/*
** EPITECH PROJECT, 2024
** SharedMemory
** File description:
** Server
*/

#include "SharedMemory.hpp"
namespace Zappy
{
    namespace Server
    {
        void SharedMemory::addCommand(const std::string& command)
        {
            _mutex.lock();
            _commandList.push_back(command + "\n");
            _mutex.unlock();
            _condVar.notify_one();
        }

        std::string SharedMemory::getCommand()
        {
            if (_commandList.empty()) return "";

            _mutex.lock();
            std::string command = _commandList.front();
            _commandList.pop_front();
            _mutex.unlock();
            return command;
        }

        bool SharedMemory::hasCommands()
        {
            return !_commandList.empty();
        }
    }
}