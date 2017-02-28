#include "ClientNetwork.h"
#include<stdio.h>
#include<winsock2.h>
#include <iostream>
#include "NetworkData.h"


#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data


ClientNetwork::ClientNetwork(std:: string name, std::string reg)
{
	this->name = name;
	this->reg = reg;

	std::cout << name<< reg;
}


void ClientNetwork::start()
{
	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
	printf("Initialised.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//setup address structure
	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);

	//start communication
	while (1)
	{
		const unsigned int packet_size = sizeof(Packet);
		char packet_data[packet_size];
		Packet packet;
		packet.speed = 22.2;
		packet.longitude = 123455;
		packet.latitude = 2334543;
		packet.packet_type = DATA_EVENT;
		packet.regNum = reg;
		packet.name = name;
		packet.altitude = 10;
		packet.presure = 10;
		packet.serialize(packet_data);

		//send the message
		if (sendto(s, packet_data, packet_size, 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		memset(buf, '\0', BUFLEN);
		//try to receive some data, this is a blocking call
		if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		{
			printf("recvfrom() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

		puts(buf);
		Sleep(1000);
	}

	closesocket(s);
	WSACleanup();
}


ClientNetwork::~ClientNetwork()
{
}
