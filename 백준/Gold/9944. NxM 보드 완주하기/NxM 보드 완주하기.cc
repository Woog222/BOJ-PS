#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

inline int MIN(int a, int b) {
	return (a<b) ?a : b;
}
inline int MAX(int a, int b) {
	return (a>b) ?a : b;
}

int n, m;
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

inline bool valid(int r, int c){
	return !(r<0 || r>=n || c<0 || c>=m);
}
int fun(vector<string> &map, int r, int c, int left) // r, c부터 몇번 이동해야 다 치우는지
{
	if (left == 0) return 0;
	
	int res = 987654321;
	for (int i=0; i<4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		while(valid(nr, nc) && map[nr][nc]=='.' ){
			map[nr][nc] = '*'; 
			nr += dr[i];
			nc += dc[i];
			left--;
		}
		nr -= dr[i];
		nc -= dc[i];
		
		// 제자리는 아닌지
		if (nr != r || nc != c)
			res = MIN(res, 1+ fun(map, nr, nc, left ) );
		
		// 복귀
		while(nr!= r || nc != c ){
			map[nr][nc] = '.'; 
			nr -= dr[i];
			nc -= dc[i];
			left++;
		}
	}
	
	return res;
}

int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	
	int cnt = 1;
	while (true)
	{	
	cin >> n>>m;
	if ( cin.eof() ) break;
		
	vector<string> map(n, string(m, '.'));
	for (int i =0; i<n; ++i) 
		cin >> map[i];
	
	int empty=0;
	for (int i =0; i<n; ++i) {
		for (int j =0; j<m; ++j) {
			if (map[i][j] == '.') {
				empty++;
			}
		}
	}
	
	int ans = 987654321;
	for (int i =0; i<n; ++i) {
		for (int j =0; j<m; ++j) {
			if (map[i][j] == '.') {
				map[i][j] = '*';
				ans = MIN(ans, fun(map, i,j, empty-1) );//fun : 횟수, 불가능하면 987654321 return
				map[i][j] = '.';
			}
		}
	}
	if (ans == 987654321)
		ans = -1;
	cout << "Case " <<cnt++ <<": " << ans << endl;
	}
}