#pragma once
#include <string>
#include <vector>

class CommandService
{
public:
	virtual std::vector<std::string> GetCommand() = 0;
	virtual bool CheckCommand(std::vector<std::string> com, int n) = 0;
	virtual void StartCommands() = 0;
	virtual void Help() = 0;
};
