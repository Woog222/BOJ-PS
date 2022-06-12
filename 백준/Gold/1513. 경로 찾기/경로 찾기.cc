#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000007;

int dr[] = { 0,-1 };
int dc[] = { -1,0 };
int n, m, c;
int grid[51][51];
int dp[51][51][51][51]; //r, c, cnt, num (방문한 오락실 중 최대 : num)

// trace back
inline bool valid(int r, int c) {
    return r >= 1 && r <= n && c >= 1 && c <= m;
}

void cal(int r, int c, int cnt, int last) 
{
    int& ret = dp[r][c][cnt][last];
    int cur = grid[r][c];

    for (int i = 0; i < 2; ++i) {
        int prev_r = r + dr[i];
        int prev_c = c + dc[i];
        if (!valid(prev_r, prev_c)) continue;

        if (cur == 0)
            ret = (ret + dp[prev_r][prev_c][cnt][last] ) % MOD;
        else if (cur == last) {
            for (int prev_last = 0; prev_last < last; ++prev_last)
                ret = (ret + dp[prev_r][prev_c][cnt - 1][prev_last]) % MOD;
        }            
    }
}

int main()
{   
    cin >> n >> m >> c;
    for (int i = 1; i <= c; ++i) {
        int r, c; cin >> r >> c;
        grid[r][c] = i;
    }


    if (grid[1][1] > 0)
        dp[1][1][1][grid[1][1]] = 1;
    else
        dp[1][1][0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int cnt = 0; cnt <= c; ++cnt) {
                for (int last = 0; last <= c; ++last ) {
                    if (grid[i][j] == 0 || grid[i][j] == last)
                        cal(i, j, cnt, last);
                }
            }
        }
    }

    for (int i = 0; i <= c; ++i) 
    {
        int ans = 0;
        for (int last = 0; last <= c; ++last) {
            ans = (ans + dp[n][m][i][last] )%MOD;
        }
        cout << ans << " ";

    }

    cout << endl;
}
