#pragma once
#include "Room.h"
class Game
{
public:
	void Run();
    void ConnectRooms(const std::shared_ptr<Room>& room1, const std::string& direction1,
        const std::shared_ptr<Room>& room2, const std::string& direction2);
};

