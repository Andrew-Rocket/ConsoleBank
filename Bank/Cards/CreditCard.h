#pragma once
#include <algorithm>
#include <string>
#include "../Utils.h"
#include "../Exceptions/CvvException.h"
#include "../Exceptions/NotNumericStringException.h"
#include "Card.h"


class CreditCard : public Card
{

public:

	std::string GetNumber() const;
	int GetCvv();
	int GetEmv();
	void SetCvv(int cvv);
	double GetBalance();
	void SetBalance(double balance);
	virtual std::string ToString();

	CreditCard(std::string& number, int cvv, double balance)
	{
		//Checking whether cvv is 3-digit number
		if (cvv < 100 || cvv > 999)
		{
			throw CvvException("Cvv must be a 3-digit number", cvv);
		}

		//Checking whether string "number" is numeric
		if (!Utils::NumericString(number))
		{
			throw NotNumericStringException("Number must be numeric", number);
		}
		Card::number = number;
		Card::cvv = cvv;
		Card::balance = balance;
		emv = new Emv(cvv);
	}

	CreditCard();

	void operator + (Card* card) override;
	void operator += (double amount) override;
	void operator -= (double amount) override;
	bool operator == (Card* card) override;
	bool operator < (Card* card) override;
	bool operator > (Card* card) override;
	bool operator != (Card* card) override;
	void operator ++ () override;
	void operator -- () override;
	void operator [] (int modifer) override;
};
