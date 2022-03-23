#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

const int portnum = 1234;


void do_yo(int sock);

int main(int argc, char* argv[]){
    // Create a socket
    int sockfd, newsockfd;

    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd<0){
        printf("Can't open socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portnum);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind to socket
    int res = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (res < 0){
        /*printf("Can't open socket\n");*/
        perror("Can't open socket.");
        exit(1);
    }

    // Listen for connection
    // Max Upto 5 connections and if one connection is reading fd then other 4 in queue
    listen(sockfd, 5);

    // Accept connection
    int clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t *)&clilen);


    // Hand off to function
    do_yo(newsockfd);

    close(newsockfd);
    close(sockfd);

    return 0;
}


void do_yo(int sock){
    const int NOT_AUTH = 0;
    char buff[1000];
    /*strcpy(buff, "Got it\n");*/
    /*send(sock, buff, strlen(buff), 0);*/

    // Send greeting
    strcpy(buff, "250 yo, hello\n");
    send(sock, buff, strlen(buff), 0);

    int state = NOT_AUTH;
    while(1){
        // Wait for input from the user
        recv(sock, buff, 1000, 0);

        if (!(strncmp("NOYO", buff, 4))){
            close(sock);
            return ;
        }
        else if(!(strncmp("MEIS", buff, 4))){
            char username[995];
            sscanf(buff + 5, "%s ", username);
            printf("Username is %s\n", username);

            // Send back confirmation.
            strcpy(buff, "200, Logged in\n");
            send(sock, buff, strlen(buff), 0);
        }
    }
}


// netstat -an | grep LIST -> list open ports
// ps aux -> list processes
