#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int main()
{
    vi a(8);
    int temp = 8;
    while (temp--)
        cin >> a[7 - temp];

    bool ascend = true;
    bool descend = true;
    for (int i = 0; i < 7; ++i) {
        if (a[i] > a[i + 1])
            ascend = false;
        if (a[i] < a[i + 1])
            descend = false;
    }

    if (ascend)
        cout << "ascending\n";
    else if (descend)
        cout << "descending\n";
    else
        cout << "mixed\n";
}
