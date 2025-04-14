#pragma once
#include <string>
#include <memory>

// Forward declaration of Room to avoid circular dependency
class Room;

struct SExit
{
	std::string_view direction;
	std::weak_ptr<Room> destination;
	bool isLocked;
	std::string description;
};

