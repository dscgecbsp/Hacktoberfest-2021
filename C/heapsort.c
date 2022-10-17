/*Program to demonstrate the heap sort algorithm to sort an array using max heap*/

#include<stdio.h>
#include<math.h>
main()
{
      int a[100],n,i,lb,ub;
      void swap(int*,int*);
      void heapsort(int[],int,int);
      printf("Enter number of elements:");
      scanf("%d",&n);
      lb=0;
      ub=n-1;
      printf("Enter the elements:\n");
      for(i=0;i<n;i++)
                      scanf("%d",&a[i]);
      heapsort(a,lb,ub);
      printf("The sorted array is:\n");
      for(i=0;i<n;i++)
                      printf("%d\t",a[i]);
      getch();
}
                       
void swap(int*p,int*q)
{
	int temp;
	temp=*p;
	*p=*q;
	*q=temp;
}
      

void heapsort(int a[],int lb,int ub)
{
	int i;
	void create_heap(int[],int,int,int,int);
	void del_heap(int[],int,int,int);
	for(i=lb;i<=ub;i++)
	{
		create_heap(a,i,a[i],lb,ub);
	}
	i=ub;
	while(i>=lb)
	{
		del_heap(a,i+1,lb,ub);
		i--;
	}
}

void create_heap(int a[],int heapsize,int data,int lb,int ub)
{
	int i,p;
	int parent(int);
	i=lb+heapsize;
	a[i]=data;
	while(i>lb&&a[p=parent(i)]<a[i])
	{
		swap(&a[p],&a[i]);
		i=p;
	}
}

void del_heap(int a[],int heapsize,int lb,int ub)
{
	int data,i,l,r,max_child;
	int left(int);
	int right(int);
	swap(&a[lb],&a[heapsize-1]);
	i=lb;
	heapsize--;
	while(1)
	{
		if((l=left(i))>=heapsize)
			break;
		if((r=right(i))>=heapsize)
			max_child=l;
		else
			max_child=(a[l]>a[r])?l:r;
		if(a[i]>=a[max_child])
			break;
		swap(&a[i],&a[max_child]);
		i=max_child;
	}
}

int parent(int i)
{
	float p;
	p=((float)i/2.0)-1.0;
	return ceil(p);
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
