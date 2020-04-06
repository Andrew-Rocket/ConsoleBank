#include <iostream>
#include "Repositories/CardRepo.h"
#include "Services/CreditCardService.h"
#include "Services/ConsoleService.h"



int main()
{
	//DI
	Repo<Card>* cardRepo = new CardRepo();
	CardService* creditCardService = new CreditCardService(cardRepo);
	ProductsFactory* productsFactory = new ProductsFactory();
	Shop* productShop = new ProductShop(productsFactory, creditCardService);
	CommandService* consoleService = new ConsoleService(productShop, creditCardService);

	std::cout << "Type 'help' to see all the commands" << std::endl;

	consoleService->StartCommands();
}
