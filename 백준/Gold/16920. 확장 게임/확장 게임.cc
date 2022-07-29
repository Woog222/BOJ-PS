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
int dist[1000][1000]; 
int s[10];
queue<pii> q[10];
int n, m, p;

inline bool valid(int r, int c) {
	return r>=0 && r<n && c>=0 && c<m;
}




int main() 
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	cin >> n >>m >> p;
	for (int i=1; i<=p; ++i)
		cin >> s[i];
	
	
	memset(dist, -1, sizeof(dist));
	vector<vector<char>> grid(n, vector<char>(m));
	while (cin.get()!='\n');
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			grid[i][j] = cin.get();
			if (grid[i][j] >= '1' && grid[i][j] <= '9') {
				q[ grid[i][j] -'0' ].emplace(i, j);
				dist[i][j] = 0;
			}
				
		}
		while (cin.get()!='\n');
	}
	
	for (int round = 1; ; ++round) {
		bool empty = true;
        
		for (int i=1; i<=p; ++i) {
			while (!q[i].empty()) {
				empty = false;
                
				int r, c;
				tie(r, c) = q[i].front();
		
				if (dist[r][c] == round*s[i]) break;
				q[i].pop();

				for (int k=0; k<4; ++k) {
					int nr = r+dr[k];
					int nc = c+dc[k];
					
					if (valid(nr, nc) && grid[nr][nc] == '.') {
						grid[nr][nc] = (char)(i + '0');
						dist[nr][nc] = dist[r][c]+1;
						q[i].emplace(nr, nc);
					}
				}
			}
		}
		
		if (empty) break;
	}

	vi ans(p);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (grid[i][j] >= '1' && grid[i][j] <= '9')
				ans[grid[i][j] - '1']++;
		}
	}

	for (int a : ans) 
		cout << a<< " ";
	cout << endl;
}