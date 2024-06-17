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
            this->_isLocked = true;
            this->_mutex.lock();
        }

        void Mutex::unlock()
        {
            this->_mutex.unlock();
            this->_isLocked = false;
        }

        bool Mutex::tryLock()
        {
            std::cout << "trylock: " << (this->_isLocked ? "true" : "false") << std::endl;
            if (_isLocked)
                return false;
            _mutex.lock();
            _isLocked = true;
            return true;
        }

        std::mutex& Mutex::getMutex()
        {
            return this->_mutex;
        }
    }
}