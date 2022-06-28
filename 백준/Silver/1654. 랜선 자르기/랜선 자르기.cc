#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <deque>
#include <cstdlib>
using namespace std;

int max_wire(const vector<long long> &wires, int size)
{
	int res =0;
	for (auto wire : wires) {
		res += wire/size;
	}
	return res;
}


int main()
{
	int n, k;
	cin >> k >> n;
	vector<long long> base(k);
	
	long long temp;
	long long low = 1, high = 0;
	for (int i=0; i<k; ++i) {
		cin >> temp;
		high = (high > temp) ? high : temp;
		base[i] = temp;
	}

	long long ans = -1;
	
	while ( low <= high )
	{
		long long mid = (low+high)/2;
		if ( max_wire(base, mid) >= n)
		{
			ans = mid;
			low = mid+1;
		}
		else {
			high = mid-1;
		}
	}

	cout << ans << endl;
}