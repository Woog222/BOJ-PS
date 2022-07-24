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
#define el '\n';
#define FOR(i, from, to) for(int (i) = (from); (i)<=(to); ++(i))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

int dr[] = { 1,0,-1,0 };
int dc[] = { 0,-1,0,1 };

int N, M;
int grid[2][100][100];
bool eraseCheese(int nth);

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j) 
            cin >> grid[0][i][j];

    int ans = 1;
    while (eraseCheese(ans++));
    cout << ans-1 << el;
}

inline bool valid(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}

void dfs(int prev, int r, int c) {
    grid[prev][r][c] = -1;
    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (valid(nr, nc) && grid[prev][nr][nc] == 0)
            dfs(prev, nr, nc);
    }
}
// 지우고, 안지워진게 남아있으면 true
bool eraseCheese(int nth)
{
    int now = nth % 2;
    int prev = 1 - now;

    dfs(prev, 0, 0);

    bool left = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[prev][i][j] != 1) {
                grid[now][i][j] = 0;
                continue;
            }

            int adj = 0;
            for (int k = 0; k < 4; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (valid(nr, nc) && grid[prev][nr][nc] == -1) 
                    adj++;
            }

            if (adj >= 2) {
                grid[now][i][j] = 0;
            }
            else {
                left = true;
                grid[now][i][j] = 1;
            }
                
        }
    }

    return left;
}