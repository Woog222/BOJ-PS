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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;

// 우 하 좌 상
char dir[] = {'R', 'D', 'L', 'U'};
int dr[] = { 0, 1, 0,-1 };
int dc[] = { 1, 0,-1, 0 };

pair<pii,pii> Prev[10][10][10][10];
int dist[10][10][10][10];
string grid[10];

int N, M;

pair<pii, pii> findRB(); // clear
// red only out : actual loc
// both out or blut out : r.first = -2
// just moved : location
pair<pii, pii> move(const pii r, const pii b, int k); // clear
// Prev 세팅하면서 bfs. 가능하면 최종 위치, 불가능하면 (1,0,0,0) 리턴
pair<pii, pii> bfs(pii r, pii b); 
void print_path(pii r, pii b);
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    pii r, b; tie(r, b) = findRB();
    pii final_r, final_b;
    tie(final_r, final_b) = bfs(r, b);

    if (final_r.first == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << dist[final_r.first][final_r.second][final_b.first][final_b.second] << '\n';
    print_path(final_r, final_b);
    

    
}


pair<pii, pii> findRB()
{
    pii r, b;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'R') {
                r.first = i;
                r.second = j;
                grid[i][j] = '.';
            }
            else if (grid[i][j] == 'B') {
                b.first = i;
                b.second = j;
                grid[i][j] = '.';
            }
        }
    }

    return make_pair(r, b);
}

pair<pii, pii> move(const pii r, const pii b, int k)
{
    int nr1, nc1, nr2, nc2;
    nr1 = r.first;
    nc1 = r.second;
    nr2 = b.first;
    nc2 = b.second;

    bool rok = true, bok = true;
    bool rout = false, bout = false;
    while (rok || bok)
    {

        if (bok) {
            nr2 += dr[k];
            nc2 += dc[k];
        }
        if (rok) {
            nr1 += dr[k];
            nc1 += dc[k];
        }

        // r -> b -> r(recheck)
        if (rok) 
        {
            if (grid[nr1][nc1] == '#') {
                rok = false;
                nr1 -= dr[k];
                nc1 -= dc[k];
            }
            else if (grid[nr1][nc1] == 'O') {
                rok = false;
                rout = true;
            }
            // blue is stop already, and bumpped
            else if (nr1 == nr2 && nc1 == nc2) {
                rok = false;
                nr1 -= dr[k];
                nc1 -= dc[k];
            }
        }

        // b
        if (bok)
        {
            if (grid[nr2][nc2] == '#') {
                bok = false;
                nr2 -= dr[k];
                nc2 -= dc[k];
            }
            else if (grid[nr2][nc2] == 'O') {
                bok = false;
                bout = true;
            }
            // r is blocked or already stopped and b get to r
            else if (nr2 == nr1 && nc2 == nc1) { 
                bok = false;
                nr2 -= dr[k];
                nc2 -= dc[k];
            }

        }

        // r again (not blocked, not out) (checking overlapping with blue)
        if (rok)
        {
            if (nr1 == nr2 && nc1 == nc2) {
                rok = false;
                nr1 -= dr[k];
                nc1 -= dc[k];
            }

        }



    } // while

    if ( bout) { // fail
        return make_pair(pii{ -2,0 }, pii{ 0,0 });
    }
    else // red out or no out, need to check red loc
        return make_pair(pii{ nr1, nc1 }, pii{ nr2, nc2 });
}

pair<pii, pii> bfs(pii r, pii b)
{
    queue<pair<pii, pii>> q;
    memset(dist, -1, sizeof(dist));
    
    dist[r.first][r.second][b.first][b.second] = 0;
    q.emplace(r, b);
    Prev[r.first][r.second][b.first][b.second] = make_pair(r, b);

    while (!q.empty())
    {
        pii r_cur, b_cur;
        tie(r_cur, b_cur) = q.front(); q.pop();
        int d = dist[r_cur.first][r_cur.second][b_cur.first][b_cur.second];

        if (d >= 11) return make_pair(pii{ -1,0 }, pii{ 0,0 });
        if (grid[r_cur.first][r_cur.second] == 'O')
            return make_pair(r_cur, b_cur);

        pii nr, nb;
        for (int k = 0; k < 4; ++k) 
        {
            tie(nr, nb) = move(r_cur, b_cur, k);

            // blue out or already visited
            if (nr.first == -2) continue;         
            if (dist[nr.first][nr.second][nb.first][nb.second] != -1)
                continue;

            dist[nr.first][nr.second][nb.first][nb.second] = d + 1;
            Prev[nr.first][nr.second][nb.first][nb.second] =
                make_pair(r_cur, b_cur);
            q.emplace(nr, nb);
        }
    }

    return make_pair(pii{ -1,0 }, pii{ 0,0 });
}

void print_path(pii r, pii b)
{
    

    vector<char> ans;

    while (Prev[r.first][r.second][b.first][b.second] != pair<pii,pii>(r, b))
    {
        pii prev_r, prev_b;
        tie(prev_r, prev_b) = Prev[r.first][r.second][b.first][b.second];
        
        int y_diff_r = r.first - prev_r.first;
        int y_diff_b = b.first - prev_b.first;
        int x_diff_r = r.second - prev_r.second;
        int x_diff_b = b.second - prev_b.second;

        // 우로 이동
        if (x_diff_r > 0 || x_diff_b > 0) {
            ans.push_back('R');
        }
        else if (x_diff_r < 0 || x_diff_b < 0) {
            ans.push_back('L');
        }
        else if (y_diff_r > 0 || y_diff_b > 0) {
            ans.push_back('D');
        }
        else
            ans.push_back('U');

        r = prev_r;
        b = prev_b;
    }

    for (int i = (int)ans.size() - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << endl;
}