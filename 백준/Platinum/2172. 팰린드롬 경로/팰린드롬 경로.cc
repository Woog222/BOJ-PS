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

int n, L;
int dr[] = { 0, 0, 1,-1, 1, 1,-1,-1 };
int dc[] = { 1,-1, 1,-1,-1, 0, 1, 0 };
int grid[20][20];
//length, start(x,y) / end(x,y)
int dp[21][20][20][20][20]; 

inline bool valid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}


void cal(int st_r, int st_c, int r, int c, int target, int l) 
{
    // i, j에서 끝나는 l-2길의 팰린드롬의 인접한 곳이 target과 같은지 확인
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
        {
            if (dp[l - 2][r][c][i][j] > 0) {
                for (int k = 0; k < 8; ++k) {
                    int endr = i + dr[k];
                    int endc = j + dc[k];
                    if (valid(endr, endc) && grid[endr][endc] == target) {
                        dp[l][st_r][st_c][endr][endc] += dp[l - 2][r][c][i][j];
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> L;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    // Basis case : L = 1, 제자리
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[1][i][j][i][j] = 1;
        }
    }

    // L=2 한칸
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) 
        {
            int cur = grid[i][j];
            for (int k = 0; k < 8; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (valid(nr, nc) && grid[nr][nc] == cur) {
                    dp[2][i][j][nr][nc]++;
                }
            }
        }
    }

    for (int l = 3; l <= L; ++l){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
            {
                for (int k = 0; k < 8; ++k) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    if (!valid(nr, nc)) continue;

                    // 두레벨 작은, 본인 옆에서 끝나는 팰린드롬의 시작지라면
                    cal(i, j, nr, nc, grid[i][j], l);
                }
            }
        }
    }
    
    // for any (i,j) to any(x,y) palindrome of length L
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    ans += dp[L][i][j][x][y];
                }
            }
        }
    }
    cout << ans << endl;
}