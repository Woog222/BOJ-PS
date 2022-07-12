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
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);	
	for (int i=0; i<n; ++i )
		cin >> a[i] >> b[i] >> c[i] >> d[i];	
	
	// 배열 합 전부 넣기
	vector<int> a_sum, b_sum;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n ; ++j){
			a_sum.push_back(a[i]+b[j]);
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n ; ++j){
			b_sum.push_back(c[i]+d[j]);
		}
	}
	
	// Sorting
	sort(a_sum.begin(), a_sum.end());
	sort(b_sum.begin(), b_sum.end());


	// Two Pointer
	long long ans = 0;
	int a_idx=0, b_idx=b_sum.size()-1;
	int a_size = a_sum.size();
	while( a_idx < a_size && b_idx >= 0 )
	{
		int temp = a_sum[a_idx] + b_sum[b_idx];
		if (temp == 0) {
			int a_s = a_sum[a_idx];
			int b_s = b_sum[b_idx];
			long long a_cnt = 1, b_cnt=1;
			while(++a_idx<a_size && a_sum[a_idx] == a_s)
				a_cnt++;
			while(--b_idx>=0 && b_sum[b_idx] == b_s)
				b_cnt++;
			
			ans += a_cnt * b_cnt;
		}
		else if (temp < 0) {
			a_idx++;
		}
		else {
			b_idx--;
		}
	}

	cout << ans << endl;
} // main