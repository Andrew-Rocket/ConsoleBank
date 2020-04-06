#pragma once
#include <exception>
#include <string>

class NotNumericStringException : public std::exception
{
private:
	std::string string;

public:

	NotNumericStringException(const char* msg, std::string& string) : exception(msg)
	{
		this->string = string;
	}

	std::string GetString()
	{
		return string;
	}
};
