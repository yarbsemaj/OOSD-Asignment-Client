#pragma once
#include<stdio.h>
#include<winsock2.h>
#include <iostream>
#include <string>
#include "Observer.h"


#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "127.0.0.1"  //ip address of udp server
#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data
class Aircraft;
class ClientNetwork :
	public Observer
{
public:
	~ClientNetwork();
	ClientNetwork();
	void start();
	void update(Aircraft  & aircraft);
	

private:
	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];
	WSADATA wsa;

};

