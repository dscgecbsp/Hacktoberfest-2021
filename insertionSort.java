// Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands.
// The array is virtually split into a sorted and an unsorted part. 
// Values from the unsorted part are picked and placed at the correct position in the sorted part.
// Algorithm 
// To sort an array of size n in ascending order: 
// 1: Iterate from arr[1] to arr[n] over the array. 
// 2: Compare the current element (key) to its predecessor. 
// 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
import java.util.*;
public class insertionSort {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int len=sc.nextInt();
        int []arr=new int[len];
        for(int i=0;i<len;i++){
          System.out.println("Enter the value of the element at position "+i);
          arr[i]=sc.nextInt();
        }
        for(int i=1;i<arr.length;i++){
            int temp=arr[i],j=i;
            while(j>0 && arr[j-1]>temp){
                arr[j]=arr[j-1];
                j--;
            }
            arr[j]=temp;
        }
        for(int element:arr){
            System.out.println(element+" ");
        }
    }
}
