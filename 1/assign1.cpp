
int minimum(int* array, int size){
		int min = array[0];
		for(int i=1; i<size; i++){
			if(array[i] < min){
				min = array[i];
			}
		}
	return min;
}

int maximum(int* array, int size){
		int max = 0;
		for(int i=0; i<size; i++){
			if(array[i] > max){
				max = array[i];
			}
		}
	return max;
}

double average(int* array, int size){
	double avg = 0;
	int i=0;
	for(; i<size; i++){
		avg+=array[i];
	}
	return avg/i;
}
