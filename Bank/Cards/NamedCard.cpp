#include "NamedCard.h"

#include <iostream>

std::string NamedCard::ToString()
{

	return this->GetNumber()
		+ "\t" + std::to_string(this->GetCvv())
		+ "\t" + std::to_string(this->GetBalance())
		+ "\t" + this->GetFirstName()
		+ "\t" + this->GetLastName();


}
