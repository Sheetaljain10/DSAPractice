#include <iostream.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    // USED FOR VECTORS , MAPS.

    // The auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer.
    // So here 'p' takes the references of a[i] and works instead of a[i] as 'p'.
    for (auto &p : a)
    {
        cin >> p;
    }
    for (auto q : a)
    {
        cout << q << " ";
    }
}