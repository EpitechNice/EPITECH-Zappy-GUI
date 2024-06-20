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
        /**
         * @brief SharedMemory class
         */
        class SharedMemory {
        public:
            /**
             * @brief Construct a new SharedMemory object (list of command)
             */
            SharedMemory() = default;
            ~SharedMemory() = default;

            /**
             * @brief Add a command to the shared memory
             *
             * @param command The command to add
             */
            void addCommand(const std::string& command);

            /**
             * @brief Check if there are commands in the shared memory
             *
             * @return true if there are commands, false otherwise
             */
            bool hasCommands();

            /**
             * @brief Get a command from the shared memory
             *
             * @return The command from the shared memory
             */
            std::string getCommand();
        private:
            std::deque<std::string> _commandList;
            Zappy::Mutex _mutex;
            std::condition_variable _condVar;
        };
    }
}

#endif