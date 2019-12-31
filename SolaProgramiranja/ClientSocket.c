#include <stdio.h>
#include <winsock.h>
#include "HttpHelpers.h"
#define PORT 80
#define USERAGENT "ApOgEE MinGW Socket Client 1.0"

int main1(int argc, char *argv[])
{
	int client_socket;
	const char *host;
	struct hostent *hent;
	int iplen = 15; //XXX.XXX.XXX.XXX
	struct sockaddr_in *remote;
	int tmpres;
	char *get;
	char buf[BUFSIZ+1];

	printf("Socket client example\n");
	
	// create tcp socket
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	// ARGUMENTS
	// 1) PF protocol family (hot to interpret internet address if specified)
	// 2) TYPE type of communication desired (SOCK_STREAM = reliable stream delivery service
	// 3) select specific protocol
	// RETURNS  descriptot integert
	// * also possible for unix pipes to create both pairs at once socketpair function
	
	client_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (client_socket < 0) {
		printf("client_socket = %d\n",client_socket);
		perror("Can't create TCP socket\n");
		exit(1);
	}  	
	
	// get host ip
	host = (char *)"www.ultratone.com.my";
	printf("Host: %s\n",host);
	char *ip = (char *)malloc(iplen+1);
	memset(ip, 0, iplen+1);
	if((hent = gethostbyname(host)) == NULL)
	{
		perror("Can't get IP");
		exit(1);
	}
	ip = inet_ntoa(*(struct in_addr *)*hent->h_addr_list);
	printf("The IP: %s\n",ip);
	
	// setup remote socket
	remote = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in *));
	remote->sin_family = AF_INET;
	printf("s_addr:%ld\n",remote->sin_addr.s_addr);
	remote->sin_addr.s_addr = inet_addr(ip);
	remote->sin_port = htons(PORT);
	printf("s_addr:%ld\n",remote->sin_addr.s_addr);
	
	// have to read 
	// http://msdn.microsoft.com/en-us/library/windows/desktop/ms737625(v=vs.85).aspx
	
	// connect socket
	if(connect(client_socket, (struct sockaddr *)remote, sizeof(struct sockaddr)) == SOCKET_ERROR){
		closesocket(client_socket);
		perror("Could not connect");
		WSACleanup();
		exit(1);
	}
	
	// prepare query
	get = build_get_query(host, (char *)"/");
	printf("query: \n%s\n", get);

	//Send the query to the server
	int sent = 0;
	while(sent < strlen(get)) { 
		tmpres = send(client_socket, get+sent, strlen(get)-sent, 0);
		if(tmpres == -1) {
			perror("Can't send query");
			exit(1);
		}
		sent += tmpres;
	}

	//now it is time to receive the page
	memset(buf, 0, sizeof(buf));
	int htmlstart = 0;
	char * htmlcontent;
	while((tmpres = recv(client_socket, buf, BUFSIZ, 0)) > 0) {
		if(htmlstart == 0) {
			/* Under certain conditions this will not work.
			 * If the \r\n\r\n part is splitted into two messages
			 * it will fail to detect the beginning of HTML content
			 */
			htmlcontent = strstr(buf, "\r\n\r\n");
			if(htmlcontent != NULL){
				htmlstart = 1;
				htmlcontent += 4;
			}
		} else {
			htmlcontent = buf;
		}
		if(htmlstart) {
			fprintf(stdout, htmlcontent);
		}

		memset(buf, 0, tmpres);
	}
	if(tmpres < 0) {
		perror("Error receiving data");
	}
	
	free(get);
	free(remote);
	closesocket(client_socket); // close with descriptor (so the system knows, youre not using socekt anymore)
	WSACleanup();
	
	printf("Program end");
	
	return 0;
}

char *build_get_query(const char *host, char *page)
{
	char *query;
	char *getpage = page;
	char *tpl = (char *)"GET /%s HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n";
	if(getpage[0] == '/'){
		getpage = getpage + 1;
		fprintf(stderr,"Removing leading \"/\", converting %s to %s\n", page, getpage);
	}
	// -5 is to consider the %s %s %s in tpl and the ending \0
	query = (char *)malloc(strlen(host)+strlen(getpage)+strlen(USERAGENT)+strlen(tpl)-5);
	sprintf(query, tpl, getpage, host, USERAGENT);
	return query;
}
