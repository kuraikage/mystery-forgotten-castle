#include "Game.h"
#include <iostream>
#include <string>
#include "Parser.h"
#include "Commands.h"
//#include "Third Party/magic_enum.hpp"

void Game::Run()
{
	std::cout << "Welcome to the Mystery of the Forgotten Castle!\n";

	/*for (auto consequence : magic_enum::enum_values<Consequence>())
	{
		std::cout << magic_enum::enum_name(consequence) << std::endl;
	}*/

	Parser parser{};

	while (true)
	{
		std::cout << "> ";
		std::string input;
		std::getline(std::cin, input);

		auto command = parser.ParseCommand(input);

		if (command.action == Actions::QUIT)
		{
			std::cout << "Goodbye!\n";
			break;
		}
	}
}
