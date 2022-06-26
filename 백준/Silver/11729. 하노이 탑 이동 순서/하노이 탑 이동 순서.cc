#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
int map[2187][2187];
int cache[21];
typedef tuple<int, int, int> ret;

void fun( int size, int from, int to)
{	
	if (size == 1) {
		cout << from << " " << to <<'\n';
		return;
	}
	
	int other = 6-from-to;
	fun(size-1, from, other);
	fun(1, from, to);
	fun(size-1, other, to);
} 

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	cache[1] = 1;
	for (int i=2; i<=n; ++i)
		cache[i] = 2*cache[i-1] + 1;
	
	cout << cache[n] << endl;
	fun (n, 1,3);
}
