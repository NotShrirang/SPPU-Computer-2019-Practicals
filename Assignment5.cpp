// construct exp tree from prefix exp, traverse the tree in postfix in non recursive order and finally delete entire tree.
#include <iostream>
#include <string.h>
using namespace std;
#define SIZE 100
struct Node
{
    char data;
    Node *left;
    Node *right;
} *head = NULL;
class stack
{
    struct Node *Stack[SIZE];
    int top;

public:
    int push(Node *item);
    Node *pop();
    stack()
    {
        top = -1;
    }
};
int stack::push(Node *item)
{
    if (top == SIZE - 1)
    {
        cout << "Stack is Full\n";
        return (0);
    }
    else
    {
        top = top + 1;
        Stack[top] = item;
    }
    return (1);
}
Node *stack::pop()
{
    Node *temp;
    if (top == -1)
    {
        cout << "Empty Stack:\n";
        return (0);
    }
    else
    {
        temp = Stack[top];
        top = top - 1;
    }
    return (temp);
}
Node *createNode(char ch, int isOperator)
{
    Node *ptr = new Node();
    if (isOperator == 0)
    {
        ptr->data = ch;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if (isOperator == 1)
    {
        head = ptr;
        ptr->data = ch;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    return ptr;
}
void displayIn(Node *root) // in order way.
{
    if (root != NULL)
    {
        displayIn(root->left);
        cout << root->data;
        displayIn(root->right);
    }
}
void displayPost(Node *root) // post order way.
{
    if (root != NULL)
    {
        displayPost(root->left);
        displayPost(root->right);
        cout << root->data;
    }
}
void deleteTree(Node *root)
{
    if (root != NULL)
    {
        deleteTree(root->right);
        deleteTree(root->left);
        free(root);
    }
}
int main()
{
    int choice;
    Node *temp;
    stack st;
    char exp[30];
    char ch;
    int i = 0;
    cout << "Enter exp in pre-fix format :";
    cin >> exp;
    i = strlen(exp) - 1;
    while (i >= 0)
    {
        ch = exp[i];
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9')
        {
            temp = createNode(ch, 0);
            st.push(temp);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            temp = createNode(ch, 1);
            temp->left = st.pop();
            temp->right = st.pop();
            st.push(temp);
        }
        i--;
    }
    cout << "In order traversal : ";
    displayIn(head);
    cout << "\nPost order traversal : ";
    displayPost(head);
    deleteTree(head);
}