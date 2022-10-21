public class merge_sort {
    public static void printArray(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void fun(int arr[], int si, int ei) {
        // base case
        if (si >= ei) {
            return;
        }

        // logic
        int mid = si + (ei - si) / 2;
        // left part
        fun(arr, si, mid);
        // right part
        fun(arr, mid + 1, ei);
        // calling function for soting
        sort(arr, si, ei, mid);

    }

    public static void sort(int arr[], int si, int ei, int mid ){
        int temp[] = new int[ei-si+1]; //temp array
        int i = si;     // iterator for left part
        int j = mid +1; // iterator for right part
        int k = 0;      // iterator for temp array
         while(i <= mid && j <= ei){
            if(arr[i] < arr[j]){
                temp[k] = arr[i];
                i++;
            }else{
                temp[k]= arr[j];
                j++;
            }
            k++;
         }
        //  remaing for left part
         while(i <= mid){
            temp[k++]=arr[i++];
         }
        // remaing for left part
        while(j <= ei){
            temp[k++] = arr[j++];
        }
        // copy temp arr to original arr
        for(k=0, i=si; k<temp.length; k++, i++)
        {
            arr[i] = temp[k];
        }
    }

    public static void main(String[] args) {
        int arr[] = { 6, 3, 9, 5, 2, 8,1,17,3,5,3,8,5,3,21,1 };
        fun(arr , 0 , arr.length-1);
        printArray(arr);
    }
}
