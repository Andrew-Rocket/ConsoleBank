#pragma once
#include <string>
#include <vector>

#include "../Shop/ProductShop.h"
#include "CommandService.h"

class ConsoleService : public CommandService
{

public:
	Shop* productShop;
	CardService* creditСardService;
	int lol = 5;

public:

	std::vector<std::string> GetCommand();
	bool CheckCommand(std::vector<std::string> com, int n);
	void StartCommands();
	void Help();


	ConsoleService(Shop* shop, CardService* cardService)
	{
		productShop = shop;
		creditСardService = cardService;
	}
};
