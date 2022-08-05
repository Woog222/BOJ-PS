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
vector<vector<pii>> bcc;
int dist[MAX], N, cnt = 0;
stack<pii> s;

bool readInput();
int dfsBcc(int here, int parent=-1);
bool fun();
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    readInput();
    memset(dist, -1, sizeof(dist));
    dfsBcc(1);
    if (fun()) cout << "Cactus" << el;
    else cout << "Not cactus" << el;
}

bool fun() {
    vi cnt(MAX + 1, 0);

    for (auto& b : bcc) {
        if (b.size() == 1) continue;

        set<int> vs;
        for (auto p : b) {
            vs.insert(p.first);
            vs.insert(p.second);
            cnt[p.first]++;
            cnt[p.second]++;
        }
        if (b.size() > vs.size()) return false;
    }

    for (int i = 1; i <= N; ++i) 
        if (cnt[i] > 2) return false;
    return true;
}

int dfsBcc(int here, int parent) {
    int ret = dist[here] = cnt++;

    for (int go : adj[here]) {
        if (go == parent) continue;
        if (dist[here] > dist[go]) s.emplace(here, go);

        if (dist[go] == -1) {
            int highest = dfsBcc(go, here);
            ret = min(ret, highest);

            if (dist[here] <= highest) {
                bcc.push_back(vector<pii>());
                vector<pii>& cur = bcc.back();
                while (!s.empty() && s.top() != pii(here, go)) {
                    cur.push_back(s.top()); s.pop();
                }
                cur.push_back(s.top()); s.pop();
            }
        }
        else
            ret = min(ret, dist[go]);
    }

    return ret;
}

bool readInput()
{
    int k;
    cin >> N >> k;
    while (k--) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    return true;
}