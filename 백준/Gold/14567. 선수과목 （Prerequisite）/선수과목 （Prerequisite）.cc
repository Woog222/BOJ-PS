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

int N, indeg[1001], st[1001];
vi adj[1001];

int main() {
    cin >> N;
    
    int m;
    cin >> m;
    while (m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (int next : adj[here]) {
            indeg[next]--;
            st[next] = max(st[here] + 1, st[next]);
            if (indeg[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= N; ++i)
        cout << st[i] + 1 << " ";
    cout << el;
}