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
	int from, to ,weight;
	
	Edge(int _from=0, int _to=0, int _weight=0) : 
	from(_from), to(_to), weight(_weight) {}
	
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

vi graph[50001];
int parent[50001];
int depth[50001];


	
int lca(int u, int v)
{
	// WLOG, 항상 u가 더 깊다고 가정 
	if (depth[u] < depth[v]) {
		swap(u,v);
	}
	
	while (depth[u] != depth[v]) {
		u = parent[u];
	}
	
	while (u!=v) {
		u = parent[u];
		v = parent[v];
	}
	
	return u;
}


int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n ,m; 
	cin >> n;
	
	for (int i=1; i<n; ++i) {
		int u ,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	depth[1] = 1;
	parent[1] = 1;
	queue<int> q;
	q.push(1);
	
	while (!q.empty()) {
		int v = q.front(); q.pop();
		
		for ( int next : graph[v] ) {
			if (depth[next]) continue;
			
			depth[next] = depth[v]+1;
			parent[next] = v;
			q.push(next);
		}
	}
	
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

}