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
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

int c[101];
int mem[101];
int dp[101][10001];

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> mem[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n * 100; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (c[i] <= j)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + mem[i]);
        }
    }

    for (int j = 0; j <= n * 100; ++j) {
        if (dp[n][j] >= m) {
            cout << j << el;
            return 0;
        }
    }
}