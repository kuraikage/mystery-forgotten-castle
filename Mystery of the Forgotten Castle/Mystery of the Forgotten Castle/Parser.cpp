#include "Parser.h"
#include <string_view>
#include "StringUtils.hpp"

Command Parser::ParseCommand(std::string_view input) const
{
	if (input.empty())
		return { "", "" };

	input = Trim(input);

	// checking the emptiness of the trimmed input
	if (input.empty())
		return { "", "" };

	// Find the first space in the input
	size_t spaceIndex = input.find(' ');

	// If there is no space, the input is the action
	if (spaceIndex == std::string_view::npos)
	{
		return { ToLower(input), "" };
	}

	// Spitting the input into the action and object
	const auto action = input.substr(0, spaceIndex);
	const auto object = input.substr(spaceIndex + 1);

	return { ToLower(action), ToLower(object) };
}