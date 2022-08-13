#include <bits/stdc++.h>
using namespace std;
#define MAX 10

class cirque
{
    int data[MAX], front, rear;

public:
    cirque()
    {
        rear = front = -1;
    }
    int isempty();
    int isfull();
    void enqueue(int key);
    void dequeue();
    void display();
};
int cirque::isempty()
{
    return (front == -1) ? 1 : 0;
}
int cirque::isfull()
{
    if ((rear == MAX - 1) && (front == 0))
    {
        return true;
    }

    if (rear == front - 1)
    {
        return true;
    }

    return false;
}
void cirque::enqueue(int key)
{
    if (isfull())
    {
        cout << "\nError: Overflow";
        return;
    }

    if (isempty())
    {
        rear = front = 0;
        data[rear] = key;
        return;
    }

    rear = (rear + 1) % MAX;
    data[rear] = key;
}
void cirque::dequeue()
{
    if (isempty())
    {
        cout << "\nError: Underflow";
        return;
    }

    if (front == rear)
    {
        front = rear = -1;
        return;
    }

    front = (front + 1) % MAX;
}
void cirque::display()
{
    cout << "\n";
    if (isempty())
    {
        cout << "Queue is empty";
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        cout << data[i] << " ";
    }
    cout << "\n";
}
int main()
{
    cirque obj;
    int ch, ele;
    do
    {
        cout << "\n1.New Order\n2.Serve Order\n3.Display\n4.Exit\n-->";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter element: ";
            cin >> ele;
            obj.enqueue(ele);
            break;

        case 2:
            obj.dequeue();
            break;

        case 3:
            obj.display();
            break;

        case 4:
            cout << "\nExiting...";
            break;

        default:
            cout << "\nInvalid input";
            break;
        }
    } while (ch != 4);
}