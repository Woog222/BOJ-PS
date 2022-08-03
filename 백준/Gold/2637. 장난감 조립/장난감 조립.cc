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
const double PI = acos(-1.0);

int N, cost[101][101], indeg[101];
vector<pii> adj[101];

int main() {
    cin >> N;
    int m; cin >> m;
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        adj[b].emplace_back(a, c); // a만드는데 b가 c개 필요하다
        indeg[a]++;
    }

    queue<int> q;
    vi basic;
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
            cost[i][i] = 1;
            basic.push_back(i);
        }
    }
        
    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (auto p : adj[here]) {
            indeg[p.first]--;
            int cnt = p.second;
            for (int i = 1; i <= N; ++i) 
                cost[p.first][i] += cost[here][i] * cnt;
            if (indeg[p.first] == 0)
                q.push(p.first);
        }
    }
    
    for (int i : basic) {
        cout << i <<" " <<cost[N][i] << el;
    }
}
