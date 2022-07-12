#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

char grid[102][102];
int out[102][102];
int a[102][102];
int b[102][102];

int N, M;

void init();
vector<pii> makePrison();
void showPrison();
void bfs(int d[102][102], pii st);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        init();
        vector<pii> prisoners = makePrison();
        bfs(out, pii{ 0,0 });
        bfs(a, prisoners[0]);
        bfs(b, prisoners[1]);

        int ans = out[prisoners[0].first][prisoners[0].second] +
            out[prisoners[1].first][prisoners[1].second];

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (grid[i][j] == '*' || a[i][j]==-1 || b[i][j] == -1) 
                    continue;

                int temp = out[i][j] + a[i][j] + b[i][j];
                if (grid[i][j] == '#') temp -= 2;
                ans = min(ans, temp);
            }
        }
        
        cout << ans << '\n';
    }

}

void init()
{
    memset(out, -1, sizeof(out));
    memset(a, -1, sizeof(a));
    memset(b, -1, sizeof(b));
}

void showPrison()
{
    for (int i = 0; i <= N + 1; ++i) {
        for (int j = 0; j <= M + 1; ++j)
            cout << grid[i][j];
        cout << '\n';
    }
}

vector<pii> makePrison()
{
    cin >> N >> M;
    for (int i = 0; i <= N + 1; ++i)
        for (int j = 0; j <= M + 1; ++j)
            grid[i][j] = '.';

    vector<pii> ret;

    while (cin.get() != '\n');
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            grid[i][j] = cin.get();
            if (grid[i][j] == '$')
                ret.push_back(pii{ i, j });
        }
        while (cin.get() != '\n');
    }

    return ret;
}

inline bool valid(int r, int c) {
    return r >= 0 && r <= N + 1 && c >= 0 && c <= M+1;
}

void bfs(int d[102][102], pii st)
{
    deque<pii> q;
    q.push_back(st);
    d[st.first][st.second] = 0;

    while (!q.empty())
    {
        int r, c; tie(r, c) = q.front(); q.pop_front();

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!valid(nr, nc) || grid[nr][nc] == '*'|| d[nr][nc]!=-1)
                continue;

            if (grid[nr][nc] == '.' || grid[nr][nc] == '$') {
                q.emplace_front(nr, nc);
                d[nr][nc] = d[r][c];
            }
            else { // door
                q.emplace_back(nr, nc);
                d[nr][nc] = d[r][c] + 1;
            }
        }

    }
}