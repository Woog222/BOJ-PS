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
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

int N;
vi adj[10001];
int cost[10001], indeg[10001], start[10001];

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cost[i] >> cnt;
        while (cnt--) {
            int preced; cin >> preced;
            adj[preced].push_back(i);
            indeg[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i)
        if (indeg[i] == 0) 
            q.push(i);
        

    while (!q.empty()) {
        int here = q.front(); q.pop();

        for (int next : adj[here]) {
            indeg[next]--;
            start[next] = max(start[next], start[here] + cost[here]);
            if (indeg[next] == 0)
                q.push(next);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, cost[i] + start[i]);
    }
    cout << ans << el;
}