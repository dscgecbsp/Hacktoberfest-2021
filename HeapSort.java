class Solution
{
    
 
    //Heapify function to maintain heap property.
    void heapify(int a[], int n, int i)
    {
      
        int largest = i;
        int l = (2*i) + 1;
        int r = (2*i) + 2;
        
        if(l<n && a[l]>a[largest])
            largest = l;
        if(r<n && a[r]>a[largest])
            largest = r;
        if(largest!=i){
            swap (a, i , largest);
            heapify(a, n, largest);
        }
    }
    
    //Function to build a Heap from array.
  public  void buildHeap(int a[], int n)
    {
       
        for(int i = (n-1)/2 ; i>=0; i--){
            heapify(a,n,i);
        }
    }
   
    
    //Function to sort an array using Heap Sort.
    public void heapSort(int a[], int n)
    {
       
        buildHeap(a,n);
        
        for(int i=n-1;i>0;i--){
            swap(a, 0 , i);
            heapify(a,i,0);
        }
    }
    
    public static void swap(int[]a,int i, int j){
        int temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
