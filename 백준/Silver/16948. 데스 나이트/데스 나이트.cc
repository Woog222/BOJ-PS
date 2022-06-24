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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

// 우 하 좌 상
int dr[] = { -2,-2, 0, 0, 2, 2 };
int dc[] = { -1, 1,-2, 2,-1, 1 };


int N;
inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}

vector<vi> move(const vector<vi>& grid, int dir);
int fun(const vvi& grid, int nth);
int main()
{
    cin >> N;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    queue<pii> q;
    vvi dist = vvi(N, vi(N, -1));
    dist[r1][c1] = 0;
    q.emplace(r1, c1);

    while (!q.empty()) 
    {
        int r, c;
        tie(r, c) = q.front(); q.pop();
        int d = dist[r][c];

        if (r == r2 && c == c2) {
            cout << d << endl;
            return 0;
        }

        for (int k = 0; k < 6; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (valid(nr, nc) && dist[nr][nc] == -1) {
                dist[nr][nc] = d + 1;
                q.emplace(nr, nc);
            }
        }
    }

  
    

    cout << -1 << endl;
}