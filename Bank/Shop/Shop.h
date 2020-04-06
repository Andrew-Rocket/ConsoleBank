#pragma once
#include "../Cards/Card.h"
#include "Products/Product.h"

class Shop
{
public:
	virtual std::string Buy(std::string key, std::string number) = 0;
	virtual void PrintProducts() = 0;
	virtual bool CheckEmv(Card* card) = 0;
};
