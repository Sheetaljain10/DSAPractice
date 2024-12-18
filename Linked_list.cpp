// Linked list concepts in C++.
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *insertatbeg(node *&head, int val)
{
    node *p = new node(val);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    return head;
}

node *insertatend(node *&head, int val)
{
    node *p = new node(val);
    if (head == NULL)
    {
        head = p;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
    return head;
}

void search(node *&head, int key)
{
    if (head == NULL)
    {
        cout << "\nLL doesn't exist!! ";
    }
    else
    {
        node *temp = head;
        while (temp != NULL && temp->data != key)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "\nElement not found in LL!!";
        }
        else
        {
            cout << "\nElement is found";
        }
    }
}

node *insertbefore(node *&head, int val, int key)
{
    node *p = new node(val);
    if (head == NULL)
    {
        cout << "\nLL is empty and No key!!";
    }
    else
    {
        if (key == head->data)
        {
            p->next = head;
            head = p;
        }
        else
        {
            node *temp = head, *prev;
            while (temp != NULL && temp->data != key)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "\nKEY NOT FOUND";
            }
            else
            {
                prev->next = p;
                p->next = temp;
            }
        }
    }
    return head;
}

node *insertafter(node *&head, int val, int key)
{
    node *p = new node(val);
    if (head == NULL)
    {
        cout << "\nLL is Empty!!";
    }
    else
    {
        if (head->data == key)
        {
            head->next = p;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL && temp->data != key)
            {
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "\nKey not found!!";
            }
            else
            {
                p->next = temp->next;
                temp->next = p;
            }
        }
    }
    return head;
}

node *delete_ele(node *&head, int key)
{
    node *prev, *temp = head;
    if (head == NULL)
    {
        cout << "\nLL doesn't exist!!";
    }
    else
    {
        if (head->data == key)
        {
            // Deleting element at beginning.
            head = head->next;
        }
        else
        {
            while (temp != NULL && temp->data != key)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                cout << "\nElement not found";
            }
            else
            {
                prev->next = temp->next;
            }
        }
        cout << "\n"
             << temp->data << " is deleted!! ";
        free(temp);
    }
    return head;
}

node *reverse_ll(node *&head)
{
    node *temp, *cur = NULL;
    if (head == NULL)
    {
        cout << "\nLL is empty!!";
        return head;
    }
    else
    {
        while (head != NULL)
        {
            temp = head->next;
            head->next = cur;
            cur = head;
            head = temp;
        }
        return cur;
    }
}

node *revknodes(node *&head, int k)
{
    node *temp = head, *prev;
    if (head == NULL)
    {
        cout << "\nLL is empty!!";
    }
    else
    {
        if (k > 1)
        {
            for (int i = 0; i < k; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = NULL;
            head = reverse_ll(head);
            prev = head;
            while (prev->next != NULL)
            {
                prev = prev->next;
            }
            prev->next = temp;
        }
    }
    return head;
}
node *make_cycle(node *&head, int pos)
{
    node *temp = head, *start_loop;
    int count = 1;
    if (head == NULL || head->next == NULL)
    {
        cout << "\nCycle not possible";
    }
    else
    {
        while (temp->next != NULL)
        {
            if (pos == count++)
            {
                start_loop = temp;
            }
            temp = temp->next;
        }
        temp->next = start_loop;
    }
    return head;
}

// Floyd's cycle finding Algorithm / Hare and tortoise algorithm.
void detect_loop(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "\nCycle doesn't exist!!";
    }
    else
    {
        node *slow = head, *fast = head, *detect;
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                break;
            }
        }
        if (fast->next == NULL)
        {
            detect = NULL;
        }
        else
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            detect = slow;
        }
        if (detect == NULL)
        {
            cout << "\nCycle doesn't exist !!";
        }
        else
        {
            cout << "\nCycle Exists !! \nElements: ";
            cout << detect->data << " ";
            detect = detect->next;
            while (detect != slow)
            {
                cout << detect->data << " ";
                detect = detect->next;
            }
        }
    }
}

node *delete_loop(node *&head)
{
    node *slow = head, *fast = head;
    if (head == NULL && head->next == NULL)
    {
        cout << "\nCycle doesn't exist!!";
    }
    else
    {
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (fast->next != NULL)
        {
            slow = head;
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
    return head;
}

int length(node *&head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *kappend(node *&head, int k)
{
    if (head == NULL && head->next == NULL)
    {
        return head;
    }
    else
    {
        if (length(head) > k)
        {
            int l = length(head), count = 0;
            node *temp = head, *new_head, *new_tail;
            while (temp->next != NULL)
            {
                count++;
                if (count == (l - k))
                {
                    new_tail = temp;
                    new_head = temp->next;
                }
                temp = temp->next;
            }
            temp->next = head;
            new_tail->next = NULL;
            return new_head;
        }
        else
        {
            return head;
        }
    }
}
node *odd_even_pos(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "\nLL doesn't exist!!";
    }
    else
    {
        node *even_start = head->next, *odd_pos = head, *even_pos = even_start;
        while (even_pos->next != NULL && odd_pos->next != NULL)
        {
            odd_pos->next = even_pos->next;
            odd_pos = odd_pos->next;
            even_pos->next = odd_pos->next;
            even_pos = even_pos->next;
        }
        if (odd_pos->next == NULL)
        {
            even_pos->next = NULL;
        }
        odd_pos->next = even_start;
    }
    return head;
}
node *merge(node *&head1, node *head2)
{
    node *p1 = head1, *p2 = head2, *p3 = NULL;
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }
    else
    {
        while (p1 != NULL && p2 != NULL)
        {
            if (p1->data <= p2->data)
            {
                p3 = insertatend(p3, p1->data);
                p1 = p1->next;
            }
            else
            {
                p3 = insertatend(p3, p2->data);
                p2 = p2->next;
            }
        }
        while (p2 != NULL)
        {
            p3 = insertatend(p3, p2->data);
            p2 = p2->next;
        }
        while (p1 != NULL)
        {
            p3 = insertatend(p3, p1->data);
            p1 = p1->next;
        }
        return p3;
    }
}

int middle(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }
    int l = length(head);
    node *mid, *temp = head;
    if (l % 2 == 0)
    {
        int c = 1;
        while (temp != NULL)
        {
            if (c++ == l / 2)
            {
                mid = temp;
                break;
            }
            temp = temp->next;
        }
        return (mid->data + mid->next->data) / 2;
    }
    else
    {
        int c = 0;
        while (temp != NULL)
        {
            if (c++ == l / 2)
            {
                mid = temp;
                break;
            }
            temp = temp->next;
        }
        return mid->data;
    }
}

node *merge_within(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *h1 = head1, *h2 = head2, *temp, *res;
    if (h1->data > h2->data)
    {
        swap(h1, h2);
    }
    res = h1;
    while (h1 != NULL && h2 != NULL)
    {
        temp = NULL;
        while (h1 != NULL && h1->data <= h2->data)
        {
            temp = h1;
            h1 = h1->next;
        }
        temp->next = h2;
        swap(h1, h2);
    }
    return res;
}

node *rem_n_end(node *&head, int n)
{
    if (head == NULL)
    {
        return head; // EQUIVALENT TO PASS IN PYTHON.
    }
    else
    {
        node *temp = head, *p, *q;
        int c = 0, l = length(head);
        while (temp != NULL)
        {
            c += 1;
            if (c == (l - n))
            {
                p = temp;
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "\nN nodes are unavailable!!";
        }
        else
        {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
        return head;
    }
}

node *rev_sum(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *h1 = head1, *h2 = head2, *h3 = NULL;
    int carry = 0;
    while (h1 != NULL || h2 != NULL || carry)
    {
        int sum = 0;
        if (h1 != NULL)
        {
            sum += h1->data;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            sum += h2->data;
            h2 = h2->next;
        }
        sum += carry;
        carry = sum / 10;
        h3 = insertatend(h3, sum % 10);
    }
    return h3;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
}
node *convert_to_ll(int a)
{
    node *num = NULL;
    while (a)
    {
        num = insertatbeg(num, a % 10);
        a /= 10;
    }
    return num;
}

void sum(node *h1, node *h2)
{
    int a, b;
    cout << "Enter any two numbers :";
    cin >> a >> b;
    h1 = convert_to_ll(a);
    h2 = convert_to_ll(b);
    display(convert_to_ll(a + b));
}
int main()
{
    node *head = NULL, *head1, *head2;
    int c, val, key;
    cout << "1] Insert at beginning\n2] Insert at end\n3] Print LL\n4] Search for key\n5] Insert before key\n6] Insert after key\n7] Delete element\n8] Reverse LL\n9] Reverse K nodes\n10] Make cycle\n11] Detect cycle\n12] Delete cycle\n13] Length of LL\n14] Append last k nodes\n15] Odd postion followed by even position element\n16] Merge 2 Sorted LL\n17] MIDDLE OF LINKED LIST.\n18] REMOVE N-TH NODE FROM END\n19] ADD AS LL.\n20] Sum of numbers as LL\n21] Exit";
    while (1)
    {
        cout << "\nEnter choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "\nEnter value: ";
            cin >> val;
            head = insertatbeg(head, val);
            break;
        case 2:
            cout << "\nEnter value: ";
            cin >> val;
            head = insertatend(head, val);
            break;
        case 3:
            cout << "\nLinked list: ";
            display(head);
            break;
        case 4:
            cout << "\nEnter key:";
            cin >> val;
            search(head, val);
            break;
        case 5:
            cout << "\nEnter key: ";
            cin >> key;
            cout << "\nEnter value: ";
            cin >> val;
            head = insertbefore(head, val, key);
            break;
        case 6:
            cout << "\nEnter key: ";
            cin >> key;
            cout << "\nEnter value: ";
            cin >> val;
            head = insertafter(head, val, key);
            break;
        case 7:
            cout << "\nEnter key: ";
            cin >> key;
            head = delete_ele(head, key);
            break;
        case 8:
            head = reverse_ll(head);
            break;
        case 9:
            cout << "\nEnter k: ";
            cin >> val;
            head = revknodes(head, val);
            break;
        case 10:
            cout << "\nEnter start position of loop: ";
            cin >> val;
            head = make_cycle(head, val);
            break;
        case 11:
            detect_loop(head);
            break;
        case 12:
            head = delete_loop(head);
            break;
        case 13:
            cout << "\nLength of Linked list: " << length(head);
            break;
        case 14:
            cout << "\nEnter K:";
            cin >> val;
            head = kappend(head, val);
            break;
        case 15:
            head = odd_even_pos(head);
            break;
        case 16:
            head1 = NULL, head2 = NULL;
            cout << "\nEnter sorted list 1 Elements [Enter -999 to end]: ";
            cin >> val;
            while (val != -999)
            {
                head1 = insertatend(head1, val);
                cin >> val;
            }
            display(head1);
            cout << "\nEnter sorted list 2 Elements [Enter -999 to end]: ";
            cin >> val;
            while (val != -999)
            {
                head2 = insertatend(head2, val);
                cin >> val;
            }
            display(head2);
            cout << "\nWITH [1] 0R WITHOUT [0] EXTERNAL LL: ";
            cin >> val;
            if (val == 1)
            {
                head = merge(head1, head2);
            }
            else
            {
                head = merge_within(head1, head2);
            }
            break;
        case 17:
            cout << "\nMIDDLE OF ODD LL OR AVG OF MIDDLE FOR EVEN LL: " << middle(head);
            break;
        case 18:
            cout << "\nENTER N:";
            cin >> val;
            head = rem_n_end(head, val);
            break;
        case 19:
            head1 = NULL, head2 = NULL;
            cout << "\nEnter N1 DIGITS[-999 to end]: ";
            cin >> val;
            while (val != -999)
            {
                head1 = insertatend(head1, val);
                cin >> val;
            }
            cout << "\nEnter N2 DIGITS[-999 to end]: ";
            cin >> val;
            while (val != -999)
            {
                head2 = insertatend(head2, val);
                cin >> val;
            }
            display(head2);
            head = rev_sum(head1, head2);
            break;
        case 20:
            head1 = NULL, head2 = NULL;
            sum(head1, head2);
            break;
        case 21:
            exit(0);
        }
    }
}