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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const int INF = 987654321;

struct Edge {
	int  to ,weight;
	
	Edge( int _to=0, int _weight=0) : 
	to(_to), weight(_weight) {}
	
	friend bool operator>(const Edge &a, const Edge &b) {
		return a.weight > b.weight;
	}
};

vvi operator *(const vvi &a, const vvi &b) {
	int size = a.size();
	
	vvi temp(size, vi(size));
	for (int i=0; i<size; ++i) {
		for (int j=0; j<size; ++j) {
			for (int k=0; k<size; ++k) {
				temp[i][j] = temp[i][j] | (a[i][k] & b[k][j]);
			}
		}
	}
	
	return temp;
}

int dp[200001][19];
const int l = 18;

int f (int n, int x)
{

	int k=0;
	while (n) {
		if (n&1) {
			//cout << x<<k<<"\n";
			x = dp[x][k];
		}
			
		k++; 
		n /= 2;
	}
	return x;
}



int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n ,m; 
	cin >> n;
	
	for (int i=1; i<=n; ++i) {
		int u;
		cin >> u;
		dp[i][0] = u;
	}
	
	for (int k = 1; k<=l; ++k) {
		for (int i=1; i<=n; ++i) {
			dp[i][k] = dp[ dp[i][k-1] ][ k-1 ];
		}
	}
	

	
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << f(u,v) << '\n';
	}

}