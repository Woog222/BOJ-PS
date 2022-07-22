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
string s;

int fun(int lo, int hi);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);

   cin >> s;
    memset(cache, -1, sizeof(cache));
    int n = s.length();
    cout << fun(0, n-1) << '\n';
}

int fun(int lo, int hi)
{
    if (lo == hi)
        return 1;
    if (lo + 1 == hi)
        return (s[lo] == s[hi]) ? 3 : 2;

    int& ret = cache[lo][hi];
    if (ret != -1)
        return ret;

    if (s[lo] == s[hi]) {
        ret = fun(lo + 1, hi) + fun(lo, hi - 1) + 1;
        return ret;
    }
    ret = fun(lo + 1, hi) + fun(lo, hi - 1) - fun(lo + 1, hi - 1);
    return ret;
}