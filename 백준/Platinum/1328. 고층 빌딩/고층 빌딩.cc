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

ll dp[101][101][101];

ll fun(int n, int l, int r) {
    if (l + r - 1 > n) return 0;
    if (l <= 0 || r <= 0) return 0;
    if (n == 1) {
        if (l == 1 && r == 1) return 1;
        else return 0;
    }


    ll& ret = dp[n][l][r];
    if (ret != -1) return ret;

    ret = 0;
    ret += fun(n - 1, l - 1, r); ret %= MOD;
    ret += fun(n - 1, l, r - 1); ret %= MOD;
    ret += fun(n - 1, l, r) * (n - 2); ret %= MOD;
    return ret;
}

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));
    int n, l, r; cin >> n >> l >> r;
    cout << fun(n, l, r) << el;
}