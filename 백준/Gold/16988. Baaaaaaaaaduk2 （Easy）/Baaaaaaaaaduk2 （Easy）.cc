#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

inline int MAX(int a, int b) {
	return (a>b) ? a: b;
}
inline int MIN(int a, int b) {
	return (a<b) ? a: b;
}

struct Point{
	int r, c;
	
	friend bool operator==(Point p1, Point p2) {
		return ( p1.r==p2.r && p1.c==p2.c );
	}
};

int dr[] = {0,0,1,-1};
int dc[] = {1,-1,0,0};
int n, m;
int map[20][20];
bool visit[20][20];

inline bool valid(int r, int c) {
	return !(r<0 || r>=n || c<0 || c>=m);
}

int dfs(int r, int c, queue<Point> &q)
{
	q.push(Point{r,c});
	map[r][c] = -2;
	
	int res = 1;
	for (int i=0; i<4; ++i) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (valid(nr, nc) && map[nr][nc] == 2 )
			res += dfs(nr, nc, q);
	}
	return res;
}

bool is_dead(vector<Point> &adjacent, Point p1, Point p2)
{
	bool res = true;
	
	for (Point adj : adjacent) {
		if ( !(adj == p1) && !(adj == p2) ) {
			res = false; break;
		}
	}
	
	return res;
}


int main()
{
	cin >> n >> m;
	vector<vector<Point>> adjacents(n*m);
	vector<int> group_size;
	
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> map[i][j];
		}
	}
	
	//cout << "checkPoint 1\n";
	
	int group_num =0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if ( map[i][j] == 2 )
			{
				queue<Point> group;
				group_size.push_back( dfs(i,j,group) ); // 그룹 다 돌면서 큐에 넣고 -2로 (처리완료한 적돌)
				
				//cout << group_num <<" : dfs done\n";
				
				memset(visit, false, sizeof(visit));
				while(!group.empty()) { //그룹 싹다 큐에서 빼면서 인접한 곳 체크
					Point p = group.front(); group.pop();
					
					for (int i=0; i<4; ++i) {
						int nr = p.r + dr[i];
						int nc = p.c + dc[i];
						if (valid(nr, nc) && !visit[nr][nc] && map[nr][nc] == 0) {
							adjacents[group_num].push_back(Point{nr,nc});
							visit[nr][nc] = true;
						}
					} // for
				} // while
				group_num++;
			}				
		} // j
	} // i
	
	//cout << "check Point2\n";
		
		
		
		
	int ans = 0;
	int size = n*m;
	for (int a=0; a<size; ++a) {
		for (int b=0; b<size; ++b) 
		{
			if (a == b) continue;
			
			int r1 = a/m, c1 = a%m;
			int r2 = b/m, c2 = b%m;
			if ( map[r1][c1]!= 0 || map[r2][c2] != 0 )
				continue;
			
			int temp_ans = 0;
			Point p1 = {r1, c1}, p2 = {r2, c2};
			for (int i = 0; i<group_num; ++i) {
				if ( is_dead(adjacents[i], p1, p2) )
					temp_ans += group_size[i];
			}
			
			ans = MAX(ans, temp_ans);
		}
	}
	
	cout << ans<< endl;
}