// Program to implement Selection Sort

#include<stdio.h>
#define MAX 100

int main()
{
    int arr[MAX];
    int i,j,size,temp;

    printf("Enter size of array : ");
    scanf("%d",&size);

    printf("Enter %d elements\n", size);
	for(i=0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}

	//logic for selection sort
	for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    //printing after sorting array
    printf("\nAfter applying selection sort, sorted elements are : \n");
    for(i=0;i<size;i++)
    {
        printf("%d\n",arr[i]);
    }
}
