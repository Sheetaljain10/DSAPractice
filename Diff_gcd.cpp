#include <iostream>
using namespace std;

// using recursion
int gcd1(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else if (b > a)
    {
        return gcd1(b, a);
    }
    else
    {
        return gcd1(b, a % b);
    }
}

// using for loop
int gcd2(int a, int b)
{
    int gcd;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}

// using while loop
int gcd3(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    else
    {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }
}

// using temp variable.
int gcd4(int a, int b)
{
    int temp;
    if (a == 0)
    {
        return b;
    }
    else
    {
        while (b != 0)
        {
            temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

void gcd(int a, int b)
{
    int ch, res;
    cout << "\nEnter choice: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        res = gcd1(a, b);
        break;
    case 2:
        res = gcd2(a, b);
        break;
    case 3:
        res = gcd3(a, b);
        break;
    case 4:
        res = gcd4(a, b);
        break;
    case 5:
        exit(0);
    }
    cout << "\nGCD: " << res;
}

int main()
{
    int a, b;
    cout << "Enter a: ";
    cin >> a;
    cout << "\nEnter b: ";
    cin >> b;
    gcd(a, b);

    return 0;
}
