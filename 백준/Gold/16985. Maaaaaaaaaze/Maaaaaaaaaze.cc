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


int dx[] = { 0, 0, 0, 0, 1,-1 };
int dy[] = { 1,-1, 0, 0, 0, 0 };
int dz[] = { 0, 0, 1,-1, 0, 0 };

int dist[5][5][5];
vvi boards[5];
void makeBoard();
int fun(int nth, vector<vvi>& maze);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    makeBoard();

    vi order(5);
    for (int i = 0; i < 5; ++i)
        order[i] = i;

    int ans = INF;
    do {
        // O(125)
        vector<vvi> maze(5);
        for (int i = 0; i < 5; ++i)
            maze[i] = boards[order[i]];

        ans = min(ans, fun(0, maze));
    } while (next_permutation(order.begin(), order.end()));

    if (ans == INF)
        ans = -1;
    cout << ans << endl;
}

inline bool valid(int x, int y, int z)
{
    return x >= 0 && x < 5 && y >= 0 && y < 5 && z >= 0 && z < 5;
}

void makeBoard()
{
    for (int k = 0; k < 5; ++k) {
        vvi& board = boards[k];

        board.resize(5, vi(5));
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> board[i][j];
    }
}

int bfs(const vector<vvi>& maze)
{
    if (maze[0][0][0] == 0)
        return INF;

    memset(dist, -1, sizeof(dist));
    queue<tuple<int, int, int>> q;
    dist[0][0][0] = 0;
    q.emplace(0, 0, 0);

    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front(); q.pop();
        if (x == 4 && y == 4 && z == 4)
            return dist[x][y][z];

        for (int k = 0; k < 6; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if (valid(nx, ny, nz) && maze[nx][ny][nz] == 1 && dist[nx][ny][nz] == -1) {
                dist[nx][ny][nz] = dist[x][y][z] + 1;
                q.emplace(nx, ny, nz);
            }
        }
    }

    return INF;
}

void rot(vvi& a) // 판 시계방향 90도 회전
{
    const int r = 2;
    const int c = 2;
    for (int s = 1; s <= 2; ++s)
    {
        vector<int> temp(2 * s);
        for (int i = 0; i < 2 * s; ++i) {
            temp[i] = a[r - s][c - s + i + 1];
        }
        // l -> u
        int to_r = r - s, to_c = r - s + 1;
        int from_r = r + s - 1, from_c = c - s;
        for (int i = 0; i < 2 * s; ++i) {
            a[to_r][to_c + i] = a[from_r - i][from_c];
        }
        // d -> l
        to_r = r + s - 1, to_c = c - s;
        from_r = r + s, from_c = c + s - 1;
        for (int i = 0; i < 2 * s; ++i) {
            a[to_r - i][to_c] = a[from_r][from_c - i];
        }
        // r -> d
        to_r = r + s, to_c = c + s - 1;
        from_r = r - s + 1, from_c = c + s;
        for (int i = 0; i < 2 * s; ++i) {
            a[to_r][to_c - i] = a[from_r + i][from_c];
        }
        // u -> r
        to_r = r - s + 1, to_c = c + s;
        for (int i = 0; i < 2 * s; ++i) {
            a[to_r + i][to_c] = temp[i];
        }
    }
}
int fun(int nth, vector<vvi> &maze)
{
    if (nth == 5) {
        return bfs(maze);
    }

    int temp = 0;
    int ret = INF;
  
    ret = min(ret, fun(nth + 1, maze));
    rot(maze[nth]);
    ret = min(ret, fun(nth + 1, maze));
    rot(maze[nth]);
    ret = min(ret, fun(nth + 1, maze));
    rot(maze[nth]);
    ret = min(ret, fun(nth + 1, maze));
    rot(maze[nth]);

    return ret;
}