#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

int
main()
{
  int sockfd, size_server;
  int conn;
  struct sockaddr_in server;

  sockfd = socket(PF_INET,SOCK_STREAM,0);

  memset(&server,0,sizeof server);

  server.sin_family = PF_INET; /* Protocol Family Internet */
  server.sin_port = htons(80); /* Set destination port. Using htons, which is "host to network short" */
  server.sin_addr.s_addr = inet_addr("200.147.67.142"); /* Use inet_addr, that change a string ip in decimal format */
  
  size_server = sizeof(server);

  conn = connect(sockfd, (struct sockaddr *) &server, size_server);
} 

  
