/*
This is a basic linked list code to insert a node at specific position.

Linked list: A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The elements in a linked list are linked using pointers.

-In linked list(singly) one node contains 2 values - data and address of next node
-Head shows/refers the starting node of the list.
-Last node will contain NULL in the next link address as there is no node after it to contain address of.


Now to add node at specific position
  1.Loop to the node after which we have to add new node.
  2.As we want to add a node in middle, we will have to pass or save the next node address to new node next variable.
  3.And we will store the data in new node data variable.
  4.And then we will link the node(previous node to which we looped to) to new node.
  
  Now that previous node contains address of new node and new node contains address of next node to which previous node was pointing before.
*/

#include<stdio.h>
#include<stdlib.h>

//Creating Linked list structure
struct Node{
    int data;
    struct Node* next;
};


int main(){
    int value = 0, position = 0;
    
    //Declaring nodes
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    
    //Allocating memory
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    //Assigning values
    first->data = 10;
    first->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;
    head = first;
    
    //Taking user input for new node
    printf("Enter node number after which you wanna add new node: ");
    scanf("%d", &position);
    printf("Enter value: ");
    scanf("%d", &value);
    
    //Creating new node
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = value;
    
  
    //Adding Node at the position
    struct Node* temp = head;
    if (head == NULL){ 
        head = newnode;
    }
    else{
        for(int i=1;i<position;i++){  
            temp = temp->next;
        }
        newnode->next = temp->next;   
        temp->next = newnode; 
    }
    
  
  //Displaying linked list
    temp = head;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
