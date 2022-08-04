#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MAX = 1000;

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    int n, k; cin >> n >> k;

    deque<int> dq;
    for (int i = 1; i <= n; ++i) dq.push_back(i);

    int ans = 0;
    while (k--) {
        int x; cin >> x;
        int idx = find(dq.begin(), dq.end(), x) - dq.begin();

        int cost = min(idx, n - idx);
        ans += cost; n--;

        while (dq.front() != x) {
            int temp = dq.front();
            dq.pop_front(); dq.push_back(temp);
        }
        dq.pop_front();
    }
    cout << ans << el;
}