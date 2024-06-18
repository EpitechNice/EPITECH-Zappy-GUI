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
        /**
         * @brief SharedMemory class for command list
         */
        class SharedMemory {
        public:
            /**
             * @brief Construct SharedMemory by default
            */
            SharedMemory() = default;
            ~SharedMemory() = default;

            /**
             * @brief Add a request to the request list
             * @param command The command to add to the list
             */
            void addCommand(const std::string& command);
            /**
             * @brief Check if the request list has a pending request
            */
            bool hasCommands();
            /**
             * @brief Retrieved the order at the top of the list
            */
            std::string getCommand();

            /**
             * @brief Lock the mutex
            */
            void lockMutex();
            /**
             * @brief Unlock the mutex
            */
            void unlockMutex();

        private:
            std::deque<std::string> _commandList;
            std::mutex _mutex;
            std::condition_variable _conditionVariable;
        };
    }
}

#endif