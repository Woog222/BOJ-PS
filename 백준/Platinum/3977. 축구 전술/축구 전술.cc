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
const int MAX = 100001;

// sccId, order -1로 초기화
vector<int> adj[MAX];
stack<int> st;
int sccId[MAX], order[MAX], sccOne[MAX];
int vcnt, scccnt;
int N;

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
        sccOne[scccnt] = st.top();
        while (true) {
            int temp = st.top(); st.pop();
            sccId[temp] = scccnt;
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
    memset(sccOne, -1, sizeof(sccOne));
    for (int i = 0; i < N; ++i) adj[i].clear();

    while (e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
}

void fun() {
    for (int i = 0; i < N; ++i) {
        if (!order[i]) {
            cout << "Confused" << el;
            return;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (sccId[i] == scccnt - 1) cout << i << el;
    }
}

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        readInput();
        for (int i = 0; i < N; ++i) 
            if (order[i] == -1) dfsScc(i);

        memset(order, 0, sizeof(order));
        dfs(sccOne[scccnt - 1]);
        fun(); cout << el;
    }
}