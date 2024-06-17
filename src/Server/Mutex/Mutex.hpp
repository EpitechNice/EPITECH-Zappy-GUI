/*
** EPITECH PROJECT, 2024
** Mutex
** File description:
** Server
*/

#ifndef MUTEX_HPP
    #define MUTEX_HPP

    #include <mutex>
    #include <iostream>

namespace Zappy
{
    namespace Server
    {
        class Mutex
        {
            private:
                std::mutex _mutex;
                bool _isLocked = false;

            public:
                Mutex();
                ~Mutex() = default;

                void lock();
                void unlock();
                bool tryLock();

                std::mutex& getMutex();
        };
    }
}

#endif