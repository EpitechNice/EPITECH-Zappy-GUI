/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Server
*/

#ifndef THREAD_HPP
    #define THREAD_HPP

    #include <thread>

namespace Zappy
{
    namespace Server
    {
        class Thread
        {
            private:
                std::thread _thread;
                bool _running;

            public:
                Thread();
                ~Thread();

                void start(void (*function)(void));
                void join(void);

        };
    }
}

#endif