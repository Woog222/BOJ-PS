#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n;
void star(vector<vector<char>> &a, int r, int c, int size, bool blank)
{
	if (size==1)
	{
		if (blank) {
			a[r][c] = ' '; return;
		}
		else{
			a[r][c] = '*'; return;
		}
	}
	
	int nsize = size/3;
	if(blank) {
		for (int i=r; i<r+size; ++i) {
			for (int j=c; j<c+size; ++j) {
				a[i][j] = ' ';
			}
		}
	}
	else {
		for (int i=0; i<3; ++i) {
			for (int j=0; j<3; ++j) {
				if (i==1 && j==1)
					star(a, r+i*nsize, c+j*nsize, nsize, true);
				else
					star(a, r+i*nsize, c+j*nsize, nsize, false);
			}
		}
	}
}
int main()
{
	cin >> n;
	vector<vector<char>> a(n, vector<char>(n,0));
	star(a, 0,0,n, false);
	for (int i = 0; i<n; ++i)
	{
		cout << string(a[i].begin(), a[i].end()) << '\n';
	}
}