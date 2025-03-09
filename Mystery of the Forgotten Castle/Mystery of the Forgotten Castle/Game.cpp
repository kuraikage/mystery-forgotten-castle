#include "Game.h"
#include <iostream>
#include <string>
#include "Parser.h"
#include "Commands.h"

void Game::Run()
{
	std::cout << "Welcome to the Mystery of the Forgotten Castle!\n";

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
