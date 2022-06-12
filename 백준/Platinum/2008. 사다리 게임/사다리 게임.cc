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


int n, m;
int A, B, x, y;
int dp[501][101][101]; // min of [level][from][to]
int ladder[501];

int cal_add_cost(int from, int to, int existing_ladder) 
{
    if (from < to) {
        int res = (to - from) * y;
        if (existing_ladder == from)
            res -= y;
        return res;
    }
    else {
        int res = (from - to) * y;
        if (existing_ladder == from - 1)
            res -= y;
        return res;
    }
}


int main()
{   
    cin >> n >> m;
    cin >> A >> B >> x >> y;
    for (int i = 1; i <= m; ++i) {
        cin >> ladder[i]; // p ~ p+1
    }

    // -1 : can't reach
    memset(dp, -1, sizeof(dp));
    // basis case: level 0
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            if (a == b)
                dp[0][a][b] = 0;
            else {
                dp[0][a][b] = (b > a) ? (b - a) * y : (a - b) * y;
            }
        }
    }

    // bottom up
    for (int level = 1; level <= m; ++level) {
        for (int a = 1; a <= n; ++a) {
            for (int b = 1; b <= n; ++b) 
            {
                bool no_ladder_b = (ladder[level] != b) && (ladder[level] != b - 1);
                int& ret = dp[level][a][b];
                ret = INF;

                // lowest cost, just fall through
                if (dp[level - 1][a][b] != -1 && no_ladder_b ) {
                    ret = min(ret, dp[level - 1][a][b]);
                }

                // delete ladder at level (if meaningful only)
                if (!no_ladder_b && dp[level - 1][a][b] != -1)
                    ret = min(ret, dp[level - 1][a][b] + x);

                // build new between level ~ level+1 (cost y)
                for (int prev = 1; prev <= n; ++prev) {
                    if (prev == b) continue;
                    ret = min(ret,
                        dp[level - 1][a][prev] + cal_add_cost(prev, b, ladder[level]));
                }

                if (ret == INF)
                    ret = -1;
            }
        }
    }

    cout << dp[m][A][B] << endl;
}