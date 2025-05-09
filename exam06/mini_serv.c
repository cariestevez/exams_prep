#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
// ---------------------------------------------------------------------------
#include <sys/select.h>

fd_set read_fds, write_fds, active_fds;;

int max_fd = 0;
int fd_to_id[1025];// client = connection = fd, id = count. 1st client = 0, 2nd = 1, etc
int id = 0; // as many as possible open fds

char *write_buffer[100];
char *read_buffer[100];
char *message_buffer[1025];
// ---------------------------------------------------------------------------


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

// --- custom functions: -----------------------------------------------------

void fatal_error() {
	write(2, "Fatal error\n", 12);
	exit(1);
}

void forward_message(int fd, char *message) {
	for (int client = 0; client <= max_fd; client++) {
		if (client != fd && FD_ISSET(client, &write_fds)) {
			send(client, message, strlen(message), 0);
		}
	}
}

void handle_new_client(int fd) {
	FD_SET(fd, &active_fds);
	fd_to_id[fd] = id++;
	sprintf(write_buffer, "server: client %d just arrived\n", fd_to_id[fd]);
	forward_message(fd, write_buffer);
	if (fd > max_fd) {
		max_fd = fd;
	}
}

// add logic to remove client (fd from active fds clearing set, fd_to_id?, close fd, free message buffer) & notify other clients
void remove_client(int fd) {
	FD_CLR(fd, &active_fds);
	close(fd);
	sprintf(write_buffer, "server: client %d just left\n", fd_to_id[fd]);
	forward_message(fd, write_buffer);
	fd_to_id[fd] = -1;
	free(message_buffer[fd]);
	message_buffer[fd] = NULL;
	if(fd == max_fd) {
		while (max_fd > 0 && fd_to_id[max_fd] == -1) {
			max_fd--;
		}
	}
}

void send_message(int fd) {
	char *message = NULL;
	while (extract_message(&message_buffer[fd], &message)) {
		sprintf(write_buffer, "client %d: ", fd_to_id[fd]);
		forward_message(fd, write_buffer);
		forward_message(fd, message);
		free(message);
	}

}

// ---------------------------------------------------------------------------

int main(int argc, char **argv) {

	// --- input error handling ---
	if (argc != 2) {
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	int port = atoi(argv[1]);//add port error handling?

	// --- initialize sets of fds for select() ---
	FD_ZERO(&active_fds);
	FD_ZERO(&read_fds);
	FD_ZERO(&write_fds);
	// --- 1. create the listener socket ---
	int listener_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (listener_fd < 0)
		fatal_error();
	max_fd = listener_fd;
	// --- add to corresponding set ---
	FD_SET(listener_fd, &active_fds);
	// ---------------------------------------------- //

	// int sockfd, connfd, len;
	
	// // socket create and verification 
	// sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	// if (sockfd == -1) { 
		// 	printf("socket creation failed...\n"); 
		// 	exit(0); 
		// } 
		// else
		// 	printf("Socket successfully created..\n"); 
	struct sockaddr_in servaddr; // struct to hold server's address (IP and port)
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 

	// Binding newly created socket to given IP and verification 
	if ((bind(listener_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		// printf("socket bind failed...\n"); 
		// exit(0);
		fatal_error();
	} 
	// else
	// 	printf("Socket successfully binded..\n");
	if (listen(listener_fd, 10) != 0) { //specify max number of clients waiting to connect (queue). Linux caps to 128
		// printf("cannot listen\n"); 
		// exit(0);
		fatal_error();
	}

	// len = sizeof(cli);
	// connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
	// if (connfd < 0) { 
    //     printf("server acccept failed...\n"); 
    //     exit(0); 
    // } 
    // else
    //     printf("server acccept the client...\n");

	// --- main loop ---
	while (1) {

		read_fds = write_fds = active_fds;
		// --- 2. monitor the sets of fds with select() ---
		if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0) { //needs to be called before accept(), otherwise the listener socked would block in accept()
			fatal_error();
		}
		// --- 3. loop through all the fds to check if they're ready ---
		for (int i = 0; i <= max_fd; i++) {
			if(!(FD_ISSET(i, &read_fds))) { // if fd isn't ready to be read(=receive) without blocking, move to next fd
				continue;
			}
			// new client connection
			if (i == listener_fd) {
				int new_client_fd = accept(listener_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
				if (new_client_fd >= 0) {
					handle_new_client(new_client_fd);
					break;
				}
			}
			//client fd ready to be read
			else {
				int read_bytes = recv(i, read_buffer, sizeof(read_buffer), 0);
				if (read_bytes <= 0) { // probable disconnection
					remove_client(i);
					break;
				}
				read_buffer[read_bytes] = '\0'; //null terminate buffer string
				message_buffer[i] = str_join(message_buffer[i], read_buffer); // append newly received message to potential preexisting messages
				//add logic to check if \n is present and send all full lines to other clients keeping only the rest in the message buffer
				send_message(i);;
			}
		}
	}
	return (0);
}
