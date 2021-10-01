#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char data;
	struct node * next;
}node;
node * head=NULL;
char pop();
int isEmpty(node * head);
int inpriority(char a);
int outpriority(char a);
node * push(char a,node * head);
node * create(char a);
void display(node *head);
int main(){
	node* ans=NULL;
	char a[100];
	scanf("%s",a);
	int n=strlen(a);
	for(int i=n-1;i>=0;i--){
		if(a[i]=='('){ 
			while(head->data!=')'){
				ans=push(pop(),ans);
			}
			pop();
		}
		else if(a[i]==')')head=push(a[i],head);
		else if(outpriority(a[i])==0) ans=push(a[i],ans);
		else if(isEmpty(head)  || inpriority(head->data)<outpriority(a[i])){head=push(a[i],head);}
		else{

			while( (!isEmpty(head)) && inpriority(head->data)>outpriority(a[i]) ){
				ans=push(pop(),ans);
				}
				head=push(a[i],head);
			}
	}
	while(!isEmpty(head)){
				ans=push(pop(),ans);
			}
	printf("ansr\n");
	display(ans);

	return 0;
}
node * create(char a){
	node * newd=(node *)malloc(sizeof(node));
	if(newd==NULL){printf("Stack overflow\n");return newd;}
	newd->data=a;
	return newd;
}
node * push(char a,node * head){
	node * newd=create(a);
	newd->next=head;
	return newd;
}
int inpriority(char a){
	if(a=='^') return 6;
	else if(a=='*' || a=='/' || a=='%') return 3;
		else if(a=='+' || a=='-') return 1;
			else return 0;
}
int outpriority(char a){
	if(a=='^') return 5;
	else if(a=='*' || a=='/' || a=='%') return 4;
		else if(a=='+' || a=='-') return 2;
			else return 0;
}
int isEmpty(node * head){
	if(head==NULL) return 1;
	else return 0;
}
char pop(){
	if(head==NULL){printf("stack underflow\n");return -1;}
	char data=head->data;
	node * garbage=head;
	head=head->next;
	free(garbage);
	return data;
}
void display(node * head){
	if(head==NULL)return;
	printf("%c",head->data);
	display(head->next);
	
}