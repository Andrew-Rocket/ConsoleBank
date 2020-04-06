#pragma once
#include <algorithm>
#include <string>

class Utils
{
public:
	static bool NumericString(std::string& str)
	{
		return std::all_of(std::begin(str), std::end(str), [](auto ch) { return isdigit(ch); });
	}

	template <class T>
	static void Swap(T& x, T& y)
	{
		T temp = x;
		x = y;
		y = temp;
	}
};
