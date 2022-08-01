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
const int INF = 987654321;
const int MOD = 1000000007;



int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int N, M;
int  dp[1000][1000];
string grid[1000];

inline bool valid(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> grid[i];
    
    for (int i = 0; i < N; ++i) dp[i][0] = grid[i][0] - '0';
    for (int j = 0; j < M; ++j) dp[0][j] = grid[0][j] - '0';
    
    int ans = 0;
    for (int i = 0; i < N; ++i) ans = max(ans, dp[i][0]);
    for (int j = 0; j < M; ++j) ans = max(ans, dp[0][j]);

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (grid[i][j] == '0') continue;

            int& cur = dp[i][j];
            cur = dp[i - 1][j - 1]+1;
            cur = min(cur, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));

            ans = max(ans, cur);
        }
    }

    cout << ans*ans << el;
}