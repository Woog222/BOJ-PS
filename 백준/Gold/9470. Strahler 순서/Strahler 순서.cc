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

int indeg[1001];
pii order[1001];
vi adj[1001];
int K, M, P;

void readInput();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        readInput();

        queue<int> q;
        for (int i = 1; i <= M; ++i) {
            if (indeg[i] == 0) {
                order[i] = make_pair(1,1);
                q.push(i);
            }
        }

        while (!q.empty()) {
            int here = q.front(); q.pop();
            int o = order[here].second >= 2 ? order[here].first + 1 : order[here].first;

            for (int next : adj[here]) {
                indeg[next]--;
                if (order[next].first == o) order[next].second++;
                else if (order[next].first < o) order[next] = pii(o, 1);

                if (indeg[next] == 0) q.push(next);
            }
        }

        int mouthOrder = order[M].first;
        if (order[M].second >= 2) mouthOrder++;
        cout << K << " " << mouthOrder << el;
    }


}

void readInput() {
    cin >> K >> M >> P;
    memset(indeg, 0, sizeof(indeg));
    for (int i = 1; i <= M; ++i) adj[i].clear();
    for (int i = 1; i <= M; ++i) order[i] = pii(0, 0);
    for (int i = 0; i < P; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
}