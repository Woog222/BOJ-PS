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

int dr[] = { 0,1,0,-1 };
int dc[] = { 1,0,-1,0 };

int N, M;
string grid[50];
int dist[50][50][4][4];
pii start;
vector<pii> dest;

inline bool valid(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}

int bfs(int dir)
{
    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int, int>> q;
    q.emplace(start.first, start.second, dir, 0);

    while (!q.empty()) {
        int r, c, dir, gift;
        tie(r, c, dir, gift) = q.front(); q.pop();
        if (gift == 3) return dist[r][c][dir][gift];
        int nd = (dir == 4) ? 1 : dist[r][c][dir][gift] + 1;

        for (int k = 0; k < 4; ++k) {
            if (k == dir) continue;
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (valid(nr, nc) && dist[nr][nc][k][gift] == -1 && grid[nr][nc] != '#') {
                int ngift = gift;
                if (pii(nr, nc) == dest[0]) ngift |= 1;
                else if (pii(nr, nc) == dest[1]) ngift |= 2;

                dist[nr][nc][k][ngift] = nd;
                q.emplace(nr, nc, k, ngift);
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> grid[i];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'S')
                start = pii(i, j);
            else if (grid[i][j] == 'C')
                dest.emplace_back(i, j);
        }
    }

    cout << bfs(4) << el;
}