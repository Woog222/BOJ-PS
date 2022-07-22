#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

int cache[1000][1000];

int fun(const string& s, int lo, int hi);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

    string s; cin >> s;
    memset(cache, -1, sizeof(cache));
    int n = s.length();
    cout << fun(s,0, n-1) << '\n';
}

int fun(const string& s, int lo, int hi)
{
    if (lo == hi)
        return 1;
    if (lo + 1 == hi)
        return (s[lo] == s[hi]) ? 3 : 2;

    int& ret = cache[lo][hi];
    if (ret != -1)
        return ret;

    if (s[lo] == s[hi]) {
        ret = (fun(s, lo + 1, hi) + fun(s, lo, hi - 1) +1 ) % MOD;
        return ret;
    }
    ret = (fun(s, lo + 1, hi) + fun(s, lo, hi - 1)) % MOD;
    ret = (ret + MOD - fun(s, lo + 1, hi - 1) ) % MOD;
    return ret;
}