// A book consists of chapters, chapters consists of sections and sections consists of subsections.
// Construct a tree and print the nodes. fiind the time and space requirements of your method.

#include <iostream>
using namespace std;

class node
{
public:
    string name;
    node *next;
    node *down;
    int flag;
    int level; // level = 0 for root node. level = 1 for chapters. level 2 = sections. level = 3 for subsections.
    node()
    {
        cout << "Enter name : ";
        cin >> name;
        down = NULL;
        next = NULL;
        flag = 0;
        level = 0;
    }
} *head, *temp;
int checkBook(node *temp, node *ptr)
{
    int depth = 4;
    int i = 0;
    while(temp->down!=NULL)
    {
        if(i<4)
        {
            temp = temp->down;
            i=i+1;
        }
        else
        {
            break;
        }
    }


}
int insert(node *ptr)
{
    if (head == NULL)
    {
        head = ptr;
        ptr->next=NULL;
        return 1;
    }
    else
    {
        temp = head;
        checkBook(temp, ptr);
        return 1;
    }
    return 0;
}
int main()
{
    node *temp = NULL;
    cout << "#######################################################\n";
    node *book = new node();
    insert(book);
    node *ptr = new node();
    insert(ptr);
}
