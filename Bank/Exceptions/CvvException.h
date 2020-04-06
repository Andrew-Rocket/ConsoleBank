#pragma once
#include <exception>

class CvvException : public std::exception
{
private:
	int cvv;

public:

	CvvException(const char* msg, int cvv) : exception(msg)
	{
		this->cvv = cvv;
	}

	int GetCvv()
	{
		return cvv;
	}

};
