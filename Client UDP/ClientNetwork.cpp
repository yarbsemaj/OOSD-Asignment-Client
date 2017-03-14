#include "ClientNetwork.h"
#include "NetworkData.h"
#include "Aircraft.h"
#include<iostream>


ClientNetwork::ClientNetwork()
{
}


void ClientNetwork::start()
{
	s, slen = sizeof(si_other);

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


}

void ClientNetwork::update(Aircraft & aircraft)
{
		Aircraft aircraftObj = aircraft;
		const unsigned int packet_size = sizeof(Packet);
		char packet_data[packet_size];
		Packet packet;
		packet.speed = aircraftObj.speed.getValue();
		packet.longitude = aircraftObj.longitude.getValue();
		packet.latitude = aircraftObj.latitude.getValue();
		packet.packet_type = DATA_EVENT;
		memmove(packet.regNum,aircraftObj.registration, sizeof(aircraftObj.registration));
		packet.altitude = aircraftObj.altitude.getValue();
		packet.presure = aircraftObj.presure.getValue();
		packet.serialize(packet_data);

		//std::cout << packet.regNum;

		//send the message
		if (sendto(s, packet_data, packet_size, 0, (struct sockaddr *) &si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d", WSAGetLastError());
			exit(EXIT_FAILURE);
		}

}




ClientNetwork::~ClientNetwork()
{
	//closesocket(s);
	//WSACleanup();
}
