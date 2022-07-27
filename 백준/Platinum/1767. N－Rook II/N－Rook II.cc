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
const ll MOD = 1000001;

int N, M, K;
ll dp[101][101][101];

ll fun(int n, int m, int k);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N >> M >> K;
    memset(dp, -1, sizeof(dp));
    cout << fun(N, M, K) << el;
}

ll fun(int n, int m, int k) {
    if (k == 0) return 1;
    if (n <= 0 || m <= 0 || k < 0) return 0;

    ll &ret = dp[n][m][k];
    if (ret != -1) return ret;

    // 0, 1, 1위에서공격, 2
    ret = fun(n - 1, m, k);
    ret += fun(n - 1, m - 1, k-1) * m; ret %= MOD;
    ret += fun(n - 2, m - 1, k - 2) * (n - 1) * m; ret %= MOD;
    ret += fun(n - 1, m - 2, k - 2) * m * (m - 1) / 2; ret %= MOD;
    return ret;
}