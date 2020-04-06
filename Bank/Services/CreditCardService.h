#pragma once
#include <string>
#include "../Cards/CreditCard.h"
#include "../Repositories/CardRepo.h"
#include "CardService.h"


class CreditCardService : public CardService
{
private:
	Repo<Card>* cardRepo;
public:

	Card* FindByNumber(std::string number) override;
	void PrintAll() override;
	bool Create(std::string number, int cvv, double balance) override;
	bool Create(std::string number, int cvv, double balance, std::string firstName, std::string lastName) override;
	bool Send(std::string donor, std::string recipient, double amount) override;
	void Save() override;


	CreditCardService(Repo<Card>* repo)
	{
		cardRepo = repo;
	}
};
