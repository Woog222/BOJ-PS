#include <iostream>
using namespace std;

int p[1000001];
int RANK[1000001];
int n, m;


int FIND(int k)
{
	if (k == p[k])
		return k;
	
	return p[k] = FIND(p[k]);
}

void UNION(int a, int b)
{
	int root1 = FIND(a);
	int root2 = FIND(b); 
	if (root1 == root2) return;
	
	if ( RANK[root1] < RANK[root2] ) {
		p[root1] = root2;
	}
	else if (RANK[root1] > RANK[root2]) {
		p[root2] = root1;
	}
	else {
		p[root2] = root1;
		RANK[root1] += 1;
	}
	
}
int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<=n; ++i) {
		p[i] = i;
		RANK[i] = 0;
	}

	while (m--)
	{
		int command, x, y;
		cin >> command >> x>> y;
		
		if (command == 0)
			UNION(x, y);
		else {
			x = FIND(x);
			y = FIND(y);
			if (x==y)
				cout <<"YES\n";
			else
				cout <<"NO\n";
		}
	}
}