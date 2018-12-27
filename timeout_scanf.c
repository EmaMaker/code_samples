#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	int value = 0;
	struct timeval tmo;
	fd_set readfds;

	printf("Enter a non-zero number: ");
	fflush(stdout);

	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	tmo.tv_sec = 3;
	tmo.tv_usec = 0;

	if (select(1, &readfds, NULL, NULL, &tmo) == 0) {
		printf("User dont give input");
		//return (1);
	} else {
		scanf("%d", &value);
		if (value != 0) {
			printf("User input a number");
		} else {
			printf("User dont give input2");
		}
	}

	printf("boh");

	return (0);
}
