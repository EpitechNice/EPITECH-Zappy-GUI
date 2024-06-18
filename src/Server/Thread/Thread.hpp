/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Server
*/

#ifndef THREAD_HPP
    #define THREAD_HPP

    #include <thread>
    #include <functional>

namespace Zappy
{
    namespace Server
    {
        /**
         * @brief Thread communication class
         */
        class Thread
        {
            private:
                std::thread _thread;
                bool _running;

            public:
                /**
                 * @brief Construct a Thread
                 */
                Thread();
                ~Thread();

                /**
                 * @brief Start a Thread
                 */
                void start(std::function<void()> function);
                /**
                 * @brief Join a Thread
                 */
                void join(void);

        };
    }
}

#endif