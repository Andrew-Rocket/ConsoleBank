#pragma once
#include <vector>
#include "../Cards/CreditCard.h"
#include "Repo.h"


class CardRepo : public Repo<Card>
{
private:
	std::vector<Card*> elements = Load();

public:

	CardRepo() {};

	std::vector<Card*> GetCards() override;

	bool Add(Card* card) override;

	Card* Find(std::string number) override;

	void Save() override;

	std::vector<Card*> Load() override;

};
