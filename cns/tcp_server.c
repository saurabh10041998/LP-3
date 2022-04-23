// TCP server

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

// function designed for chat between client and server

void func(int connfd){
  char buff[MAX];
  int n;
  // infinite loop for chat
  
  for(;;){
      bzero(buff, MAX);
      
      // read the message from client and copy it in buffer
      fread(connfd, buff, MAX);
      //print the buffer which contains the client contents
      
      printf("\x1B[32m[*] From client --> %s\n\x1B[0m", buff);

      bzero(buff, MAX);
      n = 0;
      printf("\x1B[33m[+] To client: \x1B[0m");
      //copy server message in the buffer
      while(buff[n++] = getchar() != '\n');

      //send that buffer to the client
      fwrite(connfd, buff, sizeof(buff));

      // if msg contains "Exit" then server exit and chat ended
      if(strncmp("exit", buff, 4) == 0){
        printf("\x1B[1;32m[*] Server exit \n\x1B[0m");
        break;
      }

  }
}

// Driver function

int main() { 
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;

  //socket create and verification
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1) {
    printf("\x1B[31m[!!] Socket creation failed..\n\x1B[0m");
    exit(0);
  }
  printf("\x1B[32m[*] Socket created successfully\n\x1B[0m");

  bzero(&servaddr, sizeof(servaddr));

  //assign ip and port
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  //Binding newly created socket to given IP and verification
  if((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0) {
    printf("\x1B[31m[!!] Socket bind failed\n\x1B[0m");
    exit(0);
  }

  if((listen(sockfd, 5)) != 0) {
    printf("\x1B[31m[!!] Listen failed\n\x1B[0m");
    exit(0);
  }

  printf("\x1B[34m[*] Server is listening\n\x1B[0m");
  
  len = sizeof(cli);

  //Accept the data packet from the client and verfication
  
  connfd = accept(sockfd, (SA *)&cli, &len);
  if(connfd < 0) {
    printf("\x1B[31m[!!] Server accept failed\x1B[
  }


}
