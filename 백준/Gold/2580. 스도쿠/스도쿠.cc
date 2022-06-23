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

int grid[9][9];
bool col[9][10];
bool row[9][10];
bool sq[9][10];

int N = 9;

inline int square(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}
bool fun(int k);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 0) continue;

            row[i][grid[i][j]] = true;
            col[j][grid[i][j]] = true;
            sq[square(i, j)][grid[i][j]] = true;
        }
    }
    
    fun(0);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}

bool fun(int a)
{
    if (a == 81) {
        return true;
    }
        

    int r = a / 9;
    int c = a % 9;

    if ( grid[r][c] != 0 )
        return fun(a + 1);

    for (int k = 1; k <= 9; ++k) {
        if (!row[r][k] && !col[c][k] && !sq[square(r, c)][k]) 
        {
            grid[r][c] = k;
            row[r][k] = true;
            col[c][k] = true;
            sq[square(r, c)][k] = true;

            if (fun(a + 1))
                return true;

            grid[r][c] = 0;
            row[r][k] = false;
            col[c][k] = false;
            sq[square(r, c)][k] = false;
        }
    }

    return false;
}
