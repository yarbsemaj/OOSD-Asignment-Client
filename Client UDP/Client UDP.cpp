/*
Simple udp client
*/

#include <iostream>
#include "ClientNetwork.h"


int main(void)
{
	std::string name;
	std::string reg;

	std::cin >> name >> reg;



	ClientNetwork server(name,reg);

	server.start();
	

	return 0;
}