#include <iostream>
#include <ctime>
using namespace std;

// Heapify: making largest number as root.
void heapify(int a[], int n, int i)
{

    int large = i; // both are indices of largest number.
    int left = 2 * i + 1;
    int rgt = 2 * i + 2;

    // No for loop used because recursive function used.
    if (left < n && a[left] > a[large])
    {
        large = left;
    }

    if (rgt < n && a[rgt] > a[large])
    {
        large = rgt;
    }

    // if large = i , there is no need of heapify.
    if (large != i)
    {
        swap(a[i], a[large]);
        heapify(a, n, large);
    }
}

// Does similar as selection sort
// i.e.,throws largest number to end of array and heapifies rest numbers.
void heapsort(int a[], int n)
{
    int i;
    for (i = (n / 2 - 1); i >= 0; i--)
    {
        heapify(a, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
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
    cout << "Enter number of nodes:";
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
    heapsort(a, n);
    end = clock();
    double ti = (double)(end - start) / CLOCKS_PER_SEC;

    cout << "\nafter sorting:";
    print(a, n);
    cout << "\nTime taken:" << ti;
    return 0;
}
