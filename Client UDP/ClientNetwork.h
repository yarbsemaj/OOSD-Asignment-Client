#pragma once

#include <string>
class ClientNetwork
{
public:
	~ClientNetwork();
	ClientNetwork(std::string name, std::string reg);
	void start();

private:
	std::string name;
	std::string reg;

};

