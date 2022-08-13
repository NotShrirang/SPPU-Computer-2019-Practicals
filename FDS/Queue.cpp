#include<iostream>
#define MAX 10
using namespace std;
struct queue
{
    int front, rear, val;
};
class Queue
{
    int queue[MAX];
    struct queue Q;
    public:
    Queue()
    {
        Q.front=-1;
        Q.rear=-1;
    }
    int isFull();
    int isEmpty();
    int insert(int val);
    int Delete();
    int Display();
    int search(int key);
};
int Queue::isFull()
{
    if(Q.rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Queue::isEmpty()
{
    if(Q.front<0 || Q.front>Q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Queue::insert(int val)
{
    if(isFull()==1)
    {
        cout<<"Queue is full. Delete an element to add new element.\n";
        return 0;
    }
    else if(isEmpty()==1)
    {
        Q.rear=Q.rear+1;
        Q.front=Q.front+1;
        queue[Q.rear]=val;
        return Q.rear;
    }
    else
    {
        Q.rear=Q.rear+1;
        queue[Q.rear]=val;
        return Q.rear;
    }
}
int Queue::Delete()
{
    if(isEmpty()==1)
    {
        cout<<"\nThe queue is empty! Please add an element.\n";
        return 0;
    }
    else if (Q.front == Q.rear)
    {
        Q.front = -1;
        Q.rear = -1;
        return 0;
    }
    else
    {
        Q.val=queue[Q.front];
        for(int i=Q.front;i<Q.rear;i++)
        {
            queue[i]=queue[i+1];
        }
        Q.rear--;
        return Q.front;
    }
}
int Queue::Display()
{
    cout<<"\nQueue : ";
    for(int i=Q.front;i<=Q.rear;i++)
    {
        cout<<queue[i]<<" ";
    }
    return 0;
}
int main()
{
    int x, choice;
    Queue Q;
    while(1)
    {
        cout<<"Enter choice :\n";
        cout<<"1. Insert\n";
        cout<<"2. Delete\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cout<<"--> ";
        cin>>choice;
        switch(choice)
        {
            case 1: if(Q.isFull()==1)
                    {
                        cout<<"Queue is full. Delete an element to add new element.";
                    }
                    else
                    {
                        cout<<"\nEnter element: ";
                        cin>>x;
                        Q.insert(x);
                    }
                    cout<<endl;
                    break;
            case 2: if(Q.isEmpty()==1)
                    {
                        cout<<"\nThe queue is empty! Please add an element.";
                    }
                    else
                    {
                        cout<<"\nDeleting element...\n";
                        Q.Delete();
                    }
                    break;
            case 3: Q.Display();
                    cout<<endl;
                    break;
            case 4: cout<<"\nExiting the program...\n";
                    exit(1);
                    break;
        }
    }
    return 0;
}