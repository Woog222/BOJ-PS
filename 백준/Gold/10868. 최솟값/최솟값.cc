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
typedef vector <ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;


int N;
int arr[100000];
int dp[100000][17];

int query(int i, int j) {
    int ret = arr[i], k = 17;
    while (i <= j && k >= 0) {
        if (i + (1 << k) - 1 <= j) {
            ret = min(ret, dp[i][k]);
            i += 1 << k;
        }
        k--;
    }
    return ret;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    int m; cin >> N >> m;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) dp[i][0] = arr[i];
    for (int j = 1; j < 17; ++j) {
        for (int i = 0; i < N; ++i) {
            if (i + (1 << j) > N) break;
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (m--) {
        int i, j; cin >> i >> j;
        cout << query(i-1, j-1) << el;
    }
}