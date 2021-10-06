#include <stdio.h>
int main()
{
    int n, temp;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of array:\n");
     for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    //-----------Applying the condition of BUBBLE SORT---------------
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)//Here after one pass last box will be occupied with the largest number, BECAUSE of which the length of array will be considered as ( n-1 ).Similarly,loops will go on till sorting is done.
      {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nElements of array after binary sort are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}