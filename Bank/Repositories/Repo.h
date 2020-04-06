#pragma once
#include <string>
#include <vector>


template <class T>
class Repo
{

public:
	virtual std::vector<T*> GetCards() = 0;
	virtual bool Add(T* element) = 0;
	virtual T* Find(std::string key) = 0;
	virtual void Save() = 0;
	virtual std::vector<T*> Load() = 0;
};
