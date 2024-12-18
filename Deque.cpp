#include <iostream>
#include <deque>
using namespace std;

void display(deque<int> dq)
{
    cout << endl;
    for (int i = 0; i < dq.size() - 1; i++)
    {
        cout << dq[i] << " ";
    }
}
int main()
{
    deque<int> dq;
    dq.push_front(10);
    dq.push_back(11);
    dq.push_front(20);
    cout << "\nSIZE: " << dq.size() << endl;
    dq.push_back(22);
    dq.push_front(30);
    display(dq);
    cout << "\nFRONT ELE: " << dq.front();
    dq.pop_front();
    display(dq);
    cout << "\nFRONT ELE: " << dq.front();
    cout << "\nREAR ELE: " << dq.back();
    dq.pop_back();
    display(dq);
    cout << "\nREAR ELE: " << dq.back();
}
