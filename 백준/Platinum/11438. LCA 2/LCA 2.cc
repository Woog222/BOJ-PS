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
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;
const int N = 100000;

vector<int> adj[N + 1]; // 그래프
int p[N + 1][17];
int in[N + 1]; int out[N + 1];
int order = 0;

void dfs(int here, int parent);
int lca(int u, int v);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 1);

    int query; cin >> query;
    while (query--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << el;
    }
}


// 1~N, 루트가 1이면 (1,0)으로 시작
void dfs(int here, int parent) {
    in[here] = ++order;

    //dfs특성상, 부모의 p정보는 이미다 구현되어 있다.
    p[here][0] = parent;
    for (int j = 1; j < 17; ++j)
        p[here][j] = p[p[here][j - 1]][j - 1];
    for (int next : adj[here])
        if (next != parent) dfs(next, here);

    out[here] = ++order;
}

inline bool isAncestor(int u, int v) {
    return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) return u;
    if (isAncestor(v, u)) return v;

    // 직전까지 올리기
    for (int k = 16; k >= 0; --k) {
        if (!isAncestor(p[u][k], v))
            u = p[u][k];
    }
    return p[u][0];
}