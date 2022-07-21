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
	int n; cin >> n;
	int a, b; cin >> a>>b;
	
	vector<Vector> v;
	for (int i=0; i<n-1; ++i) {
		int temp_x, temp_y;
		cin >> temp_x >> temp_y;
		v.emplace_back(temp_x-a, temp_y-b, 0);
	}

	double ans = 0;
	for (int i=0; i<v.size()-1; ++i) {
		ans += ( v[i]*v[i+1] ).size();
	}
	cout << fixed;
	cout.precision(1);
	cout << abs(ans) << endl;
}