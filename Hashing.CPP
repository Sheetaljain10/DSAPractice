#include <iostream>
using namespace std;

void hashing(int table[], int tsize, int arr[], int n)
{
    for (int k = 0; k < tsize; k++)
    {
        table[k] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int h = arr[i] % tsize;
        if (table[h] == -1)
        {
            table[h] = arr[i];
        }
        else
        {
            for (int j = 0; j < tsize; j++)
            {
                int t = (h + j) % tsize;
                if (table[t] == -1)
                {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    cout << "FINAL HASH TABLE:\n";
    for (int i = 0; i < tsize; i++)
    {
        cout << "H[" << i << "]= " << table[i] << "\t";
    }
}

int main()
{
    int arr[7] = {11, 23, 14, 12, 35, 45, 55};
    int table[7];
    int n = 7, tsize = 7;

    hashing(table, tsize, arr, n);
}
