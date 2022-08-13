#include<iostream>
#define size 10
using namespace std;

int stack[size];
int data;
int stkptr;

int isFull()
{
    if(stkptr==size-1)
    {
        return(1);
    }
    else
    {
        return(0);
    }
}
int isEmpty()
{
    if(stkptr==-1)
    {
        return(1);
    }
    else
    {
        return(0);
    }   
}
int push(int val, int stkptr)
{
    if(isFull()==1)
    {
        cout<<"Stack is Full!";
    }
    else
    {
        stkptr=stkptr+1;
        stack[stkptr]=val;
    }
    return stkptr;
}

int pop()
{
    if(stkptr==0)
    {
        cout<<"Stack is empty, cannot remove anything!";
    }
    else
    {
        stkptr=stkptr-1;
    }
    return stkptr;
}

int display(int stkptr)
{
    int i=0;
    if(isEmpty()==-1)
    {
        cout<<"Empty!";
    }
    else
    {
        cout<<"Stack: \n";
        for(i=stkptr;i>=0;i--)
        {
            cout<<" "<<stack[i];
        }
    }
    return 0;
}
int main()
{
    stkptr=-1;
    int choice, val, flag;
    flag=1;
    while(flag==1)
    {
        cout<<"\nEnter choice :\n1. Push\n2. Pop\n3. Display\n4. Exit\n-->";
        cin>>choice;
        switch(choice)
        {
            case 1 :    cout<<"Enter element: ";
                        cin>>val;
                        push(val,stkptr);
                        break;
            case 2 :    pop();
                        break;
            case 3 :    display(stkptr);
                        break;
            case 4 :    cout<<"Exiting the code...";
                        exit(0);
                        break;
            default:    cout<<"Enter correct choice:";
                        break;
        }
    }

}