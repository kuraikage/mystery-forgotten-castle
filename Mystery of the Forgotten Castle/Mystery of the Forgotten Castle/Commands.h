#pragma once
#include <string_view>

namespace actions
{
	constexpr std::string_view MOVE = "move";
	constexpr std::string_view GO = "go";
	constexpr std::string_view QUIT = "quit";
}

namespace directions
{
	constexpr std::string_view NORTH = "north";
	constexpr std::string_view SOUTH = "south";
	constexpr std::string_view EAST = "east";
	constexpr std::string_view WEST = "west";
}

namespace items
{
	constexpr std::string_view KEY = "key";
}

// scoped enum
enum class Consequence
{
	MOVE,
	USE,
};