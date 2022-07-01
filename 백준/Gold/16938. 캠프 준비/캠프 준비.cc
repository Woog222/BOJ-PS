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

int h,w,n;
bool check(pair<int, int> stk1, pair<int, int> stk2 )
{
	int r1, c1, r2, c2;
	tie(r1, c1) = stk1; tie(r2, c2) = stk2;
	
	int temp;
	if (h-c1>0) // case 1
	{
		temp = h-c1;
		if ( (r2 <= temp && c2<=w) || (c2<=temp && r2<=w) )
			return true;
	}
	if (h-r1>0)
	{
		temp = h-r1;
		if ( (r2 <= temp && c2<=w) || (c2<=temp && r2<=w) )
			return true;
	}
	if(w-r1>0)
	{
		temp = w-r1;
		if ( (r2 <= temp && c2<=h) || (c2<=temp && r2<=h) )
			return true;
	}
	if (w-c1 >0)
	{
		temp = w-c1;
		if ( (r2 <= temp && c2<=h) || (c2<=temp && r2<=h) )
			return true;
	}
	return false;
}



int main()
{
	int n, l ,r, x;
	cin >> n >> l >> r >> x;
	int level[n];
	for (int i=0; i<n; ++i)
		cin >> level[i];
	
	int ans = 0;
	int last_mask = (1<<n)-1;
	for (int mask =0; mask <= last_mask; ++mask) {
		
		int cnt = 0, sum = 0, hardest = 0, easiest = 987654321;
		for (int i=0; i<n; ++i) 
		{
			if ( mask & (1<<i) ) {
				cnt ++;
				int temp = level[i];
				sum += temp;
				hardest = MAX(hardest, temp);
				easiest = MIN(easiest, temp);
			}
		}
		
		if (cnt >=2 && sum>=l && sum<=r && (hardest-easiest)>=x)
			ans++;
	}
	
	cout << ans << endl;
}