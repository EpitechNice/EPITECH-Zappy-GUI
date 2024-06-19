/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Mutex
*/

#include "Mutex.hpp"
#include <iostream>

namespace Zappy {
    void Mutex::lock()
    {
        _isLocked = true;
        _mutex.lock();
    }

    void Mutex::unlock()
    {
        _mutex.unlock();
        _isLocked = false;
    }

    bool Mutex::tryLock()
    {
        std::cout << "trylock: " << (_isLocked ? "true" : "false") << std::endl;
        if (_isLocked) return false;
        _mutex.lock();
        _isLocked = true;
        return true;
    }
}