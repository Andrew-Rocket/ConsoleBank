#pragma once
#include "Emv.h"

class Card
{

protected:
	std::string number;
	int cvv = 0;
	double balance = 0;

	Emv* emv;

public:



	virtual std::string GetNumber() const = 0;
	virtual int GetCvv() = 0;
	virtual int GetEmv() = 0;
	virtual void SetCvv(int cvv) = 0;
	virtual double GetBalance() = 0;
	virtual void SetBalance(double balance) = 0;
	virtual std::string ToString() = 0;


	virtual void operator + (Card* card) = 0;
	virtual void operator += (double amount) = 0;
	virtual void operator -= (double amount) = 0;
	virtual bool operator == (Card* card) = 0;
	virtual bool operator < (Card* card) = 0;
	virtual bool operator > (Card* card) = 0;
	virtual bool operator != (Card* card) = 0;
	virtual void operator ++ () = 0;
	virtual void operator -- () = 0;
	virtual void operator[] (int modifer) = 0;
};
