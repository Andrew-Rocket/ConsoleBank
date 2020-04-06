#include "CardRepo.h"

#include <fstream>
#include <iostream>
#include <vector>
#include "../Cards/CreditCard.h"
#include "../Cards/Card.h"
#include "../Cards/NamedCard.h"


std::vector<Card*> CardRepo::GetCards()
{
	return elements;
}


bool CardRepo::Add(Card* card)
{
	//Checking if card with such number already exists
	if (Find(card->GetNumber()) != nullptr) {
		return false;
	}

	elements.push_back(card);
	return true;

}


Card* CardRepo::Find(std::string number)
{
	for (auto card : elements)
	{
		if (card->GetNumber() == number)
		{
			return card;
		}
	}
	return nullptr;
}

//Save to the local storage
void CardRepo::Save()
{
	std::ofstream save;
	save.open("cards.txt");

	for (auto element : elements)
	{
		//Finding the type
		std::string type = typeid(*element).name();
		type.erase(0, type.find(" ") + 1);

		save << type << " ";
		save << element->ToString() << std::endl;
	}

	save.close();
}

//Load from the local storage
std::vector<Card*> CardRepo::Load()
{
	std::vector<Card*> cards;

	std::string type;

	std::ifstream load("cards.txt");
	if (load.is_open())
	{
		while (load >> type)
		{
			if (type == "CreditCard") {
				std::string number;
				int cvv;
				double balance;

				load >> number;
				load >> cvv;
				load >> balance;

				cards.push_back(new CreditCard(number, cvv, balance));
			}

			if (type == "NamedCard") {
				std::string number;
				int cvv;
				double balance;
				std::string firstName;
				std::string lastName;

				load >> number;
				load >> cvv;
				load >> balance;
				load >> firstName;
				load >> lastName;

				cards.push_back(new NamedCard(number, cvv, balance, firstName, lastName));
			}
		}
		load.close();
	}

	return cards;
}
