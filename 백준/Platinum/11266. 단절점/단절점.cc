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
const int MAX = 10001;

vi adj[MAX];
bool iscut[MAX];
int discovered[MAX], cnt=0; // discovered->-1로 초기화
int N, M;

int dfsCut(int here, bool isRoot);
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    memset(discovered, -1, sizeof(discovered));
    cin >> N >> M;
    while (M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i=1; i<=N; ++i) 
        if (discovered[i] == -1) dfsCut(i, true);
    vi ans;
    for (int i = 1; i <= N; ++i) if (iscut[i]) ans.push_back(i);
    cout << ans.size() << el;
    for (int i : ans) cout << i << " "; cout << el;
}

int dfsCut(int here, bool isRoot) {
    discovered[here] = cnt++;
    int ret = discovered[here];

    // 루트인경우, 자식이 2개 이상이면 절단점이다.
    int child = 0;
    for (int go : adj[here]) {

        if (discovered[go] == -1) {
            child++;
            int highest = dfsCut(go, false);
            if (!isRoot && discovered[here] <= highest)
                iscut[here] = true;
            ret = min(ret, highest);
        }
        else
            ret = min(ret, discovered[go]);
    }

    if (isRoot) iscut[here] = child >= 2;
    return ret;
}