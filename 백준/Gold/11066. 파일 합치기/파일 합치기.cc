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

ll cache[501][501];
int s[501];
int ps[501];
int N;

ll fun(int lo, int hi);
int main() {

    int t; cin >> t;
    while (t--)
    {
        cin >> N;
        for (int i = 1; i <= N; ++i)
            cin >> s[i];
        for (int i = 1; i <= N; ++i) 
            ps[i] = ps[i - 1] + s[i];
        memset(cache, -1, sizeof(cache));
        cout << fun(1, N) << el;
    }

}

ll fun(int lo, int hi)
{
    if (hi - lo == 1)
        return s[lo] + s[hi];
    if (hi == lo)
        return 0;

    ll& ret = cache[lo][hi];
    if (ret != -1)
        return ret;

    ret = LLONG_MAX;
    for (int k = lo; k + 1 <= hi; ++k) {
        ret = min(ret, fun(lo, k) + fun(k + 1, hi) + ps[hi] - ps[lo-1]);
    }

    return ret;
}