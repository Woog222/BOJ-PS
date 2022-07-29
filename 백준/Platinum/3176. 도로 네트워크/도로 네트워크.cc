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

int N;
vector<pii> adj[100001]; // to, cost
int depth[100001];
int dp[100001][17];
int mindp[100001][17];
int maxdp[100001][17];
int K;

void makeTree();
void sparseTable();
int lca(int u, int v);
pii fun(int u, int v, int co);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N; while ((1 << (K + 1)) < N) K++;
    for (int i = 1; i < N; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    makeTree(); 
    sparseTable(); 

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        int co = lca(u, v);
        auto ans = fun(u, v, co);
        cout << ans.first << " " << ans.second << el;
    }
 
}

pii fun(int u, int v, int co)
{
    int ud = depth[u] - depth[co];
    int vd = depth[v] - depth[co];

    pii ret = pii(INF, -1); // MIN, MAX
    auto& m = ret.first;
    auto& M = ret.second;
    // u~co
    for (int i = K; i >= 0; --i) {
        if (ud >= (1 << i)) {
            m = min(m, mindp[u][i]);
            M = max(M, maxdp[u][i]);
            u = dp[u][i];
            ud -= (1 << i);
        }
    }
    // v_co
    for (int i = K; i >= 0; --i) {
        if (vd >= (1 << i)) {
            m = min(m, mindp[v][i]);
            M = max(M, maxdp[v][i]);
            v = dp[v][i];
            vd -= (1 << i);
        }
    }

    return ret;
}

int lca(int u, int v) {
    //depth[u] << depth[v]
    if (depth[u] > depth[v]) swap(u, v);

    int k = 0;
    while ((1 << (k + 1)) <= depth[v]) k++;

    for (int i = k; i >= 0; --i) {
        if (depth[v] - (1 << i) >= depth[u])
            v = dp[v][i];
    }
    if (u == v) return u;

    for (int i = k; i >= 0; --i) {
        if (dp[u][i] != 0 && dp[u][i] != dp[v][i])
            u = dp[u][i], v = dp[v][i];
    }
    return dp[u][0];
}

void makeTree()
{
    memset(depth, -1, sizeof(depth));
    queue<int> q;
    q.push(1);
    depth[1] = 0;
    dp[1][0] = 1;

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (pii p : adj[here]) {
            int next = p.first;
            int cost = p.second;

            if (depth[next] == -1) {
                q.push(next);
                depth[next] = depth[here] + 1;
                dp[next][0] = here;
                mindp[next][0] = maxdp[next][0] = cost;
            }
        }
    }
}

void sparseTable()
{
    for (int j = 1; j <= K; ++j) {
        for (int i = 1; i <= N; ++i) {
            dp[i][j] = dp[dp[i][j-1]][j - 1];
        }
    }

    for (int j = 1; j <= K; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (depth[i] - (1 << j) >= 0)
                mindp[i][j] = min(mindp[i][j - 1], mindp[dp[i][j - 1]][j - 1]);
        }
    }

    for (int j = 1; j <= K; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (depth[i] - (1 << j) >= 0)
                maxdp[i][j] = max(maxdp[i][j - 1], maxdp[dp[i][j - 1]][j - 1]);
        }
    }
}