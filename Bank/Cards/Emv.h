#pragma once
#include <string>

class Emv
{
	int salt = 512; //Config
	int code;
	std::string* number;

public:
	int GetCode()
	{
		return code;
	}

	Emv(int& cvv)
	{
		code = cvv * salt;
	}
};
