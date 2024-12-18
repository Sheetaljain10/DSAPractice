#include <iostream>
#include <ctime>
using namespace std;

void insertsort(int a[], int n)
{
    int i, j, key;
    for (i = 0; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of elements:";
    cin >> n;
    int a[n];
    clock_t start, end;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }
    cout << "\nBefore sorting:";
    print(a, n);

    start = clock();
    insertsort(a, n);
    end = clock();
    double ti = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "\nafter sorting:";
    print(a, n);
    cout << "\nTime taken:" << ti;
    return 0;
}