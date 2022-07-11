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
const int MOD = 10000000;

int dist[1001][1001];

int N, T;

void makeGraph();
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N >> T;
    makeGraph();

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int q; cin >> q;
    while (q--)
    {
        int a, b; cin >> a >> b;
        cout << dist[a][b] << '\n';
    }

}

inline int manhattanDist(pii a, pii b)
{
    return (int)abs(a.first - b.first) + (int)abs(a.second - b.second);
}

void makeGraph()
{
    vector<bool> special(N + 1, false);
    vector<pii> loc(N + 1);

    for (int i = 1; i <= N; ++i) {
        int s, x, y; cin >> s >> x >> y;
        special[i] = (s == 1) ? true : false;
        loc[i] = pii(x, y);
    }

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            dist[i][j] = INF;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) 
        {
            if (special[i] && special[j]) {
                dist[i][j] = min(manhattanDist(loc[i], loc[j]), T);
            }
            else {
                dist[i][j] = manhattanDist(loc[i], loc[j]);
            }
        }
    }
}