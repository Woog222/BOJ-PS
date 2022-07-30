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
const long long INF = numeric_limits<long long>::max();
const int MOD = 1000000007;

vector<pii> x, y, z;
vector<pair<ll ,int>> adj[100000];
int N;
bool included[100000];


ll cal(int co, int a, int b) {
    if (co == 0) 
        return abs(x[a].first - x[b].first);
    else if (co == 1) 
        return abs(y[a].first - y[b].first);
    else
        return abs(z[a].first - z[b].first);
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N; 
    for (int i = 0; i < N; ++i) {
        int a, b, c; cin >> a >> b >> c;
        x.emplace_back(a, i);
        y.emplace_back(b, i);
        z.emplace_back(c, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int co = 0; co < 3; ++co) {
        auto& v = (co == 0) ? x : ((co == 1) ? y : z);

        for (int i = 0; i < N; ++i) {
            int here = v[i].second;
            if (i - 1 >= 0) 
                adj[here].emplace_back(cal(co, i, i - 1), v[i - 1].second);
            if (i + 1 < N)
                adj[here].emplace_back(cal(co, i, i + 1), v[i + 1].second);
        }
    }
    // 거리, 정점
    ll ans = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

    q.emplace(0, 0);
    while (!q.empty()) {
        ll cost; int here;
        tie(cost, here) = q.top(); q.pop();
        if (included[here]) continue;

        included[here] = true;
        ans += cost;
        
        for (auto next : adj[here]) {
            if (included[next.second]) continue;
            q.push(next);
        }
    }

    cout << ans << el;
}