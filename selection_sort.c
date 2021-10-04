
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i,j;

    printf("Enter number of elements you want to store: ");
    scanf("%d" ,&n);

    int B[n];

    //getting inputs to the array from user
    for(i=0 ;i<n ;i++){
        printf("Enter number%d: ",i+1);
        scanf("%d" ,&B[i]);
    }

    //displaying unsorted array
    for(i=0 ;i<n ;i++){
      printf("%d \t" ,B[i]);
    }

    printf("\n");
    //array we have entered
    //B[] = {7,4,10,8,3,1};

    for(i=0; i<n-1; i++){      //number of passes
      int minIndex = i;     //we assume the minimum value is in the starting index of unsorted sub array
        for(j=i+1; j<n ; j++){   // j=i+1 as comparison is beginning with the next nearby item to the starting index
            if(B[j]<B[minIndex]){  //then we checking if there is any value smaller than starting index value
                //if so we are assigning that index as the minIndex
                minIndex = j;
            }
        }
       //after all the comparisons within the first pass we are checking is our minIndex is equal to starting index
       if(minIndex !=i ){
         //swap the starting value index with the newly found minValue
         int temp;
         temp = B[i];
         B[i] = B[minIndex];
         B[minIndex] = temp;
       }
    }

    printf("\n");

    //displaying the sorted array
    for(i=0 ;i<n ;i++){
      printf("%d \t" ,B[i]);
    }


    return 0;
}
