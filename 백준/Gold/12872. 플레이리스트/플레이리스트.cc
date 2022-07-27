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
const ll MOD = 1000000007;

int N, M, P;
ll cache[101][101];


ll fun(int p, int added);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N >> M >> P;
    memset(cache, -1, sizeof(cache));
    cout << fun(0, 0) << el;
}

ll fun(int p, int added) 
{
    int y = N - added;
    if (p == P) 
        return y == 0;
    

    ll& ret = cache[p][added];
    if (ret != -1) return ret;

    ret = 0;
    ret += fun(p + 1, added + 1) * y;
    if (added - M > 0) ret+= fun(p + 1, added) * (added - M);
    
    ret %= MOD;
    return ret;
}