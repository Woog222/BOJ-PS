#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n ,m;



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	vector<int> a(n,0);
	vector<int> b(m,0);
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<m; ++i)
		cin >> b[i];
	
	int i=0, j=0;	
	while(i<n && j<m)
	{
		if (a[i] <= b[j])
			cout << a[i++] << " ";
		else 
			cout << b[j++] << " ";
	}
	while(i<n)
		cout << a[i++] << " ";
	
	while(j<m)
		cout << b[j++] << " ";
	cout << endl;
}