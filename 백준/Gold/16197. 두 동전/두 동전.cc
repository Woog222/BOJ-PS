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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;

// 상하좌우
int dr[] = { -1, 1, 0, 0 };
int dc[] = {  0, 0,-1, 1 };
int dist[20][20][20][20];

int N, M;
vector<string> grid(20);
inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int bfs(queue<pair<pii, pii>>& q);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dist, -1, sizeof(dist));

    // input
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    //  동전 찾기
    queue<pair<pii, pii>> q;

    vector<pii> temp;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'o')
                temp.emplace_back(i, j);
        }
    }

    q.emplace(temp.front(), temp.back());
    dist[temp.front().first][temp.front().second][temp.back().first][temp.back().second] = 0;

    //bfs
    cout << bfs(q) << endl;
}

int bfs(queue<pair<pii, pii>>& q)
{

    while (!q.empty())
    {
        pii a, b;
        tie(a, b) = q.front(); q.pop();
        int nd = dist[a.first][a.second][b.first][b.second] + 1;
        if (nd > 10) return -1;

       // printf("(%d, %d), (%d, %d) : %d\n", a.first, a.second, b.first, b.second, nd-1);

        for (int k = 0; k < 4; ++k)
        {
            int nr1 = a.first + dr[k];
            int nc1 = a.second + dc[k];
            int nr2 = b.first + dr[k];
            int nc2 = b.second + dc[k];

            // out?
            int out = 0;
            if (!valid(nr1, nc1)) out++;
            if (!valid(nr2, nc2)) out++;
            if (out == 1)
                return nd;
            else if (out == 2)
                continue;

            // both not out
            if (grid[nr1][nc1] == '#') {
                nr1 -= dr[k];
                nc1 -= dc[k];
            }

            if (grid[nr2][nc2] == '#') {
                nr2 -= dr[k];
                nc2 -= dc[k];
            }

            if (dist[nr1][nc1][nr2][nc2] == -1) {
                q.emplace(pii(nr1, nc1), pii(nr2, nc2));
                dist[nr1][nc1][nr2][nc2] = nd;
            }
        }
    }
 

    return -1;
}
