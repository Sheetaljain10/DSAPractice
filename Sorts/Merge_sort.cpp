#include <iostream>
#include <ctime>
using namespace std;

void combine(int a[], int l, int m, int h)
{
    int i = l, j = m + 1, k = l, c[h];
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = a[j++];
        }
    }
    if (i > m)
    {
        while (j <= h)
        {
            c[k++] = a[j++];
        }
    }
    if (j > h)
    {
        while (i <= m)
        {
            c[k++] = a[i++];
        }
    }
    for (i = 0; i <= h; i++)
    {
        a[i] = c[i];
    }
}

void split(int a[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        split(a, l, m);
        split(a, m + 1, h);
        combine(a, l, m, h);
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    clock_t start, end;
    double time1;
    cout << "Enter size:";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    cout << "\nBEFORE SORTING:";
    print(a, n);
    start = clock();
    // bubblesort(a,n);
    split(a, 0, n - 1);
    end = clock();
    time1 = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "\nSORTED ARRAY:\n";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\nprocessor time:" << time1;

    return 0;
}