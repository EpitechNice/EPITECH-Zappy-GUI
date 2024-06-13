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
        SharedMemory::SharedMemory(std::string command)
        {
            //Set command in the linked list of command
        }

        SharedMemory::~SharedMemory()
        {}

        void SharedMemory::updateData(SharedData& newData)
        {
            *this->_dataPool = newData;
        }

        const Zappy::Server::SharedData* SharedMemory::getData() const
        {
            return this->_dataPool;
        }
    }
}