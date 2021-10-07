#include<iostream>
using namespace std;
int main()
{ 
int a[5],t,i,j;
    for(i=0;i<5;i++)
{
        	cout<<"Enter the value: "<<endl;
            cin>>a[i];
}
            cout<<"The Originel values in the array : "<<endl;
            for(i=0;i<5;i++)
	        cout<<a[i]<<"  ";
	    
	for(i=0;i<5;i++){
		
    for(j=0;j<4;j++){
	
    if(a[j]<a[j+1]){
    	
   t=a[j];
   a[j]=a[j+1];
   a[j+1]=t;
}
}
}
cout<<"\nThe sorted array :  \n";
for(i=0;i<5;i++)
cout<<a[i]<<" ";
}


