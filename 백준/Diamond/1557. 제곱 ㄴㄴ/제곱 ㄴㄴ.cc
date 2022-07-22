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
const int INF = 1987654321;
const int MAX = 100000;

// 백만까지의 소수들
vector<ll> primes;

void makePrimes() 
{
    vector<bool> isPrime(MAX+1, true);
    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i]) {
            primes.push_back((ll)i*i);
            for (ll j = (ll)i * i; j <= MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
// 1~num까지 제곱수로 나누어 떨어지느 ㄴ수
ll lessThan(int idx, ll div, ll num);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);

    makePrimes();
    ll k; cin >> k;

    ll ans = -1;
    ll lo = 1, hi = INT_MAX;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll cnt = mid- lessThan(0,1,mid);
        if (cnt >= k) {
            hi = mid-1;
            ans = mid;
        }
        else
            lo = mid +1;
    }

    assert(ans != -1);
    cout << ans << '\n';
}

// 1~num까지 제곱수로 나누어 떨어지느 ㄴ수
ll lessThan(int idx, ll div, ll num) 
{
    if (idx >= primes.size()) return 0;
    if (div * primes[idx] > num) return 0;
    int ret = 0;
    
    ret += num / (div * primes[idx]);
    ret += lessThan(idx + 1, div, num);
    ret -= lessThan(idx + 1, div * primes[idx], num);
    return ret;
}
