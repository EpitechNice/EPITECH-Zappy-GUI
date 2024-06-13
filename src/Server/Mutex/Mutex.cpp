/*
** EPITECH PROJECT, 2024
** Mutex
** File description:
** Server
*/

#include "Mutex.hpp"

namespace Zappy
{
    namespace Server
    {
        Mutex::Mutex()
        {}

        void Mutex::lock()
        {
            this->_mutex.lock();
        }

        void Mutex::unlock()
        {
            this->_mutex.unlock();
        }

        std::mutex& Mutex::getMutex()
        {
            return this->_mutex;
        }
    }
}