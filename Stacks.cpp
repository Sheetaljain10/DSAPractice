#include <iostream>
#include <stack>
using namespace std;

void rev_string()
{
    string s, word;
    stack<string> p;
    cout << "\nEnter String:";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        word = "";
        //'' FOR WORDS IN STRING WHILE "" FOR WHOLE STRING.
        while (s[i] != ' ')
        {
            word += s[i++];
        }
        p.push(word);
    }
    for (int j = 0; j < s.length(); j++)
    {
        if (p.empty())
            break;
        else
        {
            cout << p.top() << " ";
            p.pop();
        }
    }
}
void insert_at_bottom(stack<int> &st, int a)
{
    if (st.empty())
    {
        st.push(a);
        return;
    }
    else
    {
        int top_ele = st.top();
        st.pop();
        insert_at_bottom(st, a);
        st.push(top_ele);
    }
}
void rev_stack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    else
    {
        int ele = st.top();
        st.pop();
        rev_stack(st);
        insert_at_bottom(st, ele);
    }
}

int post_evaluate(string s)
{
    // NO VALIDATION
    stack<int> x;
    int op1, op2;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            x.push(s[i] - '0');
        }
        else
        {
            op2 = x.top();
            x.pop();
            op1 = x.top();
            x.pop();
            switch (s[i])
            {
            case '+':
                x.push(op1 + op2);
                break;
            case '-':
                x.push(op1 - op2);
                break;
            case '*':
                x.push(op1 * op2);
                break;
            case '/':
                x.push(op1 / op2);
                break;
            case '%':
                x.push(op1 % op2);
                break;
            default:
                cout << "\nINVALID EXPRESSION";
                break;
            }
        }
    }
    return x.top();
}

int evaluate_prefix(string s)
{
    stack<int> x;
    int op1, op2;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (isdigit(s[i]))
        {
            x.push(s[i] - '0');
        }
        else
        {
            // MAJOR DIFFERENCE.
            op1 = x.top();
            x.pop();
            op2 = x.top();
            x.pop();
            switch (s[i])
            {
            case '+':
                x.push(op1 + op2);
                break;
            case '-':
                x.push(op1 - op2);
                break;
            case '*':
                x.push(op1 * op2);
                break;
            case '/':
                x.push(op1 / op2);
                break;
            case '%':
                x.push(op1 % op2);
                break;
            default:
                cout << "\nINVALID EXPRESSION";
                break;
            }
        }
    }
    return x.top();
}
int preced(char c)
{
    int p;
    switch (c)
    {
    case '^':
        p = 3;
        break;
    case '*':
    case '/':
        p = 2;
        break;
    case '+':
    case '-':
        p = 1;
        break;
    default:
        p = 0;
        break;
    }
    return p;
}
string ptop(string s)
{
    stack<char> x;
    string p = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        switch (c)
        {
        case '(':
            x.push(c);
            break;
        case ')':
            while (!x.empty() && x.top() != '(')
            {
                p += x.top();
                x.pop();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            while (preced(c) <= preced(x.top()))
            {
                p += x.top();
                x.pop();
            }
            x.push(c);
            break;
        default:
            p += c;
            break;
        }
    }
    return p;
}

string bal_par(string s)
{
    stack<char> p;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            p.push(s[i]);
        }
    }
    for (int j = 0; j < s.length(); j++)
    {
        if (p.top() == ']' || p.top() == '}' || p.top() == ')')
        {
            p.pop();
        }
    }
    cout << p.empty() << '\n';
    if (p.empty())
    {
        return "Balanced";
    }
    else
    {
        return "NOT BALANCED";
    }
}
void display(stack<int> p)
{
    if (p.empty())
    {
        cout << "\nStack is empty!!";
    }
    else
    {
        cout << "\nSTACK ELEMENTS: ";
        for (int i = p.size() - 1; i >= 0; i--)
        {
            cout << p.top() << " ";
            p.pop();
        }
    }
}
int main()
{
    int c, val;
    char ch;
    string s;
    stack<int> p;
    cout << "\nOPERATIONS ON STACKS:\n1] PUSH / POP\n2] Reverse string\n3] Reverse a stack\n4] Evaluating postfix Exp.\n5] Evaluating prefix Exp.\n6] Prefix to postfix.\n7] Display stack.\n8] BALANCED PARANTHESIS.\n9]EXIT.";
    while (1)
    {
        cout << "\nCHOICE:";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "Enter 'a' to push and 'b' to pop: ";
            cin >> ch;
            if (ch == 'a')
            {
                cout << "Enter value: ";
                cin >> val;
                p.push(val);
            }
            else if (ch == 'b')
            {
                // POP FUNCTION IS VOID TYPE.
                p.pop();
            }
            else
            {
                cout << "\nWRONG CHOICE!!";
            }
            break;
        case 2:
            rev_string();
            break;
        case 3:
            rev_stack(p);
            break;
        case 4:
            cout << "\nEnter postfix expressiopn: ";
            cin >> s;
            cout << "\nRESULT: " << post_evaluate(s);
            break;
        case 5:
            cout << "\nEnter prefix expression: ";
            cin >> s;
            cout << "\nRESULT:" << evaluate_prefix(s);
            break;
        case 6:
            cout << "\nEnter infix expression: ";
            cin >> s;
            cout << "\nEquivalent postfix: " << ptop(s);
            break;

        case 7:
            display(p);
            break;

        case 8:
            cout << "\nENTER STRING: ";
            cin >> s;
            cout << "\nSTRING IS " << bal_par(s);
            break;
        case 9:
            exit(0);
        }
    }
}