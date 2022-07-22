#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
const long long INF = -987654321;

void make_prime(vi &prime, const ll last) {
	
	bool not_prime[last+1] = {false, };
	
	for (int i=2; i<=last; ++i) {
		if ( not_prime[i] ) continue;
		
		prime.push_back(i);
		for (int j= i+i; j<=last; j+= i)
			not_prime[j] = true;
	}
}

ll fun(const ll n, const ll m) 
{
	int size = m-n+1;
	vi prime;
	make_prime(prime, (ll)sqrt(m));

	vi ans(size, 1);
	for (ll p : prime) {
		ll sqp = p*p;
		for (ll i= ((n+sqp-1)/sqp)*sqp; i<=m; i+= sqp)
			ans[i-n] = 0;
	}

	int cnt = 0;
	for (auto i : ans) 
		cnt += (i>0) ? 1 : 0;
	
	return cnt;
}




int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;

	cout << fun(n, m) << endl;
}