#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>

// enum fd_type { FD_FREE, FD_LISTENER, FD_CLIENT }; 

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

int err_exit() {
	char *err_msg = "Fatal error\n";
	write(2, err_msg, strlen(err_msg));
	exit(1);
}

int main(int argc, char **argv) {

    if (argc != 2) {
        char *err_msg = "Wrong number of arguments\n";
        write(2, err_msg, strlen(err_msg));
        exit(1);
    }

    int port = atoi(argv[1]);
    //add port error handling?

	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli; 

	// listener socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) {
		err_exit();
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

	// Binding newly created socket to given IP and verification (servaddr contains all the info of our server -> IP, port, etc)
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		err_exit();
	} 
	else
		printf("Socket successfully binded..\n");
	//tell the kernel to start listening for connections (max 10 clients in this case)
	if (listen(sockfd, 10) != 0) {
		err_exit();
	}
	// int *fds = calloc(1, sizeof(int));
	// if (fds == 0) {
	// 	err_exit();
	// }
	// fds[0] = sockfd;
	// int fds_size = 1;
	// enum fd_type *types = calloc(1, sizeof(enum fd_type));
	// if (types == 0) {
	// 	err_exit();
	// }
	// types[0] = FD_LISTENER;
	
	fd_set readfds, writefds;
	FD_SET(sockfd, &readfds);
	int fd_max = sockfd;
	
	while (1) {
		// monitor with select() the created sets of fds
		if (select(fd_max + 1, &readfds, NULL, NULL, NULL) == -1) {
			perror("select");
			exit(1);
		}
		for (int i = 0; i <= fd_max; i++) {		
			// IF LISTENER FD IS READY, THEN ACCEPT A NEW CONNECTION
			if (i == sockfd && FD_ISSET(i, &readfds)) {
				// waits (blocking) for a client to connect and gives a new socket/fd (connfd) to communicate with the client
				// the original socket (sockfd) is still open and can be used to accept new connections
				// the client address (IP and port) is stored in cli
				// the len variable is used to store the size of the client address
				len = sizeof(cli);
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0) { 
					//err_exit();
					printf("server acccept failed...\n");
				} 
				else {
					printf("server acccepted client fd = %d\n", connfd);
					FD_SET(connfd, &readfds);
					//fds_size++;
				}
			}
			// IF CLIENT FD IS READY,
			// TO READ, THEN READ DATA
			else if (i != sockfd && FD_ISSET(i, &readfds)) {
				//read data from the client fd

				//if nbytes == 0, the client has closed the connection
				//if nbytes < 0, an error occurred
				//if arrived at end of request/msg -> set to write FD_SET(connfd, &writefds); FD_CLR(connfd, &readfds);

			}
			// TO WRITE, THEN WRITE DATA
			else if (i != sockfd && FD_ISSET(i, &writefds)) {

			}
		}
		// i++;
		// if (i > fds_size) {
		// 	i = 0;
		// }
	}
}