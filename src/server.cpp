/*
 * server.cpp
 *
 *  Created on: Feb 23, 2019
 *      Author: hasan
 */




/*
	C socket server example
*/

#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write

#include <fstream>
#include <iostream>
#include <exception>

using namespace std;


int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[2000];

	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");

	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");

	//Listen
	listen(socket_desc , 3);

	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);

	//accept connection from an incoming client

 	while(1) {
		client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
		if (client_sock < 0)
		{
			perror("accept failed");
			return 1;
		}
		puts("Connection accepted");

		//Receive a message from client


		const int BUFF_SIZE = 512;
		char buffer[BUFF_SIZE];
		int length;



		try {
			ifstream file("/home/hasan/test.txt", ios::binary);
			while(file.eof() == false) {
				file.read(buffer, 1);
				if(file) {
					write(client_sock , buffer , 1);
				}

			}

		}
		catch (const exception& e) {
			cout << "Error: e.what()" << endl;
		}
 	}

	return 0;
}
