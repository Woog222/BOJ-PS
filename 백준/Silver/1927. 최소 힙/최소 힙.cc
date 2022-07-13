#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int p[101];
int Size[101];

int Find(int v) {
    if (p[v] == v)
        return v;
    else
        return p[v] = Find(p[v]);
}

void Union(int u, int v)
{
    int pu = Find(u);
    int pv = Find(v);

    if (pu == pv)
        return;

    p[pu] = pv;
    Size[pv] = Size[pv] + Size[pu];
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int n; cin >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    while (n--)
    {
        int a; cin >> a;
        if (a == 0) {
            if (q.empty())
                cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else
            q.push(a);
    }
}
