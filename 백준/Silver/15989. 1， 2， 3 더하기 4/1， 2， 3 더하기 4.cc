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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const int INF = 987654321;

inline int MAX(int a, int b) {
	return (a>b) ? a: b;
}
inline int MIN(int a, int b) {
	return (a<b) ? a: b;
}

int cache[10001][4];
int fun( int n, int big )
{
	int &ret = cache[n][big];
	if (ret!= -1)
		return ret;
	
	if (n<=3) {
		if (n==1 && big<=1) 
			return ret = 1;
		else if (n==2 && big<=2)
			return ret = 1;
		else if (n==3 )
			return ret = 1;
		else
			return ret = 0;
		
		// return ret = 1 로 최적화 가능
	}

	int res = 0;
	if (big == 3) {
		res += fun(n-3,1) + fun(n-3,2) + fun(n-3, 3);
	}
	else if (big == 2) {
		res += fun(n-2,1) + fun(n-2,2);
	}
	else {
		res += fun(n-1,1);
	}
	
	return ret = res;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	memset(cache, -1, sizeof(cache));
	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> num;
		cout << fun(num, 1) + fun(num,2) + fun(num,3) <<'\n';
	}
}