	int ciao[3];

	printf("%ld", sizeof(ciao) / sizeof(*ciao)); //size in bytes of the array divided by the size in bytes of the type (pointer to the array, or first array of the element)

