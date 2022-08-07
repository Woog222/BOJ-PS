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
int sccId[MAX], order[MAX];
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

int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    memset(sccId, -1, sizeof(sccId));
    memset(order, -1, sizeof(order));

    int n, e; cin >> n >> e;
    while (e--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) 
        if (order[i] == -1) dfsScc(i);
    
    vvi ans(scccnt, vi());
    for (int i = 1; i <= n; ++i) 
        ans[sccId[i]].push_back(i);

    sort(ans.begin(), ans.end(), [&](const vi& a, const vi& b) {
            return a.front() < b.front();
        });
    


    cout << scccnt << el;
    for (auto& v : ans) {
        for (int i : v) cout << i << " ";
        cout << -1 << el;
    }
}