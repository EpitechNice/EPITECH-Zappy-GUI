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

namespace Zappy {
    namespace Server {
        class SharedMemory {
        public:
            SharedMemory() = default;
            ~SharedMemory() = default;

            void addCommand(const std::string& command);
            bool hasCommands();
            std::string getCommand();

            void lockMutex();
            void unlockMutex();

        private:
            std::deque<std::string> _commandList;
            std::mutex _mutex;
            std::condition_variable _condVar;
        };
    }
}

#endif