#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n, int *swaps) {
	int i, j;
	for (i = 0; i < n-1; i++) {
		for (j=0; j < n-i-1; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j],&arr[j+1]);
				(*swaps)++;
			}
		}
	}
}

void printArray(int arr[], int size) {
	int i;
	for (i=0; i < size ; i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void getArraySize(int *count) {
        printf("Enter The size of the array: \n");
        scanf("%d", &count);
	printf("Array Size: %d\n", count);
}

int *getArray(int *count) {
	int *array = malloc(count * sizeof(*array));
	if (!array) {
		printf("Error with malloc");
		exit(EXIT_FAILURE);
	}
	printf("Enter the elements of the array: \n");
	for (int i = 0 ; i < count; i++)
		scanf("%d", &array[i]);
	printf("Entered Array: ");
	printArray(array,count);
	return array;
}

int main() {
	int count;
	int *p_count = count;
	getArraySize(&count);
	printf("Array Size: %d", count);
	int *arr = getArray(&count);
	//int arr[] = {10, 9, 4, 2, 6, 11, 0, 1};
	// Total number of bits divided by bit size of each element = array size
	int n = sizeof(arr)/sizeof(arr[0]);
	int steps = 0;
	int *steps_p = &steps;
	printf("Array Size: %d\n",n);
	printf("Array to Sort: ");
	printArray(arr,n);
	bubbleSort(arr,n,steps_p);
	printf("Sorted Array: ");
	printArray(arr,n);
	printf("Number of Sorts: %d\n",steps);
	return 0;
}
