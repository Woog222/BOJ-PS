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
#include <ctime>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
const ll INF = INT32_MAX;
const ll MOD = 20090711;

ll n, m;
bool possible(const vector<ll>& loc, ll d)
{
    ll left = m;
    ll cur = loc[0] - d;
    for (int x : loc) {
        if (x >= cur + d) {
            cur = x;
            left--;
        }
        if (left == 0) break;
    }

    return left == 0;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<ll> loc(n);
    for (int i = 0; i < n; ++i)
        cin >> loc[i];

    sort(loc.begin(), loc.end());


    ll ans = 0;
    ll lo = 1, hi = 1000000000;

    while (lo <= hi) 
    {
        ll mid = (lo + hi) / 2;

        if (possible(loc, mid)) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

}