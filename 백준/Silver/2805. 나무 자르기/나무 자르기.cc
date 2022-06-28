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

class Functor {

public:
    ll sum, size;

    Functor(ll _size) :sum(0), size(_size) {}

    void operator()(const int &a) {
        sum += a / size;
    }
};

ll fun(const vector<ll>& trees, ll h)
{
    ll ret = 0;
    for (int tree : trees) {
        ret += (tree > h) ?  tree-h : 0;
    }

    return ret;
}

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    ll n, m; cin >> n >> m;
    vector<ll> trees(n);

    for (int i = 0; i < n; ++i)
        cin >> trees[i];

    ll ans = 0;
    ll lo =0, hi = 1000000000LL;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;

        ll len = fun(trees, mid);

        if (len >= m) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

}