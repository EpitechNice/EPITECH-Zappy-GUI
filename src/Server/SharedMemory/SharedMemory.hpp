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

namespace Zappy
{
    namespace Server
    {
        #pragma pack(push, 1)
        struct SharedData {
            void *data;
        };
        #pragma pack(pop)

        class SharedMemory
        {
            private:
                SharedData* _dataPool;

            public:
                SharedMemory(std::string comand);
                ~SharedMemory();

                void updateData(Zappy::Server::SharedData& newData);

                const Zappy::Server::SharedData* getData() const;
        };
    }
}

#endif