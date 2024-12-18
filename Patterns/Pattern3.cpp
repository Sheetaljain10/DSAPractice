#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int rows = 5, column = 5;

    cout << "\n ENTER ROWS: ";
    cin >> rows;
    int row3 = 4;
    for (int i = 0; i < row3 * 2 - 1; i++)
    {
        for (int j = 0; j < row3 * 2 - 1; j++)
        {
            if (i == 0 || j == 0 || i == (row3 * 2 - 2) || j == (row3 * 2 - 2))
            {
                cout << row3;
            }
            else if (i == 1 || j == 1 || i == (row3 * 2 - 3) || j == (row3 * 2 - 3))
            {
                cout << row3 - 1;
            }
            else if (i == 2 || j == 2 || i == (row3 * 2 - 4) || j == (row3 * 2 - 4))
            {
                cout << row3 - 2;
            }
            else
            {
                cout << row3 - 3;
            }
        }
        cout << endl;
    }
    cout << endl;

    int row2 = 4;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < row2; j++)
        {
            if (i == 0 || i == row2 - 1 || j == 0 || j == row2 - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << endl;

    int s3 = (rows - 1) * 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < s3; k++)
        {
            cout << " ";
        }
        s3 -= 2;
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    s3 = 0;
    for (int i = 0; i < rows - 1; i++)
    {
        s3 = s3 + 2;
        for (int j = 0; j < rows - 1 - i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < s3; k++)
        {
            cout << " ";
        }
        for (int l = 0; l < rows - 1 - i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    int s2 = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < s2; k++)
        {
            cout << " ";
        }
        s2 = s2 + 2;
        for (int l = 0; l < rows - i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        s2 = s2 - 2;
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < s2; k++)
        {
            cout << " ";
        }
        for (int l = 0; l <= i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    int row1 = 5;
    char p3 = 'E';
    for (int i = 0; i < row1; i++)
    {
        p3 = p3 - i;
        for (int j = 0; j <= i; j++)
        {
            cout << p3++ << " ";
        }
        p3 = 'E';
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rows - 1; i++)
    {
        char p2 = 'A';
        for (int j = 0; j < rows - 1 - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << p2++;
        }
        p2 - 1;
        for (int l = 0; l < i; l++)
        {
            cout << --p2;
        }
        cout << endl;
    }
    cout << endl;
    char p1 = 'A';
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << p1 << " ";
        }
        p1++;
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        char ch = 'A';
        for (int j = 0; j < rows - i; j++)
        {
            cout << ch++ << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        char p = 'A';
        for (int j = 0; j <= i; j++)
        {
            cout << p++ << " ";
        }
        cout << endl;
    }
    cout << endl;
    int c = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << c++ << " ";
        }
        cout << endl;
    }
    cout << endl;
    int s = 2 * (rows - 1);
    for (int i = 0; i < rows - 1; i++)
    {
        s -= 2;
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        for (int l = 0; l < s; l++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << k + 1;
        }
        cout << endl;
    }
    cout << endl;
    int start = 1;
    for (int i = 0; i <= rows; i++)
    {
        if (!(i % 2))
        {
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = 0; j < rows - 1 - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }
        for (int l = 0; l < i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < rows - i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < rows - i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < rows - i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < rows - i - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1;
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        cout << "\n";
    }

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}