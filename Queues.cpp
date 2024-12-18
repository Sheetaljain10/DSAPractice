// QUEUE FOLLOWS FIRST IN FIRST OUT.
//  IMPLEMENTNG QUEUES USING ARRAYS.
//  IMPLEMENTING USING LINKED LISTS : INSERT_AT_END , DELETE_AT_BEG.
//  IMPLEMENTING USING STACK : 2 STACKS , 1ST STACK [FIRST-IN] FOR INSERTION, 2ND STACK [FIRST-OUT] FOR DELETION.
#include <iostream>
using namespace std;
#define sz 10 // NO SEMICOLON.
int a[sz], front = -1, rear = -1;
class queue
{
    int *arr;
    int front, rear;

public:
    queue()
    {
        arr = new int(sz);
        front = -1;
        rear = -1;
    }

    // INSERTION AT END OF QUEUE
    void enqueue(int item)
    {
        if (rear == sz - 1)
        {
            cout << "\nQueue is full.";
        }
        else
        {
            if (front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                arr[rear] = item;
            }
            else
            {
                arr[++rear] = item;
            }
        }
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nQUEUE IS EMPTY!!";
        }
        else
        {
            if (front == rear)
            {
                cout << arr[front] << " IS DELETED!!";
                front = -1;
                rear = -1;
            }
            else
            {
                cout << arr[front++] << " IS DELETED";
            }
        }
    }

    int peek()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nQUEUE IS EMPTY!!";
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool empty()
    {
        if (front == -1 && rear == -1 && front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\n QUEUE IS EMPTY!!";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

void insertlq(int item)
{
    if (rear == sz - 1)
    {
        cout << "STACK IS FULL!!";
    }
    else
    {
        if (front == rear == -1)
        {
            front = rear = 0;
            a[rear] = item;
        }
        else
        {
            a[++rear] = item;
        }
    }
}

void deletelq()
{
    if (front == rear == -1)
    {
        cout << "\nQUEUE IS EMPTY";
    }
    else
    {
        if (front == rear)
        {
            cout << "\n"
                 << a[front] << " IS DELETED";
            rear = front = 0;
        }
        else
        {
            int x = a[front];
            cout << "\n"
                 << a[front--] << " IS DELETED";
        }
    }
}

void display()
{
    if (front == rear == -1)
    {
        cout << "\nQUEUE IS EMPTY!!";
    }
    else
    {
        cout << "\nELEMENTS OF QUEUE: ";
        for (int i = front; i <= rear; i++)
        {
            cout << a[i] << " ";
        }
    }
}
int main()
{
    queue p; // CLASS WITH DEFAULT CONSTRUCTOR.
    int c, val;
    cout << "QUEUE OPERATIONS:\n1] INSERTION.\n2] DELETION.\n3] DISPLAY.\n";

    while (1)
    {
        cout << "\nENTER CHOICE: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "\nENTER VALUE: ";
            cin >> val;
            cout << "\nUSING CLASS [ENTER 1 ELSE 0]: ";
            cin >> c;
            if (c == 1)
            {
                p.enqueue(val);
            }
            else
            {
                insertlq(val);
            }
            break;
        case 2:
            cout << "\nUSING CLASS [ENTER 1 ELSE 0]: ";
            cin >> c;
            if (c == 1)
            {
                p.dequeue();
            }
            else
            {
                deletelq();
            }

            break;
        case 3:
            cout << "\nUSING CLASS [ENTER 1 ELSE 0]: ";
            cin >> c;
            if (c == 1)
            {
                p.display();
            }
            else
            {
                display();
            }
            break;
        case 4:
            exit(0);
        }
    }
}