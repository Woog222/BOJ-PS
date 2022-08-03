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
const int N = 1000;

struct Edge {
    int u, v, cnt;
};

vector<int> adj[N];
vector<Edge> edge;
deque<int> circuit;

void dfsEuler(int here) {

    while (!adj[here].empty()) {
        int idx = adj[here].back();
        auto& e = edge[idx];
        assert(&e == &edge[idx]);
        if (e.cnt > 0) {
            e.cnt--;
            dfsEuler((e.u == here) ? e.v : e.u);
        }
        else
            adj[here].pop_back();
    }
    circuit.push_front(here);
}

bool readInput() {
    int n; cin >> n;
    vvi temp(n, vi(n));

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int deg = 0;
        for (int j = 0; j < n; ++j) {
            cin >> temp[i][j];
            deg += temp[i][j];
        }
        if (deg % 2) ok = false;
    }
    if (!ok) return false;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            int cnt = temp[i][j];
            if (cnt > 0) {
                edge.push_back(Edge{ i,j,cnt });
                int idx = (int)edge.size() - 1;
                adj[i].push_back(idx);
                adj[j].push_back(idx);
            }
        }
    }
    return true;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    if (!readInput()) {
        cout << -1 << el;
        return 0;
    }

    dfsEuler(0);
    for (int i : circuit) cout << i+1 << " ";
    cout << el;
}