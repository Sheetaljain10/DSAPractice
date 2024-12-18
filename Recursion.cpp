// RECURSION STRUCTURE INVOLVES TWO PARTS : 1 BASE CASE AND 2 RECURSIVE CASE.

#include <iostream>
#include <string>
using namespace std;

string keypad_arr[] = {"", "./", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int power(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    else
    {
        return n * power(n, p - 1);
    }
}

int fact(int n)
{
    if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int fibo(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
bool sort_arr(int *a, int n)
{
    if (n == 1)
    {
        return true;
    }
    else
    {
        return (a[0] < a[1] && sort_arr(a + 1, n - 1));
    }
}

void ascd(int n)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    ascd(n - 1);
    cout << n << " ";
}

void descend(int n)
{
    if (n == 1)
    {
        cout << "1 ";
        return;
    }
    cout << n << " ";
    descend(n - 1);
}

int first_occur(int s[], int i, int n, int a)
{
    if (i == n)
    {
        return -1;
    }
    if (s[i] == a)
    {
        return i;
    }
    return first_occur(s, i + 1, n, a);
}

int last_occur(int s[], int n, int i, int a)
{

    if (i == n)
    {
        return -1;
    }
    int last_one = last_occur(s, n, i + 1, a);

    if (last_one != -1)
    {
        return last_one;
    }
    if (s[i] == a)
    {
        return i;
    }
    return -1;
}

void rev_str(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    rev_str(s.substr(1));
    cout << s[0];
}

void replace_pi(string s)
{
    if (s.length() == 0)
    {
        return;
    }
    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replace_pi(s.substr(2));
    }
    else
    {
        cout << s[0];
        replace_pi(s.substr(1));
    }
}

void TOH(int n, char s, char t, char d)
{
    if (n > 0)
    {
        TOH(n - 1, s, t, d);
        cout << "Move disk " << n << " from rod " << s << " to rod " << d << endl;
        TOH(n - 1, t, s, d);
    }
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

void rem_dup(string s)
{
    // CAN BE DONE WITH RETURN TYPE STRING.
    if (s.length() == 0)
    {
        return;
    }
    string p = s.substr(1);
    if (s[0] == p[0])
    {
        rem_dup(p);
    }
    else
    {
        cout << s[0];
        rem_dup(p);
    }
}

string move_x(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    string p = s.substr(1);
    if (s[0] == 'x')
    {
        return move_x(p) + 'x';
    }
    else
    {
        return s[0] + move_x(p);
    }
}

void sub_seq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    string p = s.substr(1);
    sub_seq(p, ans);
    sub_seq(p, ans + s[0]);
}

void sub_seq2(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    int code = s[0];
    string p = s.substr(1);
    sub_seq2(p, ans);
    sub_seq2(p, ans + s[0]);
    sub_seq2(p, ans + to_string(code));
}
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string p = s.substr(1);
    string code = keypad_arr[ch - '0'];
    for (int i = 0; i < code.length(); i++)
    {
        keypad(p, ans + code[i]);
    }
}

void permut(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string p = s.substr(0, i) + s.substr(i + 1);
        permut(p, ans + c);
    }
}

int count_path(int a, int b)
{
    if (a == b)
    {
        return 1;
    }
    if (a > b)
    {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++) // 6 denotes max step that can be taken.
    {
        count += count_path(a + i, b);
    }
    return count;
}

int path_2d(int n, int i, int j)
{
    if (i == n - 1 || j == n - 1)
    {
        return 1;
    }
    if (i >= n && j >= n)
    {
        return 0;
    }
    return path_2d(n, i + 1, j) + path_2d(n, i, j + 1);
}

int tiling(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    return tiling(n - 1) + tiling(n - 2);
}

int FPP(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    return FPP(n - 1) + FPP(n - 2) * (n - 1); // NUMBER OF WAYS TO PAIR = N-1.
}

int knapsack(int w, int n, int wt[], int v[])
{
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return knapsack(w, n - 1, wt, v);
    }

    return max(knapsack(w - wt[n - 1], n - 1, wt, v) + v[n - 1], knapsack(w, n - 1, wt, v));
}
int main()
{
    int c, n, a, b[100], d[100];
    string s, k, l;
    cout << "RECURSION\n1] POWER.\n2] FACTORIAL OF NUM.\n3] FIBONACCI SERIES.\n4] ARRAY SORTED/NOT\n5] Ordered display of N.\n6] First and Last Occurance in array.\n7] REVERSE A STRING.\n8] PI to 3.14.\n9] TOWER OF HANIO.\n10] GCD OF NUMBERS.\n11] Remove all following duplicates.\n12] MOVE ALL X TO END.\n13] SUBSTRINGS OF STRING.\n14] SUBSTRINGS WITH ASCII.\n15] ALL PERMUTATIONS OF STRING IN KEYPAD.\n16] PERMUTATIONS OF STRING.\n17] COUNT PATH B/W 2 NUMBERS.\n18] COUNT PATHS IN 2-D MAZE.\n19] TILING PROBLEAM [2xN , 2x1].\n20] FRIEND PAIRING.\n21] 0/1 KNAPSACK PROBLEM.";
    cout << "\nEnter choice: ";
    cin >> c;
    switch (c)
    {
    case 1:
        cout << "\nENTER NUMBER AND POWER: ";
        cin >> n >> a;
        cout << "\nResult: " << power(n, a);
        break;
    case 2:
        cout << "\nENTER N:";
        cin >> n;
        cout << "\nFACTORIAL OF N: " << fact(n);
        break;
    case 3:
        "\nENTER N:";
        cin >> n;
        cout << fibo(n);
        break;
    case 4:
        cout << "\nEnter N: ";
        cin >> n;
        cout << "\nEnter array: ";
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        if (sort_arr(b, n) == true)
        {
            cout << "\nSORTED";
        }
        else
        {
            cout << "\nNOT SORTED";
        }
        break;
    case 5:
        cout << "\nENTER N: ";
        cin >> n;
        cout << "\n1]ASCENDING.\n2]DESCENDING.\n Enter choice: ";
        cin >> a;
        if (a == 1)
        {
            ascd(n);
        }
        else
        {
            descend(n);
        }
        break;
    case 6:
        cout << "\nEnter N: ";
        cin >> n;
        cout << "\nEnter elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << "\nEnter number to search: ";
        cin >> a;
        cout << "\nFirst occurance at : " << first_occur(b, 0, n, a) + 1;
        cout << "\nLast occurance at : " << last_occur(b, n, 0, a) + 1;
        break;
    case 7:
        cout << "\nEnter string: ";
        cin >> s;
        cout << "\nREVERSED STRING: ";
        rev_str(s);
        break;
    case 8:
        cout << "\nENTER STRING [with pi]: ";
        cin >> s;
        replace_pi(s);
        break;
    case 9:
        cout << "\nENTER NO. OF DISCS: ";
        cin >> n;
        TOH(n, 'A', 'B', 'C');
        break;
    case 10:
        cout << "\nENTER 2 NUMBERS: ";
        cin >> n >> a;
        cout << "GCD IS: " << gcd(n, a);
        break;
    case 11:
        cout << "\nENTER STRING: ";
        cin >> s;
        cout << "\nNEW STRING: ";
        rem_dup(s);
        break;
    case 12:
        cout << "\nENTER STRING: ";
        cin >> s;
        cout << move_x(s);
        break;
    case 13:
        cout << "\nENTER STRING: ";
        cin >> s;
        sub_seq(s, "");
        break;
    case 14:
        cout << "\nENTER STRING: ";
        cin >> s;
        sub_seq2(s, "");
        break;
    case 15:
        cout << "\nENTER STRING OF TWO NUMBERS IN KEYPAD: ";
        cin >> s;
        keypad(s, "");
        break;
    case 16:
        cout << "\nENTER STRING: ";
        cin >> s;
        permut(s, "");
        break;
    case 17:
        cout << "\nENTER START AND END NUMBERS: ";
        cin >> a >> n;
        cout << "\nNumber of paths: " << count_path(a, n);
        break;
    case 18:
        cout << "\nENTER N: ";
        cin >> n;
        cout << "\nNUMBER OF PATHS: " << path_2d(n, 0, 0);
        break;
    case 19:
        cout << "\nENTER N: ";
        cin >> n;
        cout << "\nNUMBER OF TILES: " << tiling(n);
        break;
    case 20:
        cout << "\nENTER N: ";
        cin >> n;
        cout << "\nNUMBER OF WAYS: " << FPP(n);
        break;
    case 21:
        cout << "\nENTER W: ";
        cin >> a;
        cout << "\nENTER N: ";
        cin >> n;
        cout << "\nENTER WEIGHTS: ";
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << "\nENTER VALUES: ";
        for (int j = 0; j < n; j++)
        {
            cin >> d[j];
        }
        cout << "\nTOTAL VALUE: " << knapsack(a, n, b, d);
        break;
    }
}