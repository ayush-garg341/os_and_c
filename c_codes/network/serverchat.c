#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<libsocket/libinetsocket.h>


int main(int argc, char *argv[]){
    char hostname[100];
    sprintf(hostname, "%s.cs.sierracollege.edu", argv[1]);
    // open connection to given server, port 2346
    int fd = create_inet_stream_socket(hostname, "2346", LIBSOCKET_IPv4, 0);

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



// Download and build libsocket
// git clone git@github.com:dermesser/libsocket.git
// cd libsocket
// cmake CMakeLists.txt
// make
//
// Install libsocket
// sudo make install
// sudo ldconfig
// cd ~
// #include<libsocket/libinetsocket.h>
// gcc prog.c -l socket
//
// Futher enhancement
// 1, Measure round trip time taken by -> time to send data to a remote server and receive a response.
