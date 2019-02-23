/*
 * client.cpp
 *
 *  Created on: Feb 23, 2019
 *      Author: hasan
 */




/*
	C ECHO client example using sockets
*/
#include<stdio.h>	//printf
#include<string.h>	//strlen
#include<sys/socket.h>	//socket
#include<arpa/inet.h>	//inet_addr
#include <unistd.h>

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[1000] , server_reply[2000];

	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}

	puts("Connected\n");

	//keep communicating with server
	int ret;
	while(1)
	{
		//printf("Enter message : ");
		scanf("%s" , message);

		//Send some data


		if( (ret=recv(sock , server_reply , sizeof(server_reply)-1 , 0)) < 0)
		{
			puts("recv failed");
			break;
		}

		server_reply[ret+1] = 0;
		//puts("Server reply :");
		puts(server_reply);
	}

	close(sock);
	return 0;
}
