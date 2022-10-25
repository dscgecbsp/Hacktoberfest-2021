#include<iostream>
using namespace  std ;
#define max 20 
class stack
{
   int stck[max]  ;
   int top ;
public :
    void init() ;
    void push(int i) ;
    void pop() ;
    void display() ;
};
void stack::init()
{
    top=0;
}
void stack::push(int i)
{
    
    if(top==max-1)
    {
        cout<<"Stack is full\n" ;
    }
    else
    {
        top++ ;
        stck[top]= i ;
    }
}
void stack::pop()
{
    int x ;
    if(top==0)
    {
        cout<<"Stack is empty\n" ;
    }
    else
    {
        x=stck[top] ;
        top--;
        cout<<"Deleted element is:"<<x ;
    }
}
void stack::display()
{
    if(top==-1)
    {
        cout<<"Stack is empty\n" ;
    }
    else
    {
        cout<<"Elements in the stack are\n" ;
        while(top>=0)
        {
            cout<<stck[top] ;
            top--;
        }
    }
}
int main()
{
    stack stack1 ;
    stack1.push(20) ;
    stack1.push(28) ;
    stack1.push(89) ;
    stack1.push(67) ;

    stack1.pop() ;
    

    stack1.display() ;
    
    return 0 ;
}
