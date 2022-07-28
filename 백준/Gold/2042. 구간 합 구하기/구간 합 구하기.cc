#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;

void update(vi &tree, int idx, ll diff)
{	
	int n = tree.size()-1; // 0안쓰니깐
	while (idx <= n ) {
		tree[idx] += diff;
		idx += (idx & -idx);
	}
}

ll sum(vi &tree, int idx)
{
	ll ret = 0;
	while (idx >= 1) {
		ret += tree[idx];
		idx -= (idx&-idx);
	}
	
	return ret;
}


int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n, m, k; cin >> n >> m >> k;
	
	vi a(n+1);
	vi tree(n+1);
	for (int i=1; i<=n; ++i) {
		cin >> a[i];
		update(tree, i, a[i]);
	}
	
	int q = m+k;
	while (q--) {
		ll x,y,z;
		cin >> x >> y >> z;
		if (x==1) {
			ll diff = z - a[y];
			a[y] = z;
			update(tree, y, diff);
		}
		else {
			cout << sum(tree, z) - sum(tree, y-1) << '\n';
		}
	}

}