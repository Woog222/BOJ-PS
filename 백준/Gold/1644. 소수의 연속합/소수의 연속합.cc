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
using namespace std;
const int INF = 987654321;

inline int MAX(int a, int b) {
	return (a>b) ? a: b;
}
inline int MIN(int a, int b) {
	return (a<b) ? a: b;
}
inline bool valid(int x, int y, int z) {
	return !(x<0 || y<0 || z<0 || x>=5 || y>=5 || z>=5);
}


int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int m;
	cin >> m;

	vector<bool> is_not_prime(m+1, false);
	vector<int> prime;
	
	for (int i=2; i<=m; ++i) {
		if (is_not_prime[i])
			continue;
		
		prime.push_back(i);
		for (int j= i*2; j<=m; j += i) {
			is_not_prime[j] = true;
		}		
	}

	prime.push_back(0);
	int i=0, j=0;
	long long sum = prime[j];
	int ans = 0;
	while (j<prime.size()-1)
	{
		if (sum > m){
			sum -= prime[i++];
		}
	 	else if (sum ==m) {
			ans += 1;
			sum += prime[++j];
		}
		else // sum < m
		{
			sum += prime[++j];
		}
	}
	
	
	if (ans == INF) ans = 0;
	cout << ans << endl;
}