//FROM: https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work
#include <stdio.h>
#include <stdlib.h>

int addInt(int, int);
//	Let's start with a basic function which we will be pointing to:

int addInt(int n, int m) {
	return n + m;
}

int main() {
	//	First thing, let's define a pointer to a function which receives 2 ints and returns an int:
	int (*functionPtr)(int, int);
	//	Now we can safely point to our function:
	functionPtr = &addInt;
	//	Now that we have a pointer to the function, let's use it:
	int sum = (*functionPtr)(2, 3); // sum == 5
	printf("%d", sum);

}

int add2to3(int (*functionPtr)(int, int)) {
	return (*functionPtr)(2, 3);
}
