#pragma once
#include <string>

struct SCommand
{
	std::string action;
	std::string object;
};

class Parser
{
public:
	SCommand ParseCommand(std::string_view input) const;
};