#pragma once
#include <iostream>
#include <ostream>

#include "CreditCard.h"
class NamedCard : public CreditCard
{
private:
	std::string firstName;
	std::string lastName;


public:
	std::string ToString() override;

	std::string GetFirstName() const
	{
		return firstName;
	}

	void SetFirstName(const std::string& firstName)
	{
		this->firstName = firstName;
	}

	std::string GetLastName() const
	{
		return lastName;
	}

	void SetLastName(const std::string& lastName)
	{
		this->lastName = lastName;
	}


	NamedCard(std::string& number, int cvv, double balance, const std::string& first_name,
		const std::string& last_name)
		: CreditCard(number, cvv, balance),
		firstName(first_name),
		lastName(last_name)
	{
	}

};
