#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n;
void fun(vector<int> v1, vector<int> v2, int idx, int selected)
{
    if (selected == 6) {
        for (int i : v2) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    if (idx == n) { return; }

    v2[selected] = v1[idx];
    fun(v1, v2, idx + 1, selected + 1);
    fun(v1, v2, idx + 1, selected);
    
    return;
}

int main()
{
    while (true)
    {
        cin >> n;
        if (n == 0) return 0;

        vector<int> a(n);
        vector<int> ans(6);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        fun(a, ans, 0, 0);
        cout << '\n';
    }

    return 0;
}