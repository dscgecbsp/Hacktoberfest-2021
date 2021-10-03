Top-Dpwn Approach(Memoization):---


class Solution 
{ 
    //Function to return max value that can be put in knapsack of capacity W.
    
    static int knapSack(int W, int wt[], int val[], int n,int [][]t) 
    { 
         // your code here 
         
         
         if(n==0 || W==0)
	     return 0;
	     
         if(t[n][W]!=-1)
	     return t[n][W];
	     
	     if(wt[n-1] > W)
	     return  t[n][W]= knapSack(W,wt,val,n-1,t);
	     
         else
	     return t[n][W]=Math.max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1,t),knapSack(W,wt,val,n-1,t));
	     
         
	     
}
     static int knapSack(int W, int wt[], int val[], int n) 
    { 
        int[][] t = new int[n+1][W+1];
        for(int i = 0; i < n + 1  ; i++)   
        for(int j = 0; j < W + 1; j++)   
            t[i][j] = -1;  
    
        return knapSack(W, wt, val, n,t );
    } 



}





Bottom-up Approach(Tabulation):---

class Solution 
{ 
    //Function to return max value that can be put in knapsack of capacity W.
    static int knapSack(int W, int wt[], int val[], int n) 
    { 
         // your code here 
         int[][] t = new int[n+1][W+1];
         for(int i = 0; i < n + 1; i++){
         for(int j = 0; j < W + 1; j++) {
           if(i==0 || j==0)
            t[i][j] = 0; 
         }
         }
         
         for(int i = 1; i < n + 1; i++){
         for(int j = 1; j < W + 1; j++) {
             
	     if(wt[i-1] <= j)
	     t[i][j]=Math.max(val[i-1]+ t[i-1][j-wt[i-1]],t[i-1][j]);
	     
         else
	     t[i][j]= t[i-1][j];
         }
         }
         
         return t[n][W];
    } 
}
