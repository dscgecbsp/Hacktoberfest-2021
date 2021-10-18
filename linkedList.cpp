#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	
	Node(int x){
		data=x;
		next=NULL;
	}
};

Node* insertAtEnd(int i, Node* head){
	struct Node* node=new Node(i);
	struct Node* current;
	current=head;

	if(head==NULL)
		return node;

	while(current->next!=node){
		if (current->next!=NULL)
			current=current->next;
		else
			current->next=node;
	}

return head;
}

//this part just skips a node
// Node* skipNode(Node* head, int y){
//     struct Node* current=new Node(0);
//     current=head;
    
//     if(y==1)
//         return head->next;
        
//     for(int i=1; i<y-1; i++){
//         current=current->next;
//     }
//     current->next = current->next->next;
    
//     return head;
// }

//this part deletes a node
Node* deleteNode(Node* head, int y){
    struct Node* current=NULL;
    struct Node* temp=NULL;
    current=head;
    temp=head->next;

    if(y==1)
        return head->next;
        
    for(int i=1; i<y-1; i++){
        current=current->next;
        temp=temp->next;
    }
    current->next = current->next->next; //or current->next=temp->next;
    delete temp;
    
    return head;
}

void printList(Node* head){
	
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	
	cout<<"\n";
}



int main(){
	cout<<"input size of linked list, then eliments of linked list, then no, of which eliment is to be deleted. \n";
	int x,y;
	cin >> x;

	struct Node* head=NULL;

	while(x--){
		int i;
		cin >> i;
		head=insertAtEnd(i, head);
	}

	cin >> y;

	if(y!=0)
		head=deleteNode(head, y);

	printList(head);

	return 0;
}
