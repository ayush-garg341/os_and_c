#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"libsocket/headers/libinetsocket.h"


int main(){
    // open connection to fremont server, port 2346
    int fd = create_inet_stream_socket("fremont.cs.sierracollege.edu", "2346", LIBSOCKET_IPv4, 0);

    // check if fd is valid
    if(fd < 0){
        fprintf(stderr, "Can not open connection to server: ");
        perror(NULL);
        exit(1);
    }

    // convert file descriptor to FILE*

    FILE *sock = fdopen(fd, "r+");

    char response[100];

    // send HELO command
    fprintf(sock, "HELO\n");

    // receive response
    fgets(response, 100, sock);
    printf("Recieved response is: %s\n", response);

    // send DATE command
    fprintf(sock, "DATE\n");

    // receive response
    fgets(response, 100, sock);
    printf("Recieved response is: %s\n", response);


    // send HELO command
    fprintf(sock, "QUIT\n");

    fclose(sock);
    close(fd);

    return 0;
}
