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
int depth[100001], p[100001][17];
vi adj[100001];

void init();
int lca(int u, int v);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    queue<int> q;
    q.push(1);
    p[1][0] = 0;
    depth[1] = 0;
    
    while (!q.empty())
    {
        int here = q.front(); q.pop();
        for (int next : adj[here]) {
            if (depth[next] == -1) {
                q.push(next);
                depth[next] = depth[here] + 1;
                p[next][0] = here;
            }
        }
    }

    init();
    int query; cin >> query;
    while (query--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << el;
    }
}

void init() {
    // 루트의 부모를 따로 나타내기위해 노드 번호 1~N으로 세팅
    // p[i][0]은 본인의 직계 부모로 초기화돼있다고 가정
    // p[root][0] = 0;
    for (int j = 1; (1 << j) < N; ++j) {
        for (int i = 1; i <= N; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    // WLOG, depth[u] < depth[v]
    if (depth[u] > depth[v]) swap(u, v);

    int k = 0; 
    while ((1 << (k+1)) <= depth[v]) k++;

    // v를 u까지 올리기
    for (int i = k; i >= 0; --i) {
        if (depth[v] - (1 << i) >= depth[u])
            v = p[v][i];
    }
    if (u == v) return u;

    // 같이 올리기
    for (int i = k; i >= 0; --i) {
        if (p[u][i] != 0 && p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    }
    return p[u][0];
}