#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdlib.h>

int
main()
{
  int sockfd, sock_client, sizefd;
  int conn, return_bind, return_listen;
  struct sockaddr_in server, client;

  sockfd = socket(PF_INET,SOCK_STREAM,0);

  memset(&server,0,sizeof server);

  server.sin_family = PF_INET; /* Protocol Family Internet */
  server.sin_port = htons(80); /* Set destination port. Using htons, which is "host to network short" */
  server.sin_addr.s_addr = inet_addr("192.168.204.130"); /* Use inet_addr, that change a string ip in decimal format */
  
  return_bind = bind(sockfd, (struct sockaddr*)&server, sizeof(server));
  
  sizefd = sizeof(server);

  if(return_bind == -1){
    perror("Error bind()...");
  }
  
  /* Well, this method has a function which listen an IP to received connections. Your second parameter is the listen BACKLOG.
   * BACKLOG is the parameter to specify how many waiting connections can be hold on QUEUE. When QUEUE is overflowed, the Kernel by default
   * drop new connections. */ 
  return_listen = listen(sockfd, 5);

  if(return_listen == -1){
    perror("Error listen()...");
  }

  /* Accept function */
  sock_client = accept(sockfd, (struct sockaddr*)&client, &sizefd); 

  if(sock_client == -1){
    perror("Accept() error...");
  }else{
    printf("Cliente conectou...\n");
  }



} 

  
