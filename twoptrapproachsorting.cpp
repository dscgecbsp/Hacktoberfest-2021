#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {0, 0, 1, 0, 1, 1, 0, 0, 1};
    int i = 0;
    int j = 8;

    int temp;
    while (i < j)
    {
        if (arr[i] < arr[j])
        {
            i++;
            
           
        }
        else if (arr[i] == arr[j])
        {
            if(arr[i]==1){
            temp=arr[j-1];
            arr[j-1]=arr[i];
            arr[i]=temp;
            i++;
            j--;
            }
            if(arr[i]==0){
                temp=arr[i+1];
                arr[i+1]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
            
        }
        else
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j--;
            i++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}