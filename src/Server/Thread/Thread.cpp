/*
** EPITECH PROJECT, 2024
** Thread
** File description:
** Server
*/

#include "Thread.hpp"

namespace Zappy
{
    namespace Server
    {
        Thread::Thread()
        {
            this->_running = false;
        }

        Thread::~Thread()
        {
            this->join();
        }

        void Thread::start(void (*function)(void))
        {
            if (!this->_running) {
                this->_running = true;
                this->_thread = std::thread(function);
            }
        }

        void Thread::join()
        {
            if (this->_running && this->_thread.joinable()) {
                this->_thread.join();
                this->_running = false;
            }
        }
    }

}