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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;



int fac[10];
int dist[400000];
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

void show(const vvi &matrix) {
	for (int i=0; i<100000000; ++i);

	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			cout << matrix[i][j] <<" ";
		}
		cout << "\n";
	}
		cout << '\n';
}

inline bool valid(int r, int c) {
	return (r>=0 && r<3 && c>=0 && c<3);
}

void cal() {
	fac[1]= 1;
	for (int i=2; i<=9; ++i)
		fac[i] = fac[i-1]*i;
}

int status(const vvi &puzzle) {
	vi temp;
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			temp.push_back( puzzle[i][j] );
		}
	}
	
	int order = 0;
	for (int i=0; i<8; ++i) {
		int cnt = 0;
		for (int j=i+1; j<9; ++j) {
			if (temp[i] > temp[j]) cnt++;
		}
		order += fac[9-i-1] * cnt;
	}
	
	return order;
}

int main() {
	//cin.tie(nullptr); ios_base::sync_with_stdio(false);
	vvi puzzle(3, vi(3));
	for (int i=0; i<3; ++i) {
		for (int j=0; j<3; ++j) {
			cin >> puzzle[i][j];
			if (puzzle[i][j] == 0)
				puzzle[i][j] = 9;
		}
	}
	cal();
	
	memset( dist, -1, sizeof(dist) );
	int s = status(puzzle);
	dist[s] = 0;
	queue<vvi> q;
	q.push(puzzle);
	
	while ( !q.empty() )
	{
		vvi cur = q.front(); q.pop();
		int cur_s = status(cur);
		if (cur_s == 0) {
			cout << dist[cur_s] << endl;
			return 0;
		}
		
		// 9위치 찾기
		int r, c;
		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				if (cur[i][j] == 9) {
					r=i; c=j; 
					i = 3; break;
				}
			}	
		}
		
		// 탐색
		for (int i=0; i<4; ++i) {
			int nr = r+dr[i]; 
			int nc = c+dc[i];
			if ( !valid(nr, nc) ) continue;
				
			swap(cur[nr][nc], cur[r][c]);
			int ns = status(cur);
			if (dist[ns] == -1 )  {

				dist[ns] = dist[cur_s]+1;
				q.push(cur);								
			}
			swap(cur[nr][nc], cur[r][c]);
		}
	}	

	cout << -1 << endl;
}