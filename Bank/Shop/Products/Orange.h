#pragma once
#include "Product.h"

class Orange : public Product
{
public:

	std::string GetProduct() override
	{
		return "Orange successfully bought!";
	}

	Orange()
	{
		price = 29.99;
	}

};
