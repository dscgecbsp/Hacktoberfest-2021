#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
void transpose(int **a,int n)
{
  int i,j;
  for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
       swap(a[i][j],a[j][i]);
     }
   } 
}
void swapping(int **a,int n)
{
  int i,j;
   for(i=0;i<n/2;i++)
    {
      for(j=0;j<n;j++)
      {
        swap(a[j][i],a[j][n-i-1]);
      }
    }
}
int main()
{
  int t;
  cin>>t;
  while(t)
  {
   int n,i,j;
   cin>>n;
    int **a;
a = new int *[n];
for(int i = 0; i <n; i++)
    a[i] = new int[n];
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      cin>>a[i][j];
    }
  }
    transpose(a,n);
    swapping(a,n);
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        cout<<a[i][j];
       if(j!=n-1)
       cout<<+" ";
      }
      cout<<endl;
    }
    cout<<endl;
   t--;
  }
   return 0;
}
