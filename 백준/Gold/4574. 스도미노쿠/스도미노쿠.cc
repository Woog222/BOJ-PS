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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;

int dr[] = { 1, 0 };
int dc[] = { 0, 1 };

int GRID[9][9];
bool USE[10][10];
bool col[9][10];
bool row[9][10];
bool sq[9][10];
int N;

inline int square(int r, int c)
{
    return (r / 3) * 3 + (c / 3);
}
inline bool valid(int r, int c) {
    return r >= 0 && r < 9 && c >= 0 && c < 9;
}
inline bool possible(int r, int c, int num)
{
    return  !(col[c][num] || row[r][num] || sq[square(r, c)][num]);

}
void input(); // clear
bool fun(int k);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 1;
    while (true) {
        cin >> N;
        if (N == 0) break;

        input(); // RESET AND GET INPUT


        fun(0);


        cout << "Puzzle " << cnt++ << '\n';
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << GRID[i][j];
            }
            cout << '\n';
        }
    }
}


void input()
{
    memset(GRID, 0, sizeof(GRID));
    memset(USE, false, sizeof(USE));
    memset(col, false, sizeof(col));
    memset(row, false, sizeof(col));
    memset(sq, false, sizeof(col));

    for (int i = 0; i < N; ++i) {
        int a, b;
        string c, d;
        cin >> a >> c >> b >> d;

        USE[a][b] = USE[b][a] = true;
        GRID[c[0] - 'A'][c[1] - '1'] = a;
        GRID[d[0] - 'A'][d[1] - '1'] = b;

        row[c[0] - 'A'][a] = row[d[0] - 'A'][b] = true;
        col[c[1] - '1'][a] = col[d[1] - '1'][b] = true;
        sq[square(c[0] - 'A', c[1] - '1')][a] = true;
        sq[square(d[0] - 'A', d[1] - '1')][b] = true;
    }

    for (int i = 1; i <= 9; ++i) {
        string temp; cin >> temp;
        GRID[temp[0] - 'A'][temp[1] - '1'] = i;
        
        row[temp[0] - 'A'][i] = true;
        col[temp[1] - '1'][i] = true;
        sq[square(temp[0] - 'A', temp[1] - '1')][i] = true;
    }
}

bool fun(int k)
{
    if (k == 81)
        return true;

    int r = k / 9;
    int c = k % 9;

    if (GRID[r][c] != 0)
        return fun(k + 1);

    // GRID[r][c] is 0!
    // i : here, j : there
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j || USE[i][j] || !possible(r, c, i) ) continue;
            
            //UP DOWN
            for (int dir = 0; dir < 2; ++dir) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (!valid(nr, nc) || GRID[nr][nc] != 0 || !possible(nr, nc, j))
                    continue;

                GRID[nr][nc] = j;
                GRID[r][c] = i;
                row[r][i] = row[nr][j] = true;
                col[c][i] = col[nc][j] = true;
                USE[i][j] = USE[j][i] = true;
                sq[square(r, c)][i] = sq[square(nr, nc)][j] = true;

                if (fun(k + 1))
                    return true;

                GRID[nr][nc] = 0;
                GRID[r][c] = 0;
                row[r][i] = row[nr][j] = false;
                col[c][i] = col[nc][j] = false;
                USE[i][j] = USE[j][i] = false;
                sq[square(r, c)][i] = sq[square(nr, nc)][j] = false;
            }
        }
    }

    return false;
}