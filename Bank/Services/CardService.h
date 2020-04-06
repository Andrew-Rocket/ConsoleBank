#pragma once
#include <string>

#include "../Cards/Card.h"

class CardService
{
public:
	virtual Card* FindByNumber(std::string number) = 0;
	virtual void PrintAll() = 0;
	virtual bool Create(std::string number, int cvv, double balance) = 0;
	virtual bool Create(std::string number, int cvv, double balance, std::string firstName, std::string lastName) = 0;
	virtual bool Send(std::string donor, std::string recipient, double amount) = 0;
	virtual void Save() = 0;

};
