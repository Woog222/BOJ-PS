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
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

int n;
vi adj[1001];
vi ans;
bool visit[1001];
int indeg[1001];

bool bfs();
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int m;
    cin >> n >> m;
    while (m--) {
        int cnt; cin >> cnt;
        vi order;
        while (cnt--) {
            int singer; cin >> singer;
            order.push_back(singer);
        }

        for (int i = 0; i + 1 < order.size(); ++i) {
            adj[order[i]].push_back(order[i+1]);
            indeg[order[i + 1]]++;
        }
    }

    if (!bfs() || ans.size() < n)
        cout << 0 << el;
    else
        for (int i : ans)
            cout << i << el;
 
}

bool bfs()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (indeg[i] == 0) {
            q.push(i);
            visit[i] = true;
        }

    while (!q.empty())
    {
        int here = q.front(); q.pop();
        ans.push_back(here);

        for (int next : adj[here]) {
            if (visit[next])
                return false;
            indeg[next]--;
            if (indeg[next] == 0) {
                visit[next] = true;
                q.push(next);
            }
        }
    }

    return true;
}