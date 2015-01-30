#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int
main(int argc, char *argv[])
{
  struct hostent *h;
  struct in_addr **addr_list;
  
  if(argc != 2){
    fprintf(stderr,"Usage: getip address\n");
    exit(1);
   }

  if((h=gethostbyname(argv[1])) == NULL){
    herror("gethostbyname");
    exit(1);
  }

   
 
  /*printf("Array size: %d\n", sizeof(*h->h_addr_list));*/
  /* printf("Host name: %s\n", h->h_name); */
  addr_list = (struct in_addr **)h->h_addr_list;
  for(int i=0; addr_list[i] != NULL ;i++){
    printf("IP: %s\n", inet_ntoa(*addr_list[i]));
  }
  
  
  /*printf("IP Address: %s\n", inet_ntoa(*((struct in_addr *)h->h_addr)));*/

  return 0;
}
