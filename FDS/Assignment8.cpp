#include<iostream>
using namespace std;

class Node
{
public:
    int data;
   	Node *next;
    Node()
    {
        data=0;
    }
}*head, *head2, *temp, *I_head, *U_head;
int insert(int val, int set)
{
    Node *ptr = new Node();
    ptr->data=val;
    ptr->next=NULL;
    if(set==1)
    {
        if(head==NULL)
        {
            head = ptr;
        }
        else
        {
            temp=head;
   		    while(temp->next!=NULL)
   		    {
   			    temp=temp->next;
		    }
		    temp->next=ptr;
        }
    }
    else if(set==2)
    {
        if(head2==NULL)
        {
            head2 = ptr;
        }
        else
        {
            temp=head2;
   		    while(temp->next!=NULL)
   		    {
   			    temp=temp->next;
		    }
		    temp->next=ptr;
        }
    }
    else if(set==3)
    {
        if(I_head==NULL)
        {
            I_head = ptr;
        }
        else
        {
            temp=I_head;
   		    while(temp->next!=NULL)
   		    {
   			    temp=temp->next;
		    }
		    temp->next=ptr;
        }
    }
    else if(set==4)
    {
        if(U_head==NULL)
        {
            U_head = ptr;
        }
        else
        {
            temp=U_head;
   		    while(temp->next!=NULL)
   		    {
   			    temp=temp->next;
		    }
		    temp->next=ptr;
        }
    }
    return 0;
}
int display(int set)
{
    Node *ptr2;
    if(set==1)
    {
        ptr2=head;
    }
    if(set==2)
    {
        ptr2=head2;
    }
    if(set==3)
    {
        ptr2=I_head;
    }
    if(set==4)
    {
        ptr2=U_head;
    }        
    cout<<"List : ";
    while (ptr2 != NULL) 
    {
        cout<< ptr2->data <<" ";
        ptr2 = ptr2->next;
    }
    return 0;
}
int intersetion()
{
    Node *I1=head;
    Node *I2=head2;
    cout<<"\n";
    while(I1!=NULL)
    {
        I2=head2;
        while (I2!=NULL)
        {
            if(I1->data==I2->data)
            {
                insert(I1->data, 3);
            }
            I2=I2->next;
        }
        I1=I1->next;
    }
    cout<<"Set of students who like both vanilla and butterscotch : \n";
    display(3);
    return 0;
}
int Union()
{
    Node *U1=head;
    Node *U2=head2;
    Node *U4=U_head;
    int flag=0;
    U1=head;
    while(U1!=NULL)
    {
        insert(U1->data, 4);
        U1=U1->next;
    }
    U1=head;
    while(U2!=NULL)
    {
        flag=0;
        while(U1!=NULL)
        {
            if(U2->data==U1->data)
            {
                flag=1;
                break;
            }
            U1=U1->next;
        }
        if(flag==0)
        {
            insert(U2->data, 4);
        }
        U2=U2->next;
    }
    cout<<"\nSet of students who like either vanilla or butterscotch or not both :\n";
    display(4);
    return 0;
}
int Neither(int n)
{
    Node *N;
    int i=1, flag=0;
    N=U_head;
    cout<<"\nNumber of students who like neither vanilla nor butterscotch :";
    while(i<=n)
    {
        flag=0;
        N=U_head;
        while(N!=NULL)
        {
            if(N->data==i)
            {
                flag=1;
                break;
            }
            N=N->next;
        }
        if(flag==0)
        {
            cout<<" "<<i;
        }
        i++;
    }
    return 0;
}
int isIn(int val, int set)
{
    if(set==1)
    {
        temp=head;
    }
    if(set==2)
    {
        temp=head2;
    }
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main()
{
    Node *temp;
    head=NULL;
    head2=NULL;
    int rollno, total;
    cout<<"###################################### Welcome ####################################";
    cout<<"\nEnter total no. of students :";
    cin>>total;
    cout<<"\nEnter roll no. of students who like vanilla:\n";
    while(1)
    {
        cout<<"Enter roll number (Press 0 to terminate):";
        cin>>rollno;
        if(rollno==0)
        {
            break;
        }
        else if(isIn(rollno, 1)==1)
        {
            cout<<"Already in list!\n";
        }
        else if(rollno<=-1)
        {
            cout<<"Negative value.\n";
        }
        else
        {
            insert(rollno, 1);
        }
    }
    display(1);
    cout<<"\nEnter roll no. of students who like butterscotch:\n";
    while(1)
    {
        cout<<"Enter roll number (Press 0 to terminate):";
        cin>>rollno;
        if(rollno==0)
        {
            break;
        }
        else if(isIn(rollno, 2)==1)
        {
            cout<<"Already in list!\n";
        }
        else
        {
            insert(rollno, 2);
        }
    }
    display(2);
    intersetion();
    Union();
    Neither(total);
    return 0;

}