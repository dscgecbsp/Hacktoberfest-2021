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
