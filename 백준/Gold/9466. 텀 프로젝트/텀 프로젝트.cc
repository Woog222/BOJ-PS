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

int N;
int to[100001];
int cache[100001];

int dfs(int here);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int t; cin >> t;

    while (t--) {
        cin >> N;
        for (int i = 1; i <= N; ++i) cin >> to[i];

        memset(cache, -1, sizeof(cache));
        for (int i = 1; i <= N; ++i) 
            if (cache[i] == -1) dfs(i);
        
        int ans = 0;
        for (int i = 1; i <= N; ++i) ans += 1 - cache[i];
        cout << ans << el;
    }
 
}

int dfs(int here) 
{
    int& ret = cache[here];
    if (ret != -1) return ret;
    ret = -2;

    if (to[here] == here) {
        ret = 1;
        return 0;
    }

    int state = cache[to[here]];
    if (state == 1 || state == 0)
        return ret = 0;
    else if (state == -2) {
        ret = 1;
        return to[here];
    }
    else {
        int res = dfs(to[here]);
        if (res == 0) 
            return ret = 0;
        if (here == res) {
            ret = 1;
            return 0;
        }
        else {
            ret = 1;
            return res;
        }
    }
}