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

struct CCTV{
	int way[4];
	int type;
	pair<int, int> loc;
	CCTV(int _type, int r, int c)
	{
		if (_type==1) {
			way[0] = 1;
			way[1] = way[2] = way[3] = 0;	
		}
		else if (_type == 2) {
			way[0] = way[2] = 1;
			way[1] = way[3] = 0; 
		}
		else if (_type == 3) {
			way[0] = way[1] = 1;
			way[3] = way[2] = 0; 
		}
		else if (_type == 4) {
			way[0] = way[1] = way[2] = 1;
			way[3] = 0; 
		}
		else { // type == 5
			way[0] = way[1] = way[2] = way[3] = 1;
		}		
		type = _type;
		loc = make_pair(r,c);
	}
	
	vector<int> status(int k)
	{
		vector<int> temp(4);
		for (int i=0; i<4; ++i) {
			temp[i] = way[(4+i-k)%4];
		}
		return temp;
	}
};

int n, m, cctv_num, empty_room;
int map[8][8];
bool check[8][8];

void change(int r, int c, int dir, int &dead_angle)
{
	if (dir==0) {
		int nr = r-1;
		while (nr>=0 && map[nr][c] != 6){
			if (map[nr][c] == 0 && check[nr][c]==false) {
				dead_angle--; 
				check[nr][c] = true;
			}
			nr--;
		}
	}
	else if (dir == 1){
		int nc = c+1;
		while (nc<m && map[r][nc] != 6){
			if (map[r][nc] == 0 && check[r][nc]==false) {
				dead_angle--; 
				check[r][nc] = true;
			}
			nc++;
		}		
	}
	else if (dir==2) {
		int nr = r+1;
		while (nr<n && map[nr][c] != 6){
			if (map[nr][c] == 0 && check[nr][c]==false) {
				dead_angle--; 
				check[nr][c] = true;
			}
			nr++;
		}
	}
	else if (dir==3) { 
		int nc = c-1;
		while (nc>=0 && map[r][nc] != 6){
			if (map[r][nc] == 0 && check[r][nc]==false) {
				dead_angle--; 
				check[r][nc] = true;
			}
			nc--;
		}		
	}
} // r, c에 위치한 cctv dir 방향으로 이동하면서 감시제거


int main()
{
	cin >> n >> m;
	
	vector<CCTV> cctvs;
	for (int i=0; i<n; ++i){
		for (int j=0; j<m; ++j) {
			int temp;
			cin >> temp;
			if (temp == 0) empty_room++;
			else if (temp>=1 && temp<=5) {
				cctvs.push_back(CCTV(temp, i, j));
				cctv_num++;
			}		
			map[i][j] =temp;
		}
	}
	
	int last_mask = (1<< (cctv_num*2) ) -1;
	int ans = 987654321;
	for (int mask = 0; mask <= last_mask; ++mask) 
	{
		int dead_angle = empty_room;
		memset(check, false, sizeof(check));
		
		vector<int> way;
		for (int i=0; i<cctv_num; ++i) {
			int r,c;
			int direction = ( mask&(3<<(i*2)) ) >> (i*2);
			tie(r,c) = cctvs[i].loc;
			cctvs[i].status(direction).swap(way);
			
			for (int dir = 0; dir<4; ++dir) {
				if (way[dir]==0) continue;
				
				change(r, c, dir, dead_angle); // dir방향으로 벽만날때까지 false면 dead_angle--
			} //each direction						
			
		} // each cctv
		if (ans > dead_angle) {
			ans = dead_angle;
			
			/*
			for (int i=0; i<n; ++i){
				for (int j=0; j<m; ++j) {
					cout << check[i][j] << " ";
				}
				cout << '\n';
			}
			cout << "dead_angle : " << empty_room <<" - "<< empty_room-dead_angle<<'\n';
			*/
		}

	} // case(mask)
	cout << ans << endl;
}