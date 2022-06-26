#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n ,m;



int main()
{
	cin >> n;
	vector<int> card(n,0);
	for (int i=0; i<n; i++)
		cin >> card[i];
	cin >> m;
	vector<int> num(m,0);
	vector<int> cnt(m,0);
	for (int i=0; i<m; i++)
		cin >> num[i];
	
	
	sort(card.begin(), card.end());
	vector<int>::iterator low, high;
	for (int i=0; i<m; i++)
	{
		int target = num[i];
		low = lower_bound(card.begin(), card.end(), target);
		high = upper_bound(card.begin(), card.end(), target);
		cout << high-low <<" ";
	}
	cout << endl;

}