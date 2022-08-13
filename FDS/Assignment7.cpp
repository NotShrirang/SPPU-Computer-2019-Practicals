#include <iostream>
using namespace std;

class Node  
{
	public:
   	string data;
   	Node* next;
}*head, *head2, *head3, *temp;
int insert(string val, int div) 
{
   if(div==1)
   {
      Node* ptr = new Node();
      ptr->data = val;
      ptr->next = NULL;
      if (head==NULL)
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
   else if(div==2)
   {
      Node* ptr = new Node();
      ptr->data = val;
      ptr->next = NULL;
      if (head2==NULL)
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
   return 0; 
}
int display(int div) 
{
   Node* ptr;
   if(div==1)
   {
      ptr = head;
   }
   else if(div==2)
   {
      ptr = head2;
   }
   while (ptr != NULL) 
   {
      cout<< ptr->data <<", ";
      ptr = ptr->next;
   }
   return 0;
}
int Delete(string val, int div)
{
   int flag=0;
   Node *ptr1;
   if(div==1)
   {
      ptr1 = head;
      while (ptr1->next->data!=val) 
      {
         if(ptr1->next->next==NULL)
         {
            flag=1;
            break;
         }
         else if(val==head->data)
         {
            head=ptr1->next;
         }
         ptr1 = ptr1->next;
      }
      if(flag==1)
      {
         ptr1->next=NULL;
      }
      else
      {
         ptr1->next=ptr1->next->next;
      }
   }
   if(div==2)
   {
      ptr1 = head2;
      while (ptr1->next->data!=val) 
      {
         if(ptr1->next->next==NULL)
         {
            flag=1;
            break;
         }
         else if(val==head2->data)
         {
            head2=ptr1->next;
         }
         ptr1 = ptr1->next;
      }
      if(flag==1)
      {
         ptr1->next=NULL;
      }
      else
      {
         ptr1->next=ptr1->next->next;
      }
   }
   cout<<"linked list:";
   display(div);
   return 0;
}
int main() 
{
   Node* ptr;
   string s;
   int choice, flag, div;
   head=NULL;
   cout<<"########################################## Welcome to Pinnacle Group #########################################\n";
   flag=0;
   while(flag==0)
   {
      cout<<"\nEnter Choice:\n1. Insert\n2. Display\n3. Delete\n4. Concatenate both lists\n5. Exit\n-->";
      cin>>choice;
      switch (choice)
      {
      case 1:  cout<<"\nFirst name should be President.\n";
               cout<<"Enter name: ";
               cin>>s;
               cout<<"\nWhich division ? : ";
               cin>>div;
               insert(s,div);
               cout<<"Press Q to terminate.\n";
               while(ptr!=NULL)
               {
                  cout<<"\tEnter name:";
                  cin>>s;
                  if(s=="Q"||s=="q")
                  {
                     break;
                  }
                  else
                  {
                     insert(s,div);
                  }
               }
               break;
      case 2:  cout<<"Linked List:";
               cout<<"Which division ? :";
               cin>>div;
               display(div);
               break;
      case 3:  cout<<"Enter name to be deleted:";
               cin>>s;
               cout<<"Which division ? :";
               cin>>div;
               Delete(s,div);
               break;
      case 4:  flag=1;
               break; 
      default: cout<<"Enter valid choice!";
               break;
      }
   }
   return 0;
}