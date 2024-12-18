// #include <bits/stdc++.h> // HEADER FILE INCLUDES ALL THE REMAINING HEADER FILES.
#include <iostream>
#include <algorithm>
#include <deque>
#define sz 100
using namespace std;

void display(deque<int> dq)
{
    cout << "\nDEQUEUE ELEMENTS: " << endl;
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << " ";
    }
}
void sliding_window(int a[], int n, int k)
{
    // SLIDING WINDOW PROBLEM.
    deque<int> x;
    int m;
    for (int i = 0; i <= n - k; i++)
    {
        m = a[i];
        for (int j = i; j < i + k - 1; j++)
        {
            m = max(m, a[j + 1]);
        }
        x.push_back(m);
    }
    display(x);
}

int main()
{
    int n, a[sz], k;
    cout << "\nENTER N: ";
    cin >> n;
    cout << "\nELEMENTS: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "\nENTER WINDOW SIZE: ";
    cin >> k;
    // int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    sliding_window(a, n, k);
}