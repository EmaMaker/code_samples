// this code works on linux 

#include <stdio.h>
#include <stdlib.h>

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	//Value to be read
	int value = 0;
	
	//Init the counter
	struct timeval tmo;
	fd_set readfds;

	//Debug message
	printf("Enter a non-zero number: ");
	
	fflush(stdout);

	FD_ZERO(&readfds);
	FD_SET(0, &readfds);
	//Set max. time
	tmo.tv_sec = 3;	//seconds
	tmo.tv_usec = 0; //microseconds

	if (select(1, &readfds, NULL, NULL, &tmo) == 0) {
		//What happens if user didn't give input
		printf("User dont give input");
		//return (1);
	} else {
		//Examine given input
		scanf("%d", &value);
		if (value != 0) {
			printf("User input a number");
		} else {
			printf("User dont give input2");
		}
	}

	//Goes one
	printf("boh");

	return (0);
}
