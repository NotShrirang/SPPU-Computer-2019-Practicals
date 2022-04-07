// Kruskal's Algorithm
#include<iostream>
using namespace std;

int MAX;
class LL
{
public:
    int source;
    int destination;
    int weight;
    LL *next;
    LL(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
        next = NULL;
    }
}*head2, *temp2;
int insertInLL(int s, int d, int w)
{
    LL *ptr = new LL(s, d, w);
    if(head2==NULL)
    {
        head2 = ptr;
    }
    else
    {
        
        if(head2->weight > w)
        {
            ptr->next = head2;
            head2 = ptr;
        }
        else
        {
            temp2 = head2;
            while(temp2->weight<=w)
            {
                if(temp2->next!=NULL)
                {
                    temp2 = temp2 ->next;
                }
            }
            if(temp2->next!=NULL)
            {
                ptr->next = temp2->next;
            }
            temp2->next = ptr;
        }
    }
    return 0;
}
class Node
{
public:
    int dest;
    int weight;
    Node* next;
    Node(int destination, int w)
    {
        dest  = destination;
        weight = w;
        next = NULL;
    }
}*head, *temp;
void insert(Node *offices[], int src, int dest, int weight)
{
    Node *ptr = new Node(dest, weight);
    if(offices[src - 1]==NULL)
    {
        offices[src-1] = ptr;
    }
    else
    {
        Node* temp = offices[src-1];
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
int display(Node *offices[])
{
    cout<<"\n##### Telephone connection ##### ";
    for(int i=0; i<MAX; i++)
    {
        if(offices[i]!=NULL)
        {
            cout<<"\nOffice "<<i+1<<" :\n";
            for(temp = offices[i]; temp!=NULL; temp = temp->next)
            {
                cout<<"\tTo : Office "<<temp->dest<<", (Weight : "<<temp->weight<<")\n";
            }
        }
    }
    cout<<"\n########################\n";
    return 1;
}
int Kruskal(Node *offices[])
{
    for(int i=0; i<MAX; i++)
    {
        if(offices[i]!=NULL)
        {
            // cout<<"\nOffice "<<i+1<<" :\n";
            for(temp = offices[i]; temp!=NULL; temp = temp->next)
            {
                // cout<<"\tTo : Office "<<temp->dest<<", (Weight : "<<temp->weight<<")\n";
                insertInLL(i, temp->dest, temp->weight);
            }
        }
    }
    for(temp2=head2; temp2!=NULL; temp2 = temp2->next)
    {
        cout<<"From "<<temp2->source<<" to "<<temp2->destination<<" weight = "<<temp2->weight<<endl;
    }
    return 1;
}
int main()
{
    int no;
    cout<<"Enter number of offices : ";
    cin>>no;
    Node* offices[no];
    MAX = no;
    for(int i=0;i<=no;i++)
    { 
        offices[i] = NULL;
    }
    while(1)
    {
        int choice, src, dest, w;
        cout<<"Enter choice :\n1. Insert\n2. Apply Kruskal's Algorithm\n3. Exit ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter source : ";
            cin>>src;
            cout<<"Enter destination : ";
            cin>>dest;
            cout<<"Enter cost :";
            cin>>w;
            insert(offices, src, dest, w);
            break;
        case 2:
            head=NULL;
            display(offices);
            Kruskal(offices);
            break;
        default:
            exit(1);
            break;
        }
    }
    return 0;
}