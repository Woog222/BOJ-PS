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


int ladder[31][11]; // i번 높이 j번째 사다리, 0 이면 없고 잇으면 그 수로 이동.

void add_ladder(int height, int left) {
	ladder[height][left] = left+1;
	ladder[height][left+1] = left;
}
void del_ladder(int height, int left) {
	ladder[height][left] = 0;
	ladder[height][left+1] = 0;
}
bool is_identity(int height, int n) {
	
	for (int i=1; i <=n; ++i) { // 각 사다리
		int start = i;
		for (int level = 1; level<=height; ++level) { //시뮬레이션
			int to = ladder[level][start];
			if (to!= 0) 
				start = to;
		}
		if (start != i)
			return false;
	}
	
	return true;
}

int main()
{
	int n, m, h;
	cin >> n>> m>> h;
	
	for (int i=0; i<m; ++i) {
		int height, left;
		cin >> height >> left;
		ladder[height][left] = left+1;
		ladder[height][left+1] = left;
	}
	// 0
	if (is_identity(h, n)) {
		cout << 0 << endl;
		return 0;
	}
	
	vector<pair<int,int>> possible; // level, nth ladder
	for (int level=1; level<=h; ++level) {
		for (int nth = 1; nth<=n-1; ++nth) {
			if (ladder[level][nth]==0 && ladder[level][nth+1]==0)
				possible.emplace_back(level, nth);
		}
	}
	int size = possible.size();
	// 1
	for (int i=0; i<size; ++i) {
		int level, nth;
		tie(level, nth) = possible[i];
		
		add_ladder(level,nth);
		if (is_identity(h, n))
		{
			cout << 1<<endl;
			return 0;
		}
		del_ladder(level, nth);
	}
	
	// 2
	for (int i=0; i<size; ++i) {
		int level1, nth1;
		tie(level1, nth1) = possible[i];
		add_ladder(level1, nth1);
		
		for (int j=i+1; j<size; ++ j) {
			int level2, nth2;
			tie(level2, nth2) = possible[j];
			if (ladder[level2][nth2]==0 && ladder[level2][nth2+1]==0) {
				add_ladder(level2, nth2);
				if (is_identity(h, n))
				{
					cout << 2<<endl;
					return 0;
				}
				del_ladder(level2, nth2);
			}
		}
		
		del_ladder(level1, nth1);
	}
	
	// 3
	for (int i=0; i<size; ++i) {
		int level1, nth1;
		tie(level1, nth1) = possible[i];
		add_ladder(level1, nth1);
		
		for (int j=i+1; j<size; ++j) {
			int level2, nth2;
			tie(level2, nth2) = possible[j];
			if (ladder[level2][nth2]!=0 || ladder[level2][nth2+1]!=0) 
				continue;
			
			add_ladder(level2, nth2);
			
			for (int k=j+1; k<size; ++k) {
				int level3, nth3;
				tie(level3, nth3) = possible[k];
				if (ladder[level3][nth3]!=0 || ladder[level3][nth3+1]!=0) 
					continue;
			
				add_ladder(level3, nth3);
				if (is_identity(h, n))
				{
					cout << 3 <<endl;
					return 0;
				}
				del_ladder(level3, nth3);
			}
			
			del_ladder(level2, nth2);
		}
		
		del_ladder(level1, nth1);
	}
	
	
	
	
	cout << -1 << endl;
	
}