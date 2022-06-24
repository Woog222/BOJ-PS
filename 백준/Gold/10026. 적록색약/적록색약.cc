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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int dr[] = { 0,1,-1,0 };
int dc[] = { 1,0,0,-1 };

int N;
string grid[100];

inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < N;
}
void dfs(int r, int c, int grp, vvi& group);
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];


    int grp1 = 0;
    vvi group(N, vi(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (group[i][j] == 0) {
                dfs(i, j, ++grp1, group);
            }
        }
    }

    cout << grp1 << endl;

    /********************************************************************/


    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'R')
                grid[i][j] = 'G';
        }
    }



    /********************************************************************/
    int grp2 = 0;
    vvi(N, vi(N, 0)).swap(group);




    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (group[i][j] == 0) {
                dfs(i, j, ++grp2, group);
            }
        }
    }

    cout << grp2 << endl;
}

void dfs(int r, int c, int grp, vvi& group) {
    group[r][c] = grp;

    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];
        if (!valid(nr, nc)) continue;
        if (grid[r][c] == grid[nr][nc] && group[nr][nc] == 0)
            dfs(nr, nc, grp, group);
    }
}
