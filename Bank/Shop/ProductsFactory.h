#pragma once
#include <map>
#include "Products/Apple.h"
#include "Products/Orange.h"
#include "Products/Product.h"
#include "Products/Strawberry.h"

class ProductsFactory
{
public:
	std::map<std::string, Product*> products;

	ProductsFactory()
	{
		products.emplace("Orange", new Orange());
		products.emplace("Apple", new Apple());
		products.emplace("Strawberry", new Strawberry());
	}

	std::map<std::string, Product*>* GetProducts()
	{
		return &products;
	}

};
