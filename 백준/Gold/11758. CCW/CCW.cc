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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const long long INF = -987654321;


int fun(int x1, int x2, int x3, int y1, int y2 ,int y3) 
{
	int v1[] = {x2-x1, y2-y1, 0};
	int v2[] = {x3-x1, y3-y1, 0};
	
	return v1[0]*v2[1] - v1[1]*v2[0];
}




int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int x1, x2, x3, y1, y2 ,y3;
	cin >> x1 >> y1 >> x2 >>y2 >>x3 >>y3;

	int ans = fun(x1,x2,x3,y1,y2,y3);
	if (ans>0)
		ans = 1;
	else if (ans==0)
		ans =0;
	else
		ans = -1;
	cout << ans << endl;
}