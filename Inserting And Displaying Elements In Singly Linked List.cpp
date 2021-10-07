//Inserting and displaying elements in singly linked list.

#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

struct node* head= NULL;

//Function to insert data in linked list 
void insert(int data)
{
    struct node *ptr= (node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    head=ptr;
    
}
//Function to Display the entered linked list 
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    int n,j;
    cout<<"Enter the total number of elements you want to insert in the linked list : ";  
    cin>>n;
    cout<<"Enter the elements : \n";
    for(int i=0;i<n;i++)
    {
        cin>>j;
        insert(j);
    }
    cout<<"\nDisplaying the linked list : ";
    display();
    
    return 0;
}
