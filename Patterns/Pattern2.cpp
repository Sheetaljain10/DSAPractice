#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "enter rows:";
    cin >> n;
    cout << "Enter column:";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n || j == 0 || j == m)
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
    return 0;
}