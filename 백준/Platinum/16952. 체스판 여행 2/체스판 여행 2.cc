#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;


struct state {
	int level, who, r, c;

	state(int a, int b, int x, int y) :
		level(a), who(b), r(x), c(y) {}
};

int n;
int grid[10][10];
pii dist[101][3][10][10]; // s번째 수 완료, 나이트, 비솝,룩 / 그리고 위치
int dr[] = { -2,-1, 1, 2, 2, 1,-1,-2 };
int dc[] = { 1, 2, 2, 1,-1,-2,-2,-1 };
int br[] = { 1, 1,-1,-1 };
int bc[] = { 1,-1, 1,-1 };
int rr[] = { 0, 0, 1,-1 };
int rc[] = { 1,-1, 0, 0 };

inline bool valid(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < n;
}

void knight(queue<state>& q, state& cur)
{
	auto& d = dist[cur.level][cur.who][cur.r][cur.c];
	for (int i = 0; i < 8; ++i) {
		int nr = cur.r + dr[i];
		int nc = cur.c + dc[i];
		if (!valid(nr, nc))
			continue;

		int new_level = cur.level;
		if (grid[nr][nc] == cur.level + 1)
			new_level++;
		auto np = make_pair(d.first + 1, d.second);
		if (dist[new_level][cur.who][nr][nc].first == -1 ||
			np< dist[new_level][cur.who][nr][nc]) {
			dist[new_level][cur.who][nr][nc] = np;
			q.push(state(new_level, cur.who, nr, nc));
		}
	}
}

void bishop(queue<state>& q, state& cur)
{
	auto& d = dist[cur.level][cur.who][cur.r][cur.c];
	for (int i = 0; i < 4; ++i) {
		int nr = cur.r + br[i];
		int nc = cur.c + bc[i];

		while (valid(nr, nc)) {
			int new_level = cur.level;
			if (grid[nr][nc] == cur.level + 1)
				new_level++;

			auto np = make_pair(d.first + 1, d.second);
			if (dist[new_level][cur.who][nr][nc].first == -1 ||
				np < dist[new_level][cur.who][nr][nc]) {
				dist[new_level][cur.who][nr][nc] = np;
				q.push(state(new_level, cur.who, nr, nc));
			}
			nr += br[i];
			nc += bc[i];
		}
	}
}

void rook(queue<state>& q, state& cur)
{
	auto& d = dist[cur.level][cur.who][cur.r][cur.c];
	for (int i = 0; i < 4; ++i) {
		int nr = cur.r + rr[i];
		int nc = cur.c + rc[i];
		while (valid(nr, nc)) {
			int new_level = cur.level;
			if (grid[nr][nc] == cur.level + 1)
				new_level++;

			auto np = make_pair(d.first + 1, d.second);
			if (dist[new_level][cur.who][nr][nc].first == -1 ||
				np < dist[new_level][cur.who][nr][nc]) {
				dist[new_level][cur.who][nr][nc] = np;
				q.push(state(new_level, cur.who, nr, nc));
			}
			nr += rr[i];
			nc += rc[i];
		}
	}
}

pii bfs(int who, pii start)
{
	for (int i = 0; i <=n*n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					dist[i][j][k][l] = make_pair(-1, -1);
				}
			}
		}
	}

	int r, c;
	tie(r, c) = start;
	queue<state> q;
	for (int k = 0; k < 3; ++k) {
		q.push(state(1, k, r, c));
		dist[1][k][r][c] = pii(0, 0);
	}

	vector<pii> cand;

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		auto& d = dist[cur.level][cur.who][cur.r][cur.c];

		if (cur.level == n * n) {
			cand.push_back(dist[cur.level][cur.who][cur.r][cur.c]);
			continue;
		}

		// knight
		if (cur.who == 0) {
			knight(q, cur);
		}
		// bishop 
		else if (cur.who == 1) {
			bishop(q, cur);
		}
		// rook
		else {
			rook(q, cur);
		}
		// change
		for (int i = 0; i < 3; ++i) {
			auto np = make_pair(d.first+1, d.second+1);
			if (dist[cur.level][i][cur.r][cur.c].first == -1 ||
				np < dist[cur.level][i][cur.r][cur.c]) {
				dist[cur.level][i][cur.r][cur.c] = np;
				q.emplace(state(cur.level, i, cur.r, cur.c));
			}
		}
	}

	sort(cand.begin(), cand.end());
	return cand[0];
}


int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
	cin >> n;
	pii st;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				st.first = i;
				st.second = j;
			}
		}
	}

	auto p = bfs(0, st);

	cout << p.first << " " << p.second << endl;
}