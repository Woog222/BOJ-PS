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


int N, M;
string grid[1500];
int dr[] = { 0, 0, 1,-1 };
int dc[] = { 1,-1, 0, 0 };
bool wvisit[1500][1500];
bool svisit[1500][1500];
queue<pii> w, nw, s, ns;
pii st = pii(-1, -1), e = pii(-1, -1);

inline bool valid(int r, int c) {
    return r >= 0 && r<N&& c >= 0 && c<M;
}

bool bfs();
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false); cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> grid[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == '.') {
                w.emplace(i, j);
                wvisit[i][j] = true;
            }
            else if (grid[i][j] == 'L') {
                grid[i][j] = '.';
                w.emplace(i, j);
                wvisit[i][j] = true;
                if (st.first == -1) st = pii(i, j);
                else e = pii(i, j);
            }
        }
    }

    s.push(st);
    svisit[st.first][st.second] = true;
    int cnt = 0;
    for (; ; ++cnt) if (bfs()) break;
    cout << cnt << el;
}

bool bfs()
{
    while (!w.empty()) {
        int r, c;
        tie(r, c) = w.front(); w.pop();
        grid[r][c] = '.';

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!valid(nr, nc) || wvisit[nr][nc])
                continue;

            if (grid[nr][nc] == 'X') {
                nw.emplace(nr, nc);
                wvisit[nr][nc] = true;
            }
            else if (grid[nr][nc] == '.') {
                assert(false);
                w.emplace(nr, nc);
                wvisit[nr][nc] = true;
            }
        }
    }
    while (!s.empty()) {
        int r, c;
        tie(r, c) = s.front(); s.pop();

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (!valid(nr, nc) || svisit[nr][nc])
                continue;

            if (grid[nr][nc] == 'X') {
                ns.emplace(nr, nc);
                svisit[nr][nc] = true;
            }
            else if (grid[nr][nc] == '.') {
                s.emplace(nr, nc);
                svisit[nr][nc] = true;
            }
        }
    }
    if (svisit[e.first][e.second]) return true;
    swap(s, ns);
    swap(w, nw);
    return false;
}