#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 1000000001;

int dr[] = { 0, 0, 1,-1};
int dc[] = { 1,-1, 0, 0};
int cache[500][500];
int grid[500][500];
int n; 

inline bool valid(int r, int c) {
	return r>=0 && r<n && c>=0 && c<n;
}

int fun(int r, int c) 
{
	int &ret = cache[r][c];
	if (ret != -1)
		return ret;
	
	ret = 1;
	for (int i=0; i<4; ++i) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if (valid(nr, nc) && grid[nr][nc] > grid[r][c] ) {
			ret = max(ret, 1+ fun(nr, nc));
		}
	}
	
	return ret;
}

int main() 
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> grid[i][j];
		}
	}
	
	int ans = 0;
	memset( cache, -1, sizeof(cache));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			ans = max(ans, fun(i, j));
		}
	}
	
	cout << ans << endl;
}