#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;
#define SIZE 5

class stk
{
	int stack[SIZE]; 
	int top;
	public:
		int push(int item);
		int pop();
		int display();
	stk()
	{
		top=-1;
	}
};
int stk::push(int item)
{
    if(top==SIZE-1)
    {
	    cout<<"Stack is Full\n";
	    return(0);
  	}
    else
    {
  	    top=top+1;
  	    stack[top]=item;
 	}
  	return(0);
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
    return(temp);
}
int stk::display()
{
 	if(top==-1)
 	cout<<"stack empty\n";
 	else
 	{
 	 	cout<<"Elements are:\n";
		for(int i=top; i>=0; i--)
 	 	{
 	 		cout<<"|"<<stack[i]<<"|"<<"\n";
 	 	}
		cout<<"'--'\n";
	}
    cout<<endl;
	return(0);
}
int main()
{
  	int option=0;
  	stk s;
  	int element;
    while(1)
    {
        cout<<"\nEnter Choice:\n1. Push\n2. Pop\n3. Display\n4. Exit\n-->";
		cin>>option;
		switch(option)
		{
			case 1 : cout<<"Enter element to push: \n";
  	    			 cin>>element;
					 s.push(element);
					 break;
			case 2 : cout<<s.pop()<<" got popped!\n";
					 break;
			case 3 : s.display();
					 break;
			case 4 : exit(1);
		}
	    
    }
    getch();
    return 0;
}
