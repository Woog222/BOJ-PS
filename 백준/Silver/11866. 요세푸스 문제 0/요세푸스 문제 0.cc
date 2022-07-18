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

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n, k; cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        q.push(i);

    vi ans;
    while (!q.empty()) {
        int cnt = k-1;
        while (cnt--) {
            q.push(q.front());
            q.pop();
        }
        ans.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < n - 1; ++i) {
        cout << ans[i] << ", ";
    }
    cout << ans.back() << ">\n";
    
}