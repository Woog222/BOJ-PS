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
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
const ll INF = INT32_MAX;
const ll MOD = 20090711;


struct Edge {
    int to, weight;

    Edge(int _to, int _w) : to(_to), weight(_w) {}
};

vector<Edge> adj[10000];
ll n, m;
bool visit[10001];


void dfs(int here, int limit)
{
    visit[here] = true;
    for (auto next : adj[here]) {
        if (!visit[next.to] && next.weight >= limit)
            dfs(next.to, limit);
    }
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].emplace_back(to, weight);
        adj[to].emplace_back(from, weight);
    }
    int start, goal;
    cin >> start >> goal;

    ll ans = 0;
    ll lo = 1, hi = 1000000000;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        memset(visit, false, sizeof(visit));
        dfs(start, mid);

        if (visit[goal]) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    cout << ans << endl;

}