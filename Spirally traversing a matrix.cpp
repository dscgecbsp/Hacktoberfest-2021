#include<iostream>
#include<cstdio>
#define ROWS 50
#define COLS 50
using namespace std;
void printSpiral(int a[ROWS][COLS], int r, int c){
int top=0,down=r-1,left=0,right=c-1;
  int dir=1,i,j,k;
  while(top<=down && left<=right)
  {
    if(dir==1)
    {
      for(i=left;i<=right;i++)
      {
        cout<<a[top][i]<<endl;
      }
        top++;
      dir=2;
    }
    else if(dir==2)
    {
      for(i=top;i<=down;i++)
      {
   cout<<a[i][right]<<endl;
      }
        right--;
      dir=3;
    }
     else if(dir==3)
    {
      for(i=right;i>=left;i--)
      {
   cout<<a[down][i]<<endl;
      }
        down--;
       dir=4;
    }
     else if(dir==4)
    {
      for(i=down;i>=top;i--)
      {
   cout<<a[i][left]<<endl; 
      }
        left++;
        dir=1;
    }
  }
}
int main()
{
  int r, c;
  cin>>r>>c;
  int a[ROWS][COLS], i, j;
  for(i = 0; i < r; i++)
    for(j = 0; j < c; j++)
      cin>>a[i][j];
  printSpiral(a, r, c);
  return 0;
}
