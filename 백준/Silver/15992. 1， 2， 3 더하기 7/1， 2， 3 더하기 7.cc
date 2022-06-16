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
const int INF = 1000000001;
const int MOD = 1000000009;

int dp[1001][1001];





int main()
{
    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][3] = 1;
    dp[3][2] = 2;

    for (int i = 4; i <= 1000; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1]) % MOD;
            dp[i][j] = (dp[i][j] + +dp[i - 3][j - 1]) % MOD;
        }
    }

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
}
