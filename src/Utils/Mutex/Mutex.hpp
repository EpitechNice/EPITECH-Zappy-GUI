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
    class Mutex {
        public:
            Mutex() = default;
            ~Mutex() = default;

            void lock();
            void unlock();
            bool tryLock();

        protected:
        private:
            std::mutex _mutex;
            bool _isLocked = false;
    };
}

#endif /* !MUTEX_HPP_ */
