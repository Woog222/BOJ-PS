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

int n;
string s;

int cal(vector<int> &nums ,vector<char> &ops, int op_len) // len : 연산자 갯수
{
	int ans = nums[0];

	for (int i=0; i<op_len; ++i) {
		char op = ops[i];
		if (op == '+') ans += nums[i+1];
		else if (op == '-') ans -= nums[i+1];
		else if (op == '*' ) ans *= nums[i+1];
	}
	
	/*
	cout << "nums:\n";
	for (int i = 0; i<op_len+1; ++i) {
		cout << nums[i] << " ";
	}
	cout << "\nops:\n";
	for (int i = 0; i<op_len; ++i) {
		cout << ops[i] << " ";
	}
	cout << "ans : " << ans <<endl;
	*/
	return ans;
}

vector<int> nums(10);
vector<char> ops(10);
int fun(int idx, int op_len) {
	// basis case
	if (idx== n-1) {
		nums[op_len] = s[idx]-'0';
		
		return cal(nums, ops, op_len);
	}
	
	int res = 1<<31;
	if (idx == n-3 ) {
		// 괄호 침
		char op = s[idx+1];
		if (op == '+') nums[op_len] = (int)(s[idx]-'0') + (int)(s[idx+2]-'0');
		else if (op == '-') nums[op_len] = (int)(s[idx]-'0') - (int)(s[idx+2]-'0');
		else if (op == '*' ) nums[op_len] = (int)(s[idx]-'0') * (int)(s[idx+2]-'0');
		
		res = MAX(res, cal(nums, ops, op_len) );
	}
	if (idx <= n-3) { 
		
		// 괄호 안침
		nums[op_len] = s[idx]-'0';
		ops[op_len] = s[idx+1];
		res = MAX(res, fun(idx+2, op_len+1) );	
	}
	if (idx <= n-5) { // 괄호 침
		char op = s[idx+1];
		if (op == '+') nums[op_len] = (int)(s[idx]-'0') + (int)(s[idx+2]-'0');
		else if (op == '-') nums[op_len] = (int)(s[idx]-'0') - (int)(s[idx+2]-'0');
		else if (op == '*' ) nums[op_len] = (int)(s[idx]-'0') * (int)(s[idx+2]-'0');
		ops[op_len] = s[idx+3];
		res = MAX(res, fun(idx+4, op_len+1) );
	}
	
	return res;
}

int main()
{
	cin >> n >> s;
	cout << fun(0,0) << endl;
}