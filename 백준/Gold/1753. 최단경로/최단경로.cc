#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <deque>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const long long INF = 987654321;


struct Edge {
	int to, weight;
	Edge(int _to = 0, int _weight = 0)
		:to(_to), weight(_weight){}
	
	friend bool operator >( const Edge &a, const Edge &b) {
		return a.weight > b.weight;
	}
};

vector<Edge> graph[20001];
bool visit[20001];
int dist[20001];



int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	int n, m, start;
	cin >> n >> m >> start;
	while (m--) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].emplace_back(to, cost);
	}
	
	// 전처리
	for (int i=1; i<=n; ++i) 
		dist[ i] = INF;
	dist[start] = 0;
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	pq.push( Edge{start, 0} );

	int visited = 0;
	for (int i=1; i<=n; ++i) 
	{
		//다음 찾기
		while ( !pq.empty() ) {
			int next = pq.top().to; pq.pop();
			if (visit[next]) continue;
			
			visited = next;
			break;
		}
		visit[visited] = true;
		
		// 간선 거리 리셋
		for (Edge e : graph[visited]) {
			if (visit[e.to]) continue; //음의 가중치만 없다면 없어도됨, 어차피 갱신 안될 것
			if (dist[e.to] > dist[visited] + e.weight) {
				pq.push(Edge(e.to, e.weight+dist[visited]));
				dist[e.to] = dist[visited] + e.weight;
			}
		}		
		

	}
	
	for (int i=1; i<=n; ++i) {
		if (dist[i] == INF)
			cout << "INF ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
}