#include <iostream>
using namespace std;
static int visited[10];
int MAX;
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
void PrimsAlgo(Node* offices[], int i, int visited[], int count)
{
    visited[count] = i;
    cout<<visited[count];
    int min_weight = 1000, o=0;
    for(int j=0; j<MAX;j++)
    {
        temp = offices[j];
        while(temp!=NULL)
        {
            temp = temp->next;
            if(temp->weight<=min_weight)
            {
                cout<<"\nWeight : "<<temp->weight<<"\nMin weight : "<<min_weight;
                min_weight = temp->weight;
                o = temp->dest;
                cout<<"\nMin weight : "<<min_weight<<"\no = "<<o;
            }
            cout<<"Hello1";
        }
        cout<<"Hello2";
    }
    cout<<"Hello3";
    if(count!=MAX)
    {
        cout<<"\nIn";
        PrimsAlgo(offices, o-1, visited, count+1);
    }
    for(int k = 0; k<10; k++)
    {
        cout<<" "<<visited[k];
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
int main()
{
    int no;
    cout<<"Enter number of offices";
    cin>>no;
    Node* offices[no];
    MAX = no;
    for(int i=0;i<=no;i++)
    { 
        offices[i] = NULL;
        visited[i] = 0; 
    }
    while(1)
    {
        int choice, src, dest, w;
        cout<<"Enter choice :\n1. Insert\n2. Apply Prim's Algorithm\n3. Exit ";
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
            display(offices);
            PrimsAlgo(offices, 1, visited, 0);
            break;
        default:
            exit(1);
            break;
        }
    }
    return 0;
}