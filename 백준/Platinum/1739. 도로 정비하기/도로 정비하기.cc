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
const int MAX = 4008;


int N, M, K;
vi adj[MAX]; // (2,3) ~~ (2n, 2n+1) (+, -)
stack<int> st;
int sccId[MAX], order[MAX]; // memset to -1
int vcnt, scccnt;

int dfsScc(int here) {
    int ret = order[here] = vcnt++;
    st.push(here);

    for (int there : adj[here]) {
        if (order[there] == -1) 
            ret = min(ret, dfsScc(there));
        else if (sccId[there] == -1) 
            ret = min(ret, order[there]);
    }

    if (ret == order[here]) {
        while (true) {
            int temp = st.top(); st.pop();
            sccId[temp] = scccnt;
            if (temp == here) break;
        }
        scccnt++;
    }
    return ret;
}

bool fun() {
    for (int i = 1; i <= N + M; ++i) {
        if (sccId[i * 2] == sccId[i * 2 + 1]) {
            return false;
        }
    }
    return true;
}

void readInput();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        readInput();
        int vsize = (N + M) * 2 + 1;
        for (int i = 2; i <= vsize; ++i) 
            if (order[i] == -1) dfsScc(i);
        if (fun()) cout << "Yes" << el;
        else cout << "No" << el;
    }
}

inline int neg(int v) {
    return v % 2 ? v - 1 : v + 1;
}

void readInput() {
    memset(sccId, -1, sizeof(sccId));
    memset(order, -1, sizeof(order));
    vcnt = scccnt = 0;
    cin >> N >> M >> K;
    for (int i = 0; i < MAX; ++i) adj[i].clear();

    for (int i = 0; i < K; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if (a == c && b == d) continue;

        bool right = b < d, down = a < c;
        b += N; d += N;
        if (a == c) 
            adj[right ? 2 * a + 1 : 2 * a].push_back(right ? 2 * a : 2 * a + 1);
        else if (b == d) 
            adj[down ? 2 * b + 1 : 2 * b].push_back(down ? 2 * b : 2 * b + 1);
        else {
            int r = right ? a * 2 : 2 * a + 1;
            int r2 = right ? c * 2 : c * 2 + 1;
            int c = down ? b * 2 : b * 2 + 1;
            int c2 = down ? d * 2 : d * 2 + 1;
            adj[neg(r2)].push_back(c2);
            adj[neg(c2)].push_back(r2);
            adj[neg(r)].push_back(c);
            adj[neg(c)].push_back(r);

            // r or r2
            adj[neg(r)].push_back(r2);
            adj[neg(r2)].push_back(r);
            adj[neg(c)].push_back(c2);
            adj[neg(c2)].push_back(c);
        }
    }
}