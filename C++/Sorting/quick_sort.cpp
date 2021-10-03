// program to implement Quick sort

#include<stdio.h>
#define MAX 150

void swap(int *p1, int *p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}

/*
 This function takes last element as pivot, places the pivot element at its correct position in sorted array,
 and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot.
*/
int getPartitionIndex(int arr[], int min, int max)
{
	int j;
	int pivot_ele = arr[max];
	int i = (min - 1);

	for (j=min; j<=max-1;j++)
	{
		if (arr[j] < pivot_ele)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[max]);
	return (i+1);
}

/* The main function that implements QuickSort
min --> Starting index,
max --> Ending index
*/
void quickSort(int arr[], int min, int max)
{
	if (min<max)
	{
		int partition_ind = getPartitionIndex(arr, min, max);
		quickSort(arr, min, partition_ind - 1);
		quickSort(arr, partition_ind + 1, max);
	}
}

// Function to accept array elements
void acceptArray(int arr[], int sz)
{
    int i;
    printf("Enter %d elements\n", sz);
    for(i=0; i<sz; i++)
    {
        scanf("%d", &arr[i]);
    }
}

// Function to print an array
void printArray(int arr[], int sz)
{
	int i;
	for (i=0; i < sz; i++)
    	{
        	printf("%d\n", arr[i]);
    	}
}

int main()
{
	int arr[MAX];
	int sz;

	printf("Enter array size : ");
    scanf("%d", &sz);

    acceptArray(arr, sz);

	quickSort(arr, 0, sz-1);

	printf("Sorted array:\n");
	printArray(arr, sz);

	return 0;
}
