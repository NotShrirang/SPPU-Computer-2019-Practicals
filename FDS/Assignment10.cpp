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
		int isEmpty();
        int push(char val);
		int pop();
		int display(int top);
        char getTop();
        int evalPostfix(char exp[]);
	stk()
	{
		top=-1;
	}
};
int stk::isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int stk::push(char val)	
{
    int item;
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
 	cout<<"Stack empty\n";
 	else
 	{
 	 	cout<<"\nElements are: ";
 	 	for(int i=top; i>=0; i--)
 	 	{
 	 		cout<<stack[i]<<" ";
 	 	}
	}
    cout<<endl;
	return(0);
}
char stk::getTop()
{
    return stack[top];
}
int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
float calc(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}
int stk:: evalPostfix(char exp[])
{
    stk eval;
    int i=0;
    while(exp[i]!='Q')
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z' || exp[i]>='0' && exp[i]<='9')
        {
            eval.push(exp[i]);
        }
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            int val1=eval.getTop();
            top=eval.pop();
            int val2=eval.getTop();
            top=eval.pop();
            cout<<calc(val1, val2, exp[i]);
        }
        i++;
    }
    return 0;
}
int main()
{
    int i,top;
    char exp[100];
    char a;
    stk s;
    cout<<"Enter exp : \n";
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
    cout<<"Entered Expression : ";
    while(exp[i]!='Q')
    {
        cout<<exp[i];
        i++;
    }
    i=0;
    cout<<endl<<"Postfix : ";
    while(exp[i]!='Q')
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z' || exp[i]>='0' && exp[i]<='9')
        {
            cout<<exp[i];
        }
        else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
        {
            if(prec(exp[i])<=prec(s.getTop()))
            {
                while(prec(exp[i])<=prec(s.getTop()))
                {
                    cout<<s.getTop();
                    s.pop();
                }
                s.push(exp[i]);
            }
            else
            {
                top=s.push(exp[i]);
            }

        }
        i++;
    }
    while(top!=-1)
    {
        cout<<s.getTop();
        top=s.pop();
    }
    // s.evalPostfix(exp);
    return 0;
}