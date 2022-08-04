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
const ll INF = numeric_limits<ll>::min();
const int N = 3000;

vector<int> adj[N+1];
bool visit[N+1];

int dfs(int here) {
    visit[here] = true;

    int ret = 1;
    for (int next : adj[here]) {
        if (!visit[next]) ret += dfs(next);
    }
    return ret;
}

bool readInput() {
    int v, e; cin >> v >> e;
    vi deg(v + 1,0);

    while (e--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    int odd = 0;
    for (int i = 1; i <= v; ++i) {
        if (deg[i] % 2 == 0) continue;
        odd++;
    }
    if (odd != 2 && odd != 0) return false;
    if (dfs(1) != v) return false;
    return true;
}



int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (!readInput()) {
        cout << "NO" << el;
    }
    else cout << "YES" << el;

}