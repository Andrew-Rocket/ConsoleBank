#include <iostream>
#include "CreditCardService.h"
#include "../Cards/CreditCard.h"
#include "../Cards/NamedCard.h"
#include "../Repositories/CardRepo.h"


//Finding card by number
Card* CreditCardService::FindByNumber(std::string number)
{
	return cardRepo->Find(number);
}

//Printing all cards
void CreditCardService::PrintAll()
{
	auto cards = cardRepo->GetCards();

	for (auto card : cards)
	{
		std::cout << card->ToString() << std::endl;
	}
}


//Creating new card
bool CreditCardService::Create(std::string number, int cvv, double balance)
{
	return cardRepo->Add(new CreditCard(number, cvv, balance));
}


bool CreditCardService::Create(std::string number, int cvv, double balance, std::string firstName, std::string lastName)
{
	return cardRepo->Add(new NamedCard(number, cvv, balance, firstName, lastName));
}


//Send money from card to card
bool CreditCardService::Send(std::string donor, std::string recipient, double amount)
{
	if (auto donor_ = FindByNumber(donor))
	{
		if (auto recipient_ = FindByNumber(recipient))
		{
			if (donor_->GetBalance() >= amount)
			{
				donor_->SetBalance(donor_->GetBalance() - amount);
				recipient_->SetBalance(recipient_->GetBalance() + amount);
				return true;
			}
		}
	}
	return false;
}

void CreditCardService::Save()
{
	cardRepo->Save();
}
