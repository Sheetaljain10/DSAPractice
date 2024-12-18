// FCFS without arrival time.
#include <bits/stdc++.h>
using namespace std;

struct fcfs
{
    int ps;
    int bt;
    int at;
    float tat;
    float wt;
};
sort(fcfs[], int);
int main()
{
    int n, i, j, t[100], temp = 0;
    float avwt, avtat;
    cout << "\nEnter number of processes:";
    cin >> n;
    fcfs a[n];
    for (i = 0; i < n; i++)
    {
        a[i].ps = i + 1;
        cout << "Process " << a[i].ps << " Enter burst time and arrival: ";
        cin >> a[i].bt >> a[i].at;
    }
    sort(a, n);
    cout << "PROCESSES\tBURST TIME\tTURNAROUND TIME\tWAITING TIME" << endl;
    for (i = 0; i < n; i++)
    {
        t[i] = temp + a[i].bt;
        temp = t[i];
        a[i].tat = t[i] - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;
        avtat += a[i].tat;
        avwt += a[i].wt;
        cout << "p[" << i + 1 << "]\t" << a[i].bt << "\t" << a[i].tat << "\t" << a[i].wt << endl;
    }
    cout << "Average waiting time: " << avwt / n << endl;
    cout << "Average turn around time: " << avtat / n;
}

void sort(fcfs a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[i].at > a[j].at)
            {
                fcfs temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}