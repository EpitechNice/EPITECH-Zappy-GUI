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
         * @brief Thread class
         */
        class Thread
        {
            private:
                std::thread _thread;
                bool _running;

            public:
            /**
             * @brief Construct a new Thread
             */
            Thread();
            ~Thread();

            /**
             * @brief Start the thread with a given function
             *
             * @param function The function to run in the thread
             */
            void start(std::function<void()> function);

            /**
             * @brief Join the thread
             *
             * @brief This function blocks until the thread finishes its execution.
             */
            void join();

        };
    }
}

#endif