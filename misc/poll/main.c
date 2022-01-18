#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#if 0
           struct pollfd {
               int   fd;         /* file descriptor */
               short events;     /* requested events */
               short revents;    /* returned events */
           };


#endif

#define WP "./a"
#define MAX_PFD 3

int main(int argc, char *argv[])
{

	struct pollfd pfd[MAX_PFD];
	nfds_t nfd = 1;
	int timeout = 5000, stat;
	char buf[4092];

	pfd[0].fd = open(WP, O_RDWR);
	if (pfd[0].fd != 0) {
		printf("%s\n", strerror(errno));
		exit(-1);
	}

	pfd[0].events = POLLIN;
	//pfd[0].events = POLLIN | POLLOUT;

	while (stat = poll(&pfd[0], nfd, timeout) >= -1) {
		memset(buf, 0, sizeof(buf));
		if (stat == 0) {
			printf("Time out ...5s\n");
			continue;
		}
		read(pfd[0].fd, buf, sizeof(buf));
		printf("%s\n", buf);
	}

	close(pfd[0].fd);
	return 0;
}
