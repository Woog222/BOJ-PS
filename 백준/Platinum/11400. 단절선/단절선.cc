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

vi adj[MAX];
int discovered[MAX], cnt=0; // discovered->-1로 초기화
vector<pii> ans;
int N, M;

int dfsCut(int here, int parent);
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
        if (discovered[i] == -1) dfsCut(i, -1);

    sort(ans.begin(), ans.end());
    cout << ans.size() << el;
    for (auto p : ans) cout << p.first << " " << p.second << el;

}

int dfsCut(int here, int parent) {
    int ret = discovered[here] = cnt++;

    for (int go : adj[here]) {

        if (discovered[go] == -1) {
            int highest = dfsCut(go, here);
            if (discovered[here] < highest) {
                int a = here, b = go;
                if (a > b) swap(a, b);
                ans.emplace_back(a, b);
            }
                
            ret = min(ret, highest);
        }
        else if (go!=parent)
            ret = min(ret, discovered[go]);
    }

    return ret;
}