#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
int map[2187][2187];
int dr[] = {0,0,0,1,1,1,2,2,2};
int dc[] = {0,1,2,0,1,2,0,1,2};
typedef tuple<int, int, int> ret;

ret fun( int map[2187][2187], int r, int c, int size )
{	
	int val = map[r][c];
	{
	int r_last = r+size;
	int c_last = c+size;
	for (int i=r; i<r_last; ++i) {
		for (int j=c; j<c_last; ++j) {
			if(val!= map[i][j]) {
				val = 10; 
				i = r_last; // double_for loop break;
				break; // 10이면 일정하지 않다는 뜻
			}			
		}
	}
	} // Scope Bracket
	
	/* Basis Case(size 1 인 경우도 처리가능) */
	if (val!= 10) {
		int a = (val == -1) ? 1 : 0;
		int b = (val == 0) ? 1 : 0;
		int c = (val == 1) ? 1 : 0;
		return make_tuple(a,b,c);
	} // 하나의 수로 이루어져있다.
	
	int cnt_minus = 0, temp_minus =0;
	int cnt_zero = 0, temp_zero = 0;
	int cnt_plus = 0, temp_plus = 0;

	for (int i=0; i<9; i++)
	{
		int nsize = size/3;
		int nr = r + dr[i]*nsize; 
		int nc = c + dc[i]*nsize;
		tie(temp_minus, temp_zero, temp_plus) = fun(map,nr,nc,nsize);
		cnt_minus += temp_minus;
		cnt_zero += temp_zero;
		cnt_plus += temp_plus;	
	}

	return make_tuple(cnt_minus, cnt_zero, cnt_plus);	
} // (-1,0,1) 갯수

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> map[i][j];
	    }	
	}
	int a, b, c;
	tie(a,b,c) = fun(map,0,0,n);
		
	cout << a <<endl;
	cout << b<< endl;
	cout << c<<endl;
}