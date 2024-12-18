#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    int ins[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    // cout << "Enter number of pages: ";
    // cin >> p;
    // int ins[p];
    int i, m, j, s, pf = 0, f = 3, temp[3];
    p = sizeof(ins) / sizeof(ins[0]);
    cout << "\nEnter page numbers:";
    // for (i = 0; i < p; i++)
    // {
    //     cin >> ins[i];
    // }
    for (i = 0; i < f; i++)
    {
        temp[i] = -1;
    }
    cout << "INCOMING\t\tFRAME1\t\tFRAME2\t\tFRAME3\n";
    for (m = 0; m < p; m++)
    {
        s = 0;
        for (j = 0; j < f; j++)
        {
            if (ins[m] == temp[j])
            {
                s++;
                pf--;
            }
        }
        pf++;
        if (pf <= f && s == 0)
        {
            temp[m] = ins[m];
        }
        else if (s == 0)
        {
            temp[(pf - 1) % f] = ins[m];
        }
        cout << "\n"
             << ins[m];
        for (i = 0; i < f; i++)
        {
            if (temp[i] == -1)
            {
                cout << "-\t\t\t";
            }
            else
            {
                cout << temp[i];
            }
        }
    }
    cout << "\nPage faults:" << pf;
    return 0;
}