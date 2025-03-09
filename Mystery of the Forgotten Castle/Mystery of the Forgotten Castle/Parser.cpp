#include "Parser.h"
#include <string_view>
#include <algorithm>
#include <cctype>

Command Parser::ParseCommand(std::string_view input) const
{
	if (input.empty())
		return { "", "" };

	auto trim = [](std::string_view input) -> std::string_view
	{
		const auto stringBegin = input.find_first_not_of(' ');

		if (stringBegin == std::string_view::npos)
			return std::string_view{};

		const auto stringEnd = input.find_last_not_of(' ');

		if (stringEnd == std::string_view::npos)
			return std::string_view{};

		const auto stringRange = stringEnd - stringBegin + 1;
		return input.substr(stringBegin, stringRange);
	};

	input = trim(input);

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

std::string Parser::ToLower(std::string_view input) const
{
	std::string lowerInput(input); // Convert to std::string (mutable)
	std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
		[](unsigned char c) { return std::tolower(c); });
	return lowerInput;
}
