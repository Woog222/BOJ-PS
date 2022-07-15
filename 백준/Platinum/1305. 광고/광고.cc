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
const int MOD = 127;
const int BASE = 256;

inline int MAX(int a, int b) {
	return (a>b) ? a: b;
}
inline int MIN(int a, int b) {
	return (a<b) ? a: b;
}

void make_fail_fun(vector<int> &f, const string& p) 
{
	f[0] = 0;
	int m = f.size();
	int begin = 1, matched = 0;
	
	while ( begin + matched < m ) 
	{
		if ( p[begin+matched] == p[matched] ) {
			++matched;
			f[begin+matched-1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - f[matched-1];
				matched = f[matched-1];
			}
				
		}
	}
}


int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n; string p;
	cin >> n;
	cin >> p;


	vector<int> fail(p.size());
	make_fail_fun(fail, p);
	
	
	
	
	cout << n - fail[n-1] <<'\n';

}