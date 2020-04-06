#pragma once
#include <iostream>
#include <map>

#include "../Services/CardService.h"
#include "Shop.h"
#include "Products/Product.h"
#include "ProductsFactory.h"

class ProductShop : public Shop
{
private:
	ProductsFactory* productsFactory;
	std::map<std::string, Product*>* products;
	CardService* creditCardService;


public:


	std::string Buy(std::string key, std::string number)
	{

		const double price = products->at(key)->GetPrice();
		if (auto card = creditCardService->FindByNumber(number)) {
			if (CheckEmv(card) && card->GetBalance() >= price)
			{
				card->SetBalance(card->GetBalance() - price);
				return products->at(key)->GetProduct();
			}
		}
		return "";
	}


	void PrintProducts()
	{
		for (auto element : *products)
		{
			std::cout << element.first << " " << element.second->GetPrice() << std::endl;
		}

	}

	bool CheckEmv(Card* card)
	{
		int salt = 512; //Config
		if (card->GetEmv() == card->GetCvv() * salt)
		{
			return true;
		}
		return false;
	}
	//Generating products map

	ProductShop(ProductsFactory* productsFactory, CardService* cardService)
	{
		this->productsFactory = productsFactory;
		products = productsFactory->GetProducts();
		creditCardService = cardService;
	}
};
