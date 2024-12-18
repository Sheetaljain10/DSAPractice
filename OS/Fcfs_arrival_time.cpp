// FCFS without arrival time.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1000, i, j;
    float avwt, avtat;
    cout << "\nEnter number of processes:";
    cin >> n;
    int wt[n], bt[n], tat[n];

    cout << "Enter burst time for:";
    for (i = 0; i < n; i++)
    {
        cout << "p[" << i + 1 << "]: ";
        cin >> bt[i]; // burst times input by user
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }

    cout << "PROCESSES\tBURST TIME\tTURNAROUND TIME\tWAITING TIME" << endl;
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "p[" << i + 1 << "]\t" << bt[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }
    avtat /= n;
    avwt /= n;
    cout << "Average waiting time: " << avwt << endl;
    cout << "Average turn around time: " << avtat;
}