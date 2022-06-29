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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 1987654321;



ll N;
ll fun(ll num);

int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);

    cin >> N;
    ll k; cin >> k;

    ll lo = 1, hi = N * N;
    ll ans = hi;
    while (lo <= hi)
    {
        ll mid = (hi + lo) / 2;

        // mid까지의 개수
        ll cnt = fun(mid);
        //cout << mid << " : " << cnt << endl;
        if (cnt >= k) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }

    }

    cout << ans << endl;
    
}


ll fun(ll num)
{
    ll ret = 0;

    for (ll i = 1; i <= min(N, num); ++i) {
        ret += min(num / i, N);
    }

    return ret;
}