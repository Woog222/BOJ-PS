#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 987654321;

struct Edge {
	int  to ,weight;
	
	Edge( int _to=0, int _weight=0) : 
	to(_to), weight(_weight) {}
	
	friend bool operator>(const Edge &a, const Edge &b) {
		return a.weight > b.weight;
	}
};

int dist[20000];
int Prev[20000];
int how[20000];
string bfs(int k) 
{
	/// 초기화
	for (int i=0; i<k; ++i)
		dist[i] = Prev[i] = how[i] = 0;
	
	
	// bfs
	queue<int> q;
	q.push(1);
	dist[1] = 1;
	how[1] = 1;
	
	
	while (!q.empty()) {
		int num = q.front(); q.pop();
		//cout << num << " ";
		
		int next = num*10 % k;
		if ( dist[next]==0 ) {
			dist[next] = dist[num]+1;
			q.push(next);
			Prev[next] = num;
			how[next] = 0;
		}

		
		next = (num*10+1) %k;
		if ( dist[next]==0 ) {
			dist[next] = dist[num]+1;
			q.push(next);
			Prev[next] = num;
			how[next] = 1;
		}
	}
	
	if (dist[0] == 0) 
		return string("BRAK");
	
	
	char temp[dist[0]+1];
	
	char c;
	int before = 0;
	for (int i=dist[0]-1; i>=0 ; --i) {
		c = (char) '0' + how[before];
		before = Prev[before];
		temp[i] = c;
	}
	temp[dist[0]] = '\0';
	
	return string(temp);
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	

	
	while (n--) {
		int k; cin >> k;
		// 출력
		cout << bfs( k) << '\n';
	}

}