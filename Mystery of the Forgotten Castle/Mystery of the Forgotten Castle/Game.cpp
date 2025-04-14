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

		if (command.action == actions::QUIT)
		{
			std::cout << "Goodbye!\n";
			break;
		}
	}
}

inline void Game::ConnectRooms(const std::shared_ptr<Room>& room1, const std::string& direction1, const std::shared_ptr<Room>& room2, const std::string& direction2)
{
	room1->Connect(direction1, room2);
	room2->Connect(direction2, room1);
}
