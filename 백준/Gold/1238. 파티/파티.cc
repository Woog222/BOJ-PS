#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

struct Edge {
    int to, weight;

    explicit Edge(int _to=0, int _weight=0) : to(_to), weight(_weight) {}

};

int N, M, X;
vector<Edge> adj[1001]; // 1 ~ N
int comeback[1001];
int dijkstra(int start);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back(Edge(to, cost));
    }
    memset(comeback, -1, sizeof(comeback));
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0,X);

    while (!q.empty())
    {
        auto here = q.top(); q.pop();
        if (comeback[here.second] != -1) continue;
        comeback[here.second] = here.first;
        //cout << here.second << " : " << here.first << '\n';

        for (Edge e : adj[here.second]) {
            if (comeback[e.to] == -1 ) {
                q.emplace(e.weight + here.first, e.to);
            }
        }
    }

    //i ~ X + X ~I
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        //cout << i << " : " << dijkstra(i) << " ~ " << comeback[i] << '\n';
        ans = max(ans, comeback[i] + dijkstra(i));
    }
    cout << ans << '\n';
}
// to X
int dijkstra(int start)
{
    vi dist(N + 1, INF);
    vector<bool> visit(N + 1, false);
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);

    while (!pq.empty())
    {
        auto here = pq.top(); pq.pop();
        if (visit[here.second]) continue;
        visit[here.second] = true;
        if (here.second == X)
            return dist[X];

        for (auto next : adj[here.second]) {
            if (dist[next.to] > dist[here.second] + next.weight) {
                dist[next.to] = dist[here.second] + next.weight;
                pq.emplace(dist[here.second] + next.weight, next.to);
            }
        }
    }
    assert(0);
    return dist[X];
}