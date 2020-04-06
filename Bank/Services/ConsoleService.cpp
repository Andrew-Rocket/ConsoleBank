#include "ConsoleService.h"
#include <iostream>
#include <vector>
#include "../Shop/ProductShop.h"
#include "CreditCardService.h"



//Command parser
std::vector<std::string> ConsoleService::GetCommand()
{
	std::string command;
	std::vector<std::string> parsed;
	std::getline(std::cin, command);
	command += " ";

	while (true) {
		parsed.push_back(command.substr(0, command.find(" ")));
		command.erase(0, command.find(" ") + 1);

		if (strcmp(&command[0], "\0") == 0 || strcmp(&command[0], " ") == 0)
		{
			break;
		}
	}
	return parsed;
}

//Checking command arguments
bool ConsoleService::CheckCommand(std::vector<std::string> com, int n)
{
	if (com.size() == n)
	{
		return true;
	}

	return false;

}

//Show help
void ConsoleService::Help()
{
	std::cout << std::endl;
	std::cout << "help - view help" << std::endl;
	std::cout << "info - print out all the cards" << std::endl;
	std::cout << "save - save the cards" << std::endl;
	std::cout << "create {number} {cvv} {balance} [first name] [last name] - create new card (the card number must be unique)" << std::endl;
	std::cout << "find {number} - find credit card by number" << std::endl;
	std::cout << "send {donor} {recipient} {amount} - transfer money from card to card" << std::endl;
	std::cout << "products - print out all the products" << std::endl;
	std::cout << "buy {product} {card number} - buy product" << std::endl;
	std::cout << "unite {first card} {second card} - transfer all money from first card to second" << std::endl;
	std::cout << "add {number} {amount} - add money to the card" << std::endl;
	std::cout << "withdraw {number} {amount} - withdraw money from the card" << std::endl;
	std::cout << "exit - save and exit from the program" << std::endl;
	std::cout << std::endl;
}

//Todo: good command system
void ConsoleService::StartCommands()
{
	while (true)
	{
		try {

			//Command "system"
			std::cout << "/";
			auto command = GetCommand();

			if (command.at(0) == "exit" && CheckCommand(command, 1))
			{
				creditСardService->Save();
				break;

			}

			if (command.at(0) == "help" && CheckCommand(command, 1))
			{
				Help();
				continue;
			}

			if (command.at(0) == "save" && CheckCommand(command, 1))
			{
				creditСardService->Save();
				continue;
			}

			if (command.at(0) == "info" && CheckCommand(command, 1))
			{
				creditСardService->PrintAll();
				continue;
			}

			if (command.at(0) == "find" && CheckCommand(command, 2))
			{
				std::cout << creditСardService->FindByNumber(command.at(1))->ToString() << std::endl;
				continue;
			}

			if (command.at(0) == "send" && CheckCommand(command, 4))
			{

				if (creditСardService->Send(command.at(1), command.at(2), std::stod(command.at(3))))
				{
					std::cout << "Transaction successfully completed!" << std::endl;
				}
				else
				{
					std::cout << "Transaction failed!" << std::endl;
				}

				continue;
			}

			if (command.at(0) == "create" && CheckCommand(command, 4))
			{
				creditСardService->Create(
					command.at(1),
					std::stoi(command.at(2)),
					std::stod(command.at(3))
				) ? std::cout << "Card added successfully!" << std::endl
					: std::cout << "Card with such number already exists!" << std::endl;

				continue;
			}

			if (command.at(0) == "create" && CheckCommand(command, 6))
			{
				creditСardService->Create(
					command.at(1),
					std::stoi(command.at(2)),
					std::stod(command.at(3)),
					command.at(4),
					command.at(5)
				) ? std::cout << "Card added successfully!" << std::endl
					: std::cout << "Card with such number already exists!" << std::endl;

				continue;
			}

			if (command.at(0) == "create" && CheckCommand(command, 6))
			{
				creditСardService->Create(
					command.at(1),
					std::stoi(command.at(2)),
					std::stod(command.at(3)),
					command.at(4),
					command.at(5)
				) ? std::cout << "Card added successfully!" << std::endl
					: std::cout << "Card with such number already exists!" << std::endl;

				continue;
			}

			if (command.at(0) == "products" && CheckCommand(command, 1))
			{
				productShop->PrintProducts();
				std::cout << std::endl;
				continue;
			}

			if (command.at(0) == "buy" && CheckCommand(command, 3))
			{
				const auto product = productShop->Buy(command.at(1), command.at(2));
				if (product != "")
				{
					std::cout << product << std::endl;
					continue;
				}
				std::cout << "Error" << std::endl;
				continue;

			}

			if (command.at(0) == "unite" && CheckCommand(command, 3))
			{
				auto card = creditСardService->FindByNumber(command.at(1));
				auto card2 = creditСardService->FindByNumber(command.at(2));
				*card + card2;
				continue;
			}

			if (command.at(0) == "add" && CheckCommand(command, 3))
			{
				auto card = creditСardService->FindByNumber(command.at(1));
				*card += std::stod(command.at(2));
				continue;
			}

			if (command.at(0) == "withdraw" && CheckCommand(command, 3))
			{
				auto card = creditСardService->FindByNumber(command.at(1));
				*card -= std::stod(command.at(2));
				continue;
			}

			std::cout << "No such command with such arguments!" << std::endl;
		}
		catch (CvvException& ex) {
			std::cout << ex.what() << std::endl;
			std::cout << "Cvv was: " << ex.GetCvv() << std::endl;
		}
		catch (NotNumericStringException& ex)
		{
			std::cout << ex.what() << std::endl;
			std::cout << "The number was: " << ex.GetString() << std::endl;
		}
		catch (std::invalid_argument& ex)
		{
			std::cout << "Wrong arguments!" << std::endl;
		}
	}
}
