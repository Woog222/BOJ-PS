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
const int MAX = 200001;

vector<int> adj[MAX];
bool visit[MAX];
int N, M;

int dfs(int here) {
    visit[here] = true;
    if (adj[here].empty()) return -1;
    
    int ret = adj[here].size() % 2;
    for (int next : adj[here]) {
        if (!visit[next]) ret += dfs(next);
    }
    return ret;
}

void readInput() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    readInput();
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visit[i]) {
            int temp = dfs(i);
            if (temp >= 0)
                ans += max(1, temp / 2);
        }
    }
    cout << ans << el;
}