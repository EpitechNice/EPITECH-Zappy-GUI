/*
** EPITECH PROJECT, 2024
** Mutex
** File description:
** Server
*/

#ifndef MUTEX_HPP
    #define MUTEX_HPP

    #include <mutex>

namespace Zappy
{
    namespace Server
    {
        class Mutex
        {
            private:
                std::mutex _mutex;

            public:
                Mutex();
                ~Mutex() = default;

                void lock();
                void unlock();

                std::mutex& getMutex();
        };
    }
}

#endif