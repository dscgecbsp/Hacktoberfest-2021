
/*
Binary Search is a searching technique for finding element in a sorted array .The idea is to repeatedly divide the search interval in half.
In this technique with the help of just one comparison we ignore the half of the elements.
The comparison we use is to compare the target element(x) with the mid element(mid) of given array arr.
1]Firstly,we begin with the middle element of the whole array as a search key.
2]if x ==arr[mid] return mid
3]else if x>arr[mid] this implies that element is in the right half subarray after the mid element.
4]else the element might be in the left half subarray before mid element.
5]If element not found return -1;

Time Complexity:O(log(n))
Space Complexity:O(1)
*/
//Java Implementation of Iterative and Recursive Binary Search

public class BinarySearch {

        // Java implementation of recursive Binary Search
        static int binarySearchRecursive(int arr[], int low, int high, int x)
        {
            if (high >= low) {
                int mid = low + (high - low) / 2;

                
                if (arr[mid] == x)  //If the mid element is itself the target
                    return mid;
              
                if (arr[mid] > x)    //If element is smaller than mid, then element can only be present in left half subaray
                    return binarySearchRecursive(arr, low, mid - 1, x);

                return binarySearchRecursive(arr, mid + 1, high, x);   //else the element can only be present in right half subaray
            }

     
            return -1;   //If element not found return -1
        }
  
  
        //Java implementation of iterative Binary Search
        static int binarySearchIterative(int arr[], int x)
        {
            int low=0;
            int high=arr.length-1;
            while(low<=high)
            {
                int mid = low + (high - low) / 2;
                if(arr[mid]==x)
                    return mid;
                else if(arr[mid]<x)
                    low=mid+1;
                else
                    high=mid-1;
            }
            return -1;
        }

    // Driver method to test above
    public static void main(String args[])
    {

        int arr[] = { 3, 23, 40, 50,78 };
        int n = arr.length;
        int x = 50;
        int y=23;
        int result = binarySearchIterative(arr, x);
        if(result!=0)
          System.out.println("Using Iterative Binary Search" + result);
        else 
        System.out.println("Element not found");
      
        
        int result1=binarySearchRecursive(arr,0,n-1,y);
        if(result1!=0)
          System.out.println("Using Recursive Binary Search" + result1);
        else 
          System.out.println("Element not found");
            
    }
}
