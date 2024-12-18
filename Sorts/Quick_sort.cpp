#include <iostream>
#include <ctime>
using namespace std;

int partition(int a[], int l, int h)
{
    int p = a[l], i = l + 1, j = h;
    while (i <= j)
    {
        while (a[i] < p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[l], a[j]);
    return j;
}
void quick(int a[], int l, int h)
{
    if (l < h)
    {
        int p = partition(a, l, h);
        quick(a, l, p - 1);
        quick(a, p + 1, h);
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
    quick(a, 0, n - 1);
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