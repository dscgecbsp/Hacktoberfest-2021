//reverse the array
import java.util.Scanner;

public class reverseTheArray {
    public static void reverse(int a[], int start, int end) {

        int temp;
        if (start > end) {
            return;
        }
        temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        reverse(a, start + 1, end - 1);
    }

    public static void printArray(int a[]) {
        for (int i = 0; i < a.length; i++)
            System.out.print(a[i] + " ");
        System.out.println("");
    }

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int a[] = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();
        printArray(a);
        reverse(a, 0, n - 1);
        System.out.println("Reversed array is ");
        printArray(a);
    }
}
