#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h> // for sockaddr_in struct
#include <sys/socket.h>
#include <unistd.h> // for close
#include <dirent.h> // for opendir, closedir
#include <errno.h>
#include <string.h> // for memset
#include <arpa/inet.h> // for inet_addr
#include <sys/types.h>

#define MAX_CLIENTS 10
#define PORT 5005

struct sockaddr_in set_socket_addr(uint32_t inaddr, short sin_port) {
    struct sockaddr_in addr;
    memset((void*) &addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(inaddr);
    addr.sin_port = htons(sin_port);

    return addr;
}

void server_process(int sockfd) {
    printf("Server: got connection\n");
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in server_addr = set_socket_addr(INADDR_ANY, PORT);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("SOCKET ERROR");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("BIND ERROR");
        exit(1);
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("LISTEN ERROR");
        exit(1);
    }

    for (;;) {
        // Accept a connection
        if ((connfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len)) < 0) {
            perror("ACCEPT ERROR");
            exit(1);
        }

        // Read from the socket
        if (fork() == 0) {
            close(sockfd);
            server_process(connfd);
            exit(0);
        }

        close(connfd);
    }
}