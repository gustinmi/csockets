#include <stdio.h>//compile: gcc TCPClient_windows.c -o TCPClient_windows.exe -lws2_32
#include <winsock.h> //Warning: This program does not perform any error handling.

int main(int argc, char *argv[])  {
  
	int client;
	struct sockaddr_in address;
	WSADATA wsaData; // WinSocket Data
	char data;

	WSAStartup(MAKEWORD(2, 0), &wsaData); //Initialize WinSock
    client = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //Allocate TCP Socket

    memset(&address, 0, sizeof(address)); //clear socket address
    address.sin_family      = AF_INET;  //IPv4 address
    address.sin_addr.s_addr = inet_addr("127.0.0.1");//set to (loopback) IP address
    address.sin_port        = htons(9020); //make port in network byte order

	printf("Connecting to %lu \n", address.sin_addr.s_addr);
	
    if(connect(client, (struct sockaddr *)&address, sizeof(address))  == SOCKET_ERROR){ //(*@\clientBox{1+2)}@*)
		closesocket(client);
		fprintf(stderr, "Error while connecting");
		WSACleanup();
		exit(1);
	}
    data = 2;
    send(client, &data, 1, 0);  //(*@\clientBox{3)}@*) send 1 byte of data to client, flags=0

    closesocket(client);  //(*@\clientBox{4)}@*)
    WSACleanup();  //Finalize WinSock
    return 0;
}
