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
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 1987654321;

// 우좌하상
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };


int N = 1;
int grid[100][100];
bool visit[100][100];

bool dfs(int r, int c, int m, int M);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);


    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];


    int lo = 0, hi = 200;
    int ans = 200;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;

        

        bool possible = false;

        for (int m = 0; m+mid <= 200; ++m) 
        {
            if (grid[0][0] < m || grid[0][0] >m + mid) continue;

            memset(visit, false, sizeof(visit));
            if (dfs(0, 0, m, m + mid)) {
                possible = true;
                break;
            }
        }



        if ( possible ) {
            hi = mid - 1;
            ans = min(ans, mid);
        }
        else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;
}


inline bool valid(int r, int c)
{
    return r >= 0 && r < N && c >= 0 && c < N;
}

bool dfs(int r, int c, int m, int M)
{
    if (r == N - 1 && c == N - 1)
        return true;

    visit[r][c] = true;

    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (!valid(nr, nc) || visit[nr][nc] ) continue;
        if (grid[nr][nc] <m || grid[nr][nc] >M) continue;



        if ( dfs(nr, nc, m, M) )
            return true;
    }

    return false;
}