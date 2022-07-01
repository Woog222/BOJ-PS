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
/*
inline bool valid(int r, int c){
	return !(r<0 || r>=n || c<0 || c>=m);
}
*/
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};


bool is_friend[4001][4001];
vector<int> map[4001];




int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	

	int n, m;
	cin >> n>>m;
	while (m--)
	{
		int a, b;
		cin >> a>>b;
		is_friend[a][b] = is_friend[b][a] = true;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	int ans = 20000;
	int a, b, c;
	for ( a=1; a<=n; ++a) {
		for (auto b : map[a]) {
			for (auto c : map[b] ) {
				if (is_friend[a][c])
				{
					int sum_of_friend = map[a].size()+map[b].size()+map[c].size()-6;
					ans = MIN(ans, sum_of_friend);
				}
			}
		}
	}
	
	if (ans == 20000) ans = -1;
	
	cout << ans <<endl;
	
}