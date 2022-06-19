#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, num[10];
vector<int> ans(10);
bool check[10] = { false, };
vector<vector<int>> d;

void fun(int idx, int start)
{
    if (idx == m) {
        d.push_back(ans);
        return;
    }

    for (int i = start; i < n; i++)
    {
        ans[idx] = num[i];
        fun(idx + 1, i);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort( num, num+n );

    fun(0, 0);

    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());

    for (auto& v : d)
    {
        for (int i = 0; i < m; i++) {
            cout << v[i];
            if (i != m - 1) { cout << " "; }
        }
        cout << '\n';
    }
    return 0;

}