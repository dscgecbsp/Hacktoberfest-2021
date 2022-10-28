#include<stdio.h>
int main()
{
	int i,j,k,p,q,r,rows,a;
	printf("enter no of rows:");
	scanf("%d",&rows);
	a=rows;
	for(i=1;i<=rows;i++)
	{
		for(j=1;j<=rows-i;j++)
		{
			printf(" ");
		}
		for(k=1;k<=(2*i-1);k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(p=1;p<=rows;p++)
	{
		for(q=1;q<p;q++)
		{
			printf(" ");
		}
		for(r=(2*a-1);r>=1;r--)
			{printf("*");
			
			}
			a--;
			printf("\n");
			}
			return 0;
		}
