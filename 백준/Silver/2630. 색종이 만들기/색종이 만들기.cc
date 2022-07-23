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


int grid[128][128];

pii fun(int r, int c, int len);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    pii ans = fun(0, 0, n);
    cout << ans.first << '\n' << ans.second << endl;
}

pii operator + (const pii& a, const pii& b) {
    return pii(a.first + b.first, a.second+ b.second);
}
// {0,1}
pii fun(int r, int c, int len)
{
    if (len == 1) {
        return grid[r][c] ? pii(0, 1) : pii(1, 0);
    }
    bool ok = true;
    int val = grid[r][c];
    for (int i=0; i<len; ++i)
        for (int j=0; j<len; ++j)
            if (grid[i + r][j + c] != val) {
                ok = false;
                i = len; break;
            }

    if (ok)
        return val ? pii(0, 1) : pii(1, 0);

    pii ret = { 0,0 };
    int nlen = len / 2;
    ret = ret + fun(r, c, nlen);
    ret = ret + fun(r, c + nlen, nlen);
    ret = ret + fun(r + nlen, c, nlen);
    ret = ret + fun(r + nlen, c + nlen, nlen);
    return ret;
}