#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int n, a, b;

int fun(int r, int c, int size, int first)
{
	if (size==1) return first;
	
	int delta = (size*size)/4;
	int nsize = size>>1;
	
	if (r<= a && a < (r+nsize) ) {
		if (c <=b && b < (c+nsize) )
			return fun(r,c,nsize, first);
		else
			return fun(r,c+nsize, nsize, first+delta);
	}
	else {
		if (c <=b && b < (c+nsize) )
			return fun(r+nsize,c,nsize, first+2*delta);
		else
			return fun(r+nsize,c+nsize, nsize, first+3*delta);
	}
		
	
}

int main()
{
	cin >> n >> a >> b;
	cout << fun(0,0,(1<<n),0) << endl;
}