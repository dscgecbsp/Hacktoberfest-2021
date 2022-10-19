#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
}*root=NULL;

int c=0;

int append_end()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
			p=p->link;
		p->link=temp;
	}
	printf("---Node created Succesfully---\n\n");
}

void append_begin()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	
	temp->link=NULL;
	if(root==NULL)
		root=temp;
	else
	{
		temp->link=root;
		root=temp;		
	}
	printf("---Node created Succesfully---\n\n");
}

void append_pos()
{
	struct node *temp,*p;
	int pos,i;
	temp=(struct node*)malloc(sizeof(struct node*));
	printf("Enter the Position and Data: ");
	scanf("%d %d",&pos,&temp->data);
	temp->link=NULL;
	if(pos>=1 && pos<=c+1)
	{
		if(root==NULL)
			root=temp;
		else
		{
			p=root;
			if(pos==1)
			{
				temp->link=root;
				root=temp;
			}
			else
			{
				for(i=1;i<pos-1;i++)
					p=p->link;
				temp->link=p->link;
				p->link=temp;
			} 
		}
		c++;
		printf("---Node created Succesfully---\n\n");
	}
	else
		printf("Invalid Input");
}

void display()
{
	struct node *ptr;
	ptr=root;
	if(ptr==NULL)
		printf("\nThe List is empty\n");
	else
	{
		printf("The data/s is/are---> ");
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
		printf("\n\n");
	}
}

void del_end()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("The List is Empty");
	else
	{
		while(ptr->link!=NULL)
		{
			p=ptr;
			ptr=ptr->link;
		}
		if(ptr==root)
			root=NULL;
		else
			p->link=NULL;
		printf("---Node Deleted Succefully---\n\n");
	}
}

void del_begin()
{
	struct node *ptr,*p;
	ptr=root;
	if(ptr==NULL)
		printf("The List is Empty");
	else
	{
		root=ptr->link;
		printf("---Node Deleted Succefully---\n\n");
	}
}

del_val()
{
	struct node *ptr,*p;
	int val,f=0;
	ptr=root;
	printf("Enter the Data to be Deleted: ");
	scanf("%d",&val);
	if(ptr==NULL)
		printf("\nThe List is Empty\n\n");
	else
	{
		if(ptr->link==NULL && ptr->data==val)
		{
			root=NULL;
			printf("\n---Node deleted Succesfully---\n\n");
		}
		else
		{
			while(ptr->data!=val)
				ptr=ptr->link;
			if(ptr==NULL)
				printf("\nThe Value is not present\n\n");
			else
			{
				ptr=root;
				while(ptr->data!=val)
				{
					p=ptr;
					ptr=ptr->link;
				}
				if(ptr==root)
					root=ptr->link;
				else
					p->link=ptr->link;
				printf("\n---Node deleted Succesfully---\n\n");
			}
		}
	}
}

void del_dup()
{
	struct node *current,*index,*temp;
	current=root;
    if(current==NULL)
		printf("\nThe List is Empty\n");  
    else
	{
		while(current!=NULL)
		{
			temp=current;
            index=current->link;  
            while(index!=NULL)
			{
				if(current->data==index->data)
                    temp->link=index->link;  
                else
                	temp=index;
                index=index->link;  
            }
            current=current->link;
        }
        printf("\n---Duplicate Nodes Deleted Succesfully---\n\n");
        display();
    }
}

void reverse()
{ 
    struct node *prev = NULL,*current,*next = NULL; 
    current=root;
    while(current!=NULL)
	{ 
        next=current->link; 
        current->link=prev; 
        prev=current; 
        current=next; 
    } 
    root=prev;
    	printf("---List Reversed Succesfully---\n\n");
}

int main()
{
	int ch;
	start:
	printf("1. Append Node at End\n2. Append Node at Beginning\n3. Append Node at Position\n4. Display Nodes\n");
	printf("5. Length of the List\n6. Delete from End\n7. Delete from Beginning\n8. Delete by Value\n");
	printf("9. Delete Duplicate Elements\n10. Reverse the List\n11. Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			append_end();
			c++;
			goto start;
		case 2:
			append_begin();
			c++;
			goto start;
		case 3:
			append_pos();
			goto start;
		case 4:
			display();
			goto start;
		case 5:
			printf("The Length of the Linked List is %d",c);
			goto start;
		case 6:
			del_end();
			c--;
			goto start;
		case 7:
			del_begin();
			c--;
			goto start;
		case 8:
			del_val();
			c--;
			goto start;
		case 9:
			del_dup();
			goto start;
		case 10:
			reverse();
			goto start;
		case 11:
			printf("\n---Program Terminated---");
			break;
	}
}
