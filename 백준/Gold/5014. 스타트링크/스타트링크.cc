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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int dist[1000001];

int main()
{
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();

        int next = cur + u;
        if (next >= 1 && next <= f && dist[next] == -1)
        {
            q.push(next);
            dist[next] = dist[cur] + 1;
        }

        next = cur - d;
        if (next >= 1 && next <= f && dist[next] == -1)
        {
            q.push(next);
            dist[next] = dist[cur] + 1;
        }
    }

    if (dist[g] == -1) {
        cout << "use the stairs\n";
    }
    else {
        cout << dist[g] << endl;
    }
}