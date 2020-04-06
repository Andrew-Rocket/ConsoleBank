#include "CreditCard.h"

#include <iostream>



std::string CreditCard::GetNumber() const
{
	return number;
}

int CreditCard::GetCvv()
{
	return cvv;
}

void CreditCard::SetCvv(int cvv)
{
	this->cvv = cvv;
}

double CreditCard::GetBalance()
{
	return balance;
}

void CreditCard::SetBalance(double balance)
{
	this->balance = balance;
}


std::string CreditCard::ToString()
{
	return this->GetNumber() + "\t" + std::to_string(this->GetCvv()) + "\t" + std::to_string(this->GetBalance());
}

int CreditCard::GetEmv()
{
	return emv->GetCode();
}

void CreditCard::operator+(Card* card)
{
	this->balance + card->GetBalance();
	card->SetBalance(0);
}


void CreditCard::operator+=(double amount)
{
	this->balance += amount;
}

void CreditCard::operator-=(double amount)
{
	this->balance -= amount;
}


bool CreditCard::operator==(Card* card)
{
	if (this->balance == card->GetBalance())
	{
		return true;
	};
	return false;
}

bool CreditCard::operator<(Card* card)
{
	if (this->balance < card->GetBalance())
	{
		return true;
	};
	return false;
}

bool CreditCard::operator>(Card* card)
{
	if (this->balance > card->GetBalance())
	{
		return true;
	};
	return false;
}

bool CreditCard::operator!=(Card* card)
{
	if (this->balance != card->GetBalance())
	{
		return true;
	};
	return false;
}


void CreditCard::operator++()
{
	this->balance += 1000;
}

void CreditCard::operator--()
{
	this->balance -= 1000;
}


void CreditCard::operator[](int modifer)
{
	this->balance *= modifer;
}
