#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
#define SIZE 100

class stk
{
	char stack[SIZE]; 
	int top;
	public:
		int push(char val);
		int pop();
		int display(int top);
		char getTop(int top);
	stk()
	{
		top=-1;
	}
};
int stk::push(char val)	
{
    if(top==SIZE-1)
    {
	    cout<<"Stack is Full\n";
	    return(0);
  	}
    else
    {
  	    top=top+1;
  	    stack[top]=val;
 	}
  	return(top);
}
int stk::pop()
{
 	int temp;
 	if(top==-1)
 	{
 		cout<<"Empty Stack:\n";
 		return(0);
	}
	else
	{
		temp=stack[top];
		top=top-1;
	}
    return(top);
}
int stk::display(int top)
{
 	if(top==-1)
 	cout<<"stack empty\n";
 	else
 	{
 	 	cout<<"\nElements are: ";
 	 	for(int i=top; i>=0; i--)
 	 	{
 	 		cout<<stack[i]<<"\t";
 	 	}
	}
    cout<<endl;
	return(0);
}
char stk::getTop(int top)
{
	if(top==-1)
	{
		cout<<"stack empty\n";
		return 0;
	}
 	else
	{
		return stack[top];
	}
}
int main()
{
  	int i,top;
    char exp[100];
    char a;
    stk s;
    cout<<"Enter exp (Press Q to exit.):\n";
    while(1)
    {
        cin>>a;
        if(a=='Q')
        {
            exp[i]='Q';
			break;
        }
        else
        {
            exp[i]=a;
        }
		i++;
    }
    i=0;
	cout<<"Expression: ";
    while(exp[i]!='Q')
    {
        cout<<exp[i];
        i++;
    }
    for(i=0;exp[i]!='Q';i++)
    {
        if(exp[i]=='('||exp[i]=='[' || exp[i]=='{')
        {
            top=s.push(exp[i]);
        }
		else if(exp[i]==')' && s.getTop(top)=='(' || exp[i]==']' && s.getTop(top)=='[' || exp[i]=='}' && s.getTop(top)=='{')
		{
			top=s.pop();
		}
    }
	if(top==-1)
	{
		cout<<"\nThe expression is well paranthesized!";
	}
    else
	{
		cout<<"\nThe expression is not well paranthesized!";
	}
    return 0;
}
