#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *next;
};

void linkedListTraversal(struct Node *head){
	struct Node *ptr=head;
	do{
		printf("Elements: %d\n",ptr->data);
		ptr=ptr->next;
	}while(ptr!=head);
}

int main(){
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	//Allocate memory to nodes in heap
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	fourth=(struct Node*)malloc(sizeof(struct Node));
	
	//Link first to second
	head->data=4;
	head->next=second;
	
	//Link second to third
	second->data=3;
	second->next=third;
	
	//Link third to fourth
	third->data=6;
	third->next=fourth;
	
	//Link fourth to head(first)
	fourth->data=1;
	fourth->next=head;
	
	linkedListTraversal(head);
  
  return 0;
}
