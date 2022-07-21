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

class Vector {
	public:
	double a, b, c;
	Vector(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
	
	friend Vector operator *(Vector v1, Vector v2) {
		return Vector( v1.b*v2.c- v1.c*v2.b , v1.c*v2.a-v1.a*v2.c ,
					 v1.a*v2.b- v1.b*v2.a);
	}
	
	double size() {
		return  c/2;
	}
};





int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int x1, y1,x2,y2, x3,y3, x4, y4;
	cin >> x1>> y1>>x2>>y2>> x3>>y3>> x4>> y4;
	
	bool ans = true;
	{
		Vector v(x2-x1, y2-y1, 0);
		Vector v1(x3-x1, y3-y1, 0);
		Vector v2(x4-x1, y4-y1, 0);
		if ( (v* v1).size() * (v*v2).size() > 0)
			ans = false;
	}
	
	{
		Vector v(x4-x3, y4-y3, 0);
		Vector v1(x2-x3, y2-y3, 0);
		Vector v2(x1-x3, y1-y3, 0);
		if ( (v* v1).size() * (v*v2).size() > 0)
			ans = false;			
	}
	
	cout << ans << endl;
}