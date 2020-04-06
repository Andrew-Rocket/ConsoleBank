#pragma once
#include <string>

class Product
{
public:
	double price = 0;

	double GetPrice()
	{
		return price;
	};

	virtual std::string GetProduct() = 0;
};
