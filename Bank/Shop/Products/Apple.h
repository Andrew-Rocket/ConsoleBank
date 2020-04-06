#pragma once
#include "Product.h"

class Apple : public Product
{
public:
	std::string GetProduct() override
	{
		return "Apple bought!";
	}

	Apple()
	{
		price = 49.99;
	}
};
