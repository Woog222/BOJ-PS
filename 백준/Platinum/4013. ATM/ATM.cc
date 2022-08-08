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
const int MAX = 500001;

// sccId, order -1로 초기화
vector<int> adj[MAX], adj2[MAX];
stack<int> st;
int sccId[MAX], order[MAX], vcnt, scccnt; // SCC
int atm[MAX], sum[MAX]; // MONEY
int N, S;
bool isend[MAX];

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
            sum[scccnt] += atm[temp];
            if (temp == here) break;
        }
        scccnt++;
    }
    return ret;
}

void dfs(int here) {
    order[here] = 1;
    for (int there : adj[here]) 
        if (!order[there]) dfs(there);
}

void readInput() {
    int e; cin >> N >> e;

    vcnt = scccnt = 0;
    memset(sccId, -1, sizeof(sccId));
    memset(order, -1, sizeof(order));
    for (int i = 1; i <= N; ++i) adj[i].clear();

    while (e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; ++i) cin >> atm[i]; 
}

int cache[MAX];
int fun(int here) {
    int& ret = cache[here];
    if (ret != -1) return ret;

    ret = isend[here] ? sum[here] : -2;
    for (int there : adj2[here]) {
        int m = fun(there);
        if (m > 0) 
            ret = max(ret, sum[here] + m);
    }

    return ret;
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    readInput();
    // scc
    for (int i = 1; i <= N; ++i) 
        if (order[i] == -1) dfsScc(i);
    // make adj2
    for (int i = 1; i <= N; ++i) 
        for (int j : adj[i]) 
            if (sccId[i] != sccId[j]) 
                adj2[sccId[i]].push_back(sccId[j]);
    // end or not
    int p;
    cin >> S >> p;
    while (p--) {
        int temp; cin >> temp;
        isend[sccId[temp]] = true;
    }

    // dp
    memset(cache, -1, sizeof(cache));
    cout << fun(sccId[S]) << el;
}
