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
const double PI = acos(-1.0);

vector<pii> adj[100001];
int N, M, K, S, T, indeg[100001];
ll cache[100001][11];

ll fun(int here, int left);
void readInput();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    readInput();
    memset(cache, -1, sizeof(cache));
    ll ans = fun(S, K);
    if (ans < 0) ans = -1;
    cout << ans  << el;
}

ll fun(int here, int left) {
    if (here == T && left == 0) return 0;
    ll& ret = cache[here][left];
    if (ret != -1) return ret;

    ret = INF;
    if (here == T) ret = 0;
    for (pii p : adj[here]) {
        int next = p.first;
        if (next > here) {
            ret = max(ret, fun(next, left) + p.second);
        }
        if (next < here && left > 0) {
            ret = max(ret, fun(next, left - 1));
        }
    }
    return ret;
}

void readInput() {
    cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; ++i) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
        indeg[b]++;
    }

}