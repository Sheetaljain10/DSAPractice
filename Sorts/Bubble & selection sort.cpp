#include <iostream>
#include <ctime>
using namespace std;

void bubblesort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectsort(int a[], int n)
{
    int i, j, mi;
    for (int i = 0; i < n - 1; i++)
    {
        mi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[mi])
            {
                mi = j;
            }
        }
        if (mi != i)
        {
            int temp = a[mi];
            a[mi] = a[i];
            a[i] = temp;
        }
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
    start = clock();
    bubblesort(a, n);
    // selectsort(a, n);
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