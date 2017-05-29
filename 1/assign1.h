struct array{
	int* array1;
	int size;
	int min;
	int max;
	double avg;
};

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the minimum element in the array (array is unchanged)
int minimum(int* array, int size);




// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the maximum element in the array (array is unchanged)
int maximum(int* array, int size);




// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the average of the elements in the array (array is unchanged)
double average(int* array, int size);
