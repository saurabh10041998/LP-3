// TCP client

#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd){
  char buff[MAX];
  int n; 
  for(;;){
    bzero(buff, MAX);
    printf("\x1B[32m [+] Enter  the string: \x1B[0m");
    n = 0;
    while((buff[n++] = getchar()) != '\n');
    write(sockfd, buff, MAX);

    bzero(buff, sizeof(buff));
    read(sockfd, buff, sizeof(buff));
    printf("\x1B[33m[*] From server: %s \n\x1B[0m", buff);

    if(strncmp(buff, "exit", 4) == 0) {
      printf("\x1[1;32m[*] Client exit\n\x1B[0m");
      break;
    }
  }
}

int main() {
  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) {
    printf("\x1B[31m[!!] Socket creation failed...\n\x1B[0m");
    exit(0);
  } 

  printf("\x1B[32m[*] Socket successfully created\n\x1B[0m");
  bzero(&servaddr, sizeof(servaddr));

  // Assign IP,PORT
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  //connect the client socket to server socket
  if(connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0) { 
    printf("\x1B[31m[!!] Connection with server failed\n\x1B[0m");
    exit(0);
  } 

  printf("\x1B[32m[*] Connected to server\n\x1B[0m");

  // function for chat
  func(sockfd);

  // close the socket

  close(sockfd);

  return 0;

}
