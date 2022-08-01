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

int dp[10000][10];
int N;
string st, goal;

inline int toNumber(char c) {
    return c - '0';
}

int fun(int idx, int left)
{
    if (idx == N) return 0;
    int& ret = dp[idx][left];
    if (ret != -1) return ret;

    int now = (toNumber(st[idx]) + left) % 10;
    int l = (toNumber(goal[idx]) + 10 - now) % 10;
    int r = (now + 10 - toNumber(goal[idx])) % 10;

    ret = min(fun(idx+1, (left + l) % 10) + l, fun(idx + 1, left) + r);
    return ret;
}


int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> st >> goal;
    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0) << el;
}