//This program creates and manages a variable-length array

	 int  length = 1; 																//first length of the array
	 int* out = (int*) malloc(length * sizeof(int));									//allocates as much ram as indicated by the length of the array (b) multiplied by the size on an int in Ram. This is actually a pointer to the ram that as been allocated
	 int* out_copy = out; 															//now creates a pointer to a copy of the other pointer, that acts as a constant copy

	 printf("Starting array length:   %d\n\tNew value in index 0 is:   ", length);
	 out[0] = 32;																	//assign a value to the first element
	 printf("%d\n", out[0]);															//prints the new value

	 length = 2;																		//now it changes the length
	 printf("New array length:    %d\n", length);
	 printf("Creating new array with increased length\n");

	 out = (int*) malloc(length * sizeof(int));										//creates the new array, with the new length
	 out=out_copy;																	//copies the pointer to the old array into the new one

	 printf("Longer array has been created and old array value copied into the new one\nNew values are:\n");

	 out[1] = 33;																	//adds a variable into the new index that has been created when increasing lenght
	 printf("\t%d\n", out[0]);															//prints the value in the first index (it is still the value instantiated before)
	 printf("\t%d\n", out[1]);															//prints the new value: the array length as increased

	 free(out_copy);
