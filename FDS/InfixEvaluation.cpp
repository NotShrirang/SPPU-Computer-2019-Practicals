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
        char getTop();
        int isEmpty();
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
int IsAlphaOrNum(char c)
{
    if(c>='a' && c<='z' || c>='A' && c<='Z')
    {
        return 2;
    }
    else if(0<=c && c<=9)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int calc(int a, int b, char op)
{
	switch(op)
    {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}
int evaluateInfix(char exp[])
{
    int length=0;
    stk value, ops;
    int i=0;
    while(exp[i]!='Q')
    {
        length++;
    }
    for(i=0; i<length; i++)
    {
        if(exp[i]=='(')
        {
            ops.push(exp[i]);
        }
        else if(IsAlphaOrNum(exp[i]==1))
        {
            int val=0;
            while(exp[i]!='Q' && IsAlphaOrNum(exp[i]==1))
            {
                val = (val*10) + (exp[i]-'0');
                i++;
            }
            value.push(val);
            i--;
        }
        else if(exp[i] == ')')
        {
            while(!ops.isEmpty() && ops.getTop()!='(')
            {
                int val2 = value.getTop();
                value.pop();
                int val1 = value.getTop();
                value.pop();
                char op = ops.getTop();
                ops.pop();
                value.push(calc(val1, val2, op));
            }
            if(!ops.isEmpty())
            {
                ops.pop();
            }
        }
        else
        {
            while(!ops.isEmpty() && prec(ops.getTop()) >= prec(exp[i]) );
            {
                int val2 = value.getTop();
                value.pop();
                int val1 = value.getTop();
                value.pop();
                char op = ops.getTop();
				ops.pop();
                value.push(calc(val1, val2, op));
            }
            ops.push(exp[i]);
        }
    }
    while(!ops.isEmpty())
    {
		int val2 = value.getTop();
		value.pop();
				
		int val1 = value.getTop();
		value.pop();
				
		char op = ops.getTop();
		ops.pop();
				
		value.push(calc(val1, val2, op));
	}
    return value.getTop();
}
int main()
{
    int i,top;
    char exp[100];
    char a;
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
    while(exp[i]!='Q')
    {
        cout<<exp[i];
        i++;
    }
    i=0;
    cout<<endl;
    evaluateInfix(exp);
    return 0;
}