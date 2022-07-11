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

int n, m;

int cal( const vector<vector<int>> &a, const vector<vector<int>> &b )
{
	int res = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			res += a[i][j] * b[i][j];
		}
	}
	return res;
}
void change_row( vector<vector<int>> &a, const int p, const int q ) {
	vector<int> temp = a[p];
	a[p]= a[q];
	a[q] = temp;
}
void change_col( vector<vector<int>> &a, const int p, const int q ) {
	vector<int> temp(n);
	for (int i=0; i<n; ++i) {
		temp[i] = a[i][p];
		a[i][p] = a[i][q];
	}
	for (int i=0; i<n; ++i) {
		a[i][q] = temp[i];
	}
}

void show(vector<vector<int>> &a) {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cout << a[i][j] << " ";
		}
cout << endl;
	}
}

int main()
{
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m) );
	vector<vector<int>> b(n, vector<int>(m) );
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			cin >> a[i][j];
			b[i][j] = 4;
		}
	}
	for (int i=0; i<n; ++i) {
		b[i][0] = b[i][m-1] = 2;
	}
	for (int j=0; j<m; ++j) {
		b[0][j] = b[n-1][j] = 2;
	}
	b[0][0] = b[0][m-1] = b[n-1][0] = b[n-1][m-1] = 1;
	
	// biggest_col find
	int min_col_sum=INF;
	int col_idx;
	for (int j= 1; j<m-1; ++j) {
		int sum = 0;
		for (int i=0; i<n ; ++i)
			sum += a[i][j] * b[i][j];
		
		if (sum < min_col_sum) {
			col_idx = j;
			min_col_sum = sum;
		}
	}
	// biggest_int find
	int min_row_sum=INF;
	int row_idx;
	for (int i=1 ;i<n-1 ; ++i) {
		int sum = 0;
		for (int j= 0; j<m; ++j)
			sum += a[i][j] * b[i][j];
		
		if (sum < min_row_sum) {
			row_idx = i;
			min_row_sum = sum;
		}
	}

	// case1 : do nothing
	int ans = cal(a,b);
	
	// case2 : change col
	if (m > 2)
	{
		change_col(a, 0, col_idx);
		ans = MAX(ans, cal(a,b));
		change_col(a, 0, col_idx);

		change_col(a, m-1, col_idx);
		ans = MAX(ans, cal(a,b));
		change_col(a, m-1, col_idx);	
	}

		
		//cout << j << m-1 <<" : \n" << ans <<endl;


	//case3 : change_row
	if (n>2)
	{
		change_row(a, 0, row_idx);
		ans = MAX(ans, cal(a,b));
		change_row(a, 0, row_idx);

		change_row(a, n-1, row_idx);
		ans = MAX(ans, cal(a,b));
		change_row(a, n-1, row_idx);
	}
		

	
	cout << ans << endl;
} // main