#pragma once
#include "Product.h"

class Strawberry : public Product
{
public:

	std::string GetProduct() override
	{
		return "Strawberry successfully bought!";
	}

	Strawberry()
	{
		price = 19.99;
	}
};
