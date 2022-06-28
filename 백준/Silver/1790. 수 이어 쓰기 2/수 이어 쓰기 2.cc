#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
#include <deque>
#include <cstdlib>
using namespace std;

int POW_10(int k)
{
	if (k==0) return 1;
	else return 10 * POW_10(k-1) ;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	long long num = 9, digits = 1;
	
	while (POW_10(digits-1)<=n)
	{
		//cout << k << " " << num << endl;
		if (k > num*digits) {

			k -= num * (digits++);
			num *= 10; 
		}
		else{
			int nth_num = POW_10(digits-1) + (k-1)/digits;
			int nth_digit = (k-1)%digits;
			//cout << nth_num << "의 " << nth_digit+1 << "번째 " << digits << endl;
			if (nth_num > n) break;

			int divider = POW_10(digits - nth_digit-1);
			cout << (nth_num / divider) % 10 << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}