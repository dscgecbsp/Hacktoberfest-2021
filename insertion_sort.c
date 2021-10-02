// C program for insertion sort
#include <math.h>
#include <stdio.h>

// Function to sort an array using insertion sort
void insertion_sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) /*loops from 2nd array element(arr[1]) 
								to last array element(arr[n-1]) to compare arr[i-1] & arr[i].
								If arr[i-1] > arr[i], then swap them*/
    {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A function to print the sorted array of size n
void print_array(int arr[], int n)
{
	int i;
    printf("Array after sorting\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

//main function
int main()
{
	int n,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);//To take input the length of array from the user
	int arr[n];
    printf("Enter the array elements\n");
    //for loop to take input into the array
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

	insertion_sort(arr, n);//calling the insertion_sort() function with arguments arr and n(here the array is passed as address)
	print_array(arr, n);//calling the print_array() function to print the array after sorting

	return 0;
}
