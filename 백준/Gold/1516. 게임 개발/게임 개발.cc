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

int N, cost[501], start[501], indeg[501];
vi adj[501];

void readInput();
int main() {
    readInput();

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int here = q.front(); q.pop();
        int st = start[here];

        for (int next : adj[here]) {
            indeg[next]--;
            start[next] = max(start[next], st + cost[here]);
            if (indeg[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= N; ++i) cout << cost[i] + start[i] << el;
}

void readInput() {
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
        while (true) {
            int pre; cin >> pre;
            if (pre == -1) break;
            adj[pre].push_back(i);
            indeg[i]++;
        }
    }
}