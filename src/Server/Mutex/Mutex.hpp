/*
** EPITECH PROJECT, 2024
** GUI
** File description:
** Mutex
*/

#ifndef MUTEX_HPP_
    #define MUTEX_HPP_

    #include <mutex>

namespace Zappy {
    /**
     * @brief A simple mutex class
     */
    class Mutex {
        public:
            Mutex() = default;
            ~Mutex() = default;

            /**
             * @brief Lock the mutex
             */
            void lock();

            /**
             * @brief Unlock the mutex
             */
            void unlock();

            /**
             * @brief Try to lock the mutex.
             *
             * @return `true` if the mutex was successfully locked, `false` if it was already locked
             */
            bool tryLock();

        protected:
        private:
            std::mutex _mutex;
            bool _isLocked = false;
    };
}

#endif /* !MUTEX_HPP_ */
