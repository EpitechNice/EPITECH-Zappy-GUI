/*
** EPITECH PROJECT, 2024
** SharedMemory
** File description:
** Server
*/

#ifndef SHAREDMEMORY_HPP
    #define SHAREDMEMORY_HPP

    #include <sys/mman.h>
    #include <string>
    #include <queue>
    #include <condition_variable>
    #include <iostream>

    #include "Mutex.hpp"

namespace Zappy {
    namespace Server {
        class SharedMemory {
        public:
            SharedMemory() = default;
            ~SharedMemory() = default;

            void addCommand(const std::string& command);
            bool hasCommands();
            std::string getCommand();

        private:
            std::deque<std::string> _commandList;
            Zappy::Mutex _mutex;
            std::condition_variable _condVar;
        };
    }
}

#endif