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
int dr[] = { 0, 1, 0,-1 };
int dc[] = { 1, 0,-1, 0 };

int dist[10][10][10][10];
string grid[10];

int N, M;

pair<pii, pii> findRB(); // clear
// red only out : r.first = -1
// both out or blut out : r.first = -2
// just moved : location
pair<pii, pii> move(const pii r, const pii b, int k); // clear
int fun(pii r, pii b, int nth);

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    pii r, b; tie(r, b) = findRB();

    int ans = (fun(r, b, 0) > 0) ? 1 : 0;
    cout << ans << endl;
    
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
    else if (rout ) // rout only
        return make_pair(pii{ -1,0 }, pii{ 0,0 });
    else // no out
        return make_pair(pii{ nr1, nc1 }, pii{ nr2, nc2 });
}

int fun(pii r, pii b, int nth)
{
    if (r.first == -1)
        return nth;

    if (nth >= 10)
        return -1; // FAIL under 10;

    int ret = 11;
    pii nr, nb;
    // 우 하 좌 상
    for (int k = 0; k < 4; ++k) 
    {
        tie(nr, nb) = move(r, b, k);
        if (nr.first == -2) continue; // FAIL (BLUE OUT)

        int temp;
        if ((temp = fun(nr, nb, nth + 1)) > 0)
            ret = min(ret, temp);
    }

    if (ret == 11)
        return -1; //FAIL
    else
        return ret;
}