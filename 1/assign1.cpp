// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the minimum element in the array (array is unchanged)
int minimum(int* array, int size){
		int min = array[0];	//sets minimum value to the first value in the array
		for(int i=1; i<size; i++){	//loop to check for minimum value
			if(array[i] < min){
				min = array[i];		//sets new minimum
			}
		}
	return min;	//returns minimum value
}

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the maximum element in the array (array is unchanged)
int maximum(int* array, int size){
		int max = 0;		//sets maximum value to zero
		for(int i=0; i<size; i++){		//loop to check for maximum value
			if(array[i] > max){
				max = array[i];						//sets new maximum
			}
		}
	return max;		//returns maximum value
}

// pre-condition: Pointer to an array of ‘n’ integers
// post-condition: Calculates the average of the elements in the array (array is unchanged)
double average(int* array, int size){
	double avg = 0;		//sets initial average to zero
	int i=0;
	for(; i<size; i++){
		avg+=array[i];	//adds all values in the array
	}
	return avg/i;	//calculates and returns the average value
}
