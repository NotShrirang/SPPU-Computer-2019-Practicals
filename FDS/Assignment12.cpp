#include <iostream>
#define MAX 10
using namespace std;

struct DQ
{
    int front, rear, val;
};
class Deque
{
    int deque[MAX];
    struct DQ Q;

public:
    Deque()
    {
        Q.front = -1;
        Q.rear = -1;
    }
    int isFull();
    int isEmpty();
    int addFront(int val);
    int addRear(int val);
    int removeFront();
    int removeRear();
    int Display();
    int size();
};
int Deque::isFull() // Returns 1 if full.
{
    if (Q.rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Deque::isEmpty() // Returns 1 if empty.
{
    if (Q.front < 0 || Q.front > Q.rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int Deque::addFront(int val) // Returns rear pointer.
{
    if (isFull() == 1)
    {
        cout << "Queue is full. Delete an element to add new element.";
        return 0;
    }
    else if (isEmpty() == 1)
    {
        Q.rear = Q.rear + 1;
        Q.front = Q.front + 1;
        deque[Q.rear] = val;
        return Q.rear;
    }
    else if ((Q.rear == 0) && (Q.front == 0))
    {
        deque[1] = deque[0];
        Q.rear++;
        deque[0] = val;
        return Q.rear;
    }
    else
    {
        for (int i=Q.rear+1; i>Q.front; i--)
        {
            deque[i] = deque[i-1];
        }
        deque[Q.front] = val;
        Q.rear++;
        return Q.rear;
    }
}
int Deque::addRear(int val) // Returns rear pointer.
{
    if (isFull() == 1)
    {
        cout << "Queue is full. Delete an element to add new element.";
        return 0;
    }
    else if (isEmpty() == 1)
    {
        Q.rear = Q.rear + 1;
        Q.front = Q.front + 1;
        deque[Q.rear] = val;
        return Q.rear;
    }
    else
    {
        Q.rear = Q.rear + 1;
        deque[Q.rear] = val;
        return Q.rear;
    }
}
int Deque::removeFront() // Returns value deleted from front
{
    if (isEmpty() == 1)
    {
        cout << "Queue is empty. Add an element to delete an element.";
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
        Q.val = deque[Q.front];
        Q.front = Q.front + 1;
        return Q.val;
    }
}
int Deque::removeRear() // Returns value deleted from rear.
{
    if (isEmpty() == 1)
    {
        cout << "Queue is empty. Add an element to delete an element.";
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
        Q.val = deque[Q.rear];
        Q.rear = Q.rear - 1;
        return Q.val;
    }
}
int Deque::Display() // Just prints whole queue. Doesn't return anything.
{
    cout << "\nDeque : ";
    for (int i = Q.front; i <= Q.rear; i++)
    {
        cout << deque[i] << " ";
    }
    return 0;
}
int Deque::size() // Returns size of queue.
{
    int i = Q.front;
    while (i <= Q.rear)
    {
        i++;
    }
    return i;
}
int main()
{
    int x, choice;
    Deque Q;
    while (1)
    {
        cout << "\nEnter choice :\n";
        cout << "1. Insert at front\n";
        cout << "2. Insert at rear\n";
        cout << "3. Delete from front\n";
        cout << "4. Delete from rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "--> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n\nEnter element: ";
            cin >> x;
            Q.addFront(x);
            break;
        case 2:
            cout << "\n\nEnter element: ";
            cin >> x;
            Q.addRear(x);
            break;
        case 3:
            cout << "\n\nDeleting element from front...";
            Q.removeFront();
            break;
        case 4:
            cout << "\n\nDeleting element from rear...";
            Q.removeRear();
            break;
        case 5:
            cout << "\n\nDisplay deque...";
            Q.Display();
            break;
        case 6:
            cout << "\n\nExiting the program...";
            exit(1);
            break;
        }
    }
    return 0;
}