#pragma once
#include <string>

struct Command
{
	std::string action;
	std::string object;
};

class Parser
{
public:
	Command ParseCommand(std::string_view input) const;

private:
	std::string ToLower(std::string_view input) const;
};