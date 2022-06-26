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
#include <ctime>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int dr[] = { 0,0,0,1,1,2,2,2 };
int dc[] = { 0,1,2,0,2,0,1,2 };
char grid[3072][6143 + 1];
void fun(int r, int c, int size);

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int h, w;
    cin >> h;
    w = (h / 3) * 5 + (h / 3 - 1);

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            grid[i][j] = ' ';
        }
        grid[i][w] = '\0';
    }

    fun(0, w / 2, h);
   
    for (int i = 0; i < h; ++i)
        cout << grid[i] << '\n';
}

void fun(int r, int c, int height)
{
    if (height == 3) {
        grid[r][c] = '*';
        grid[r + 1][c - 1] = grid[r + 1][c + 1] = '*';
        grid[r + 2][c - 2] = grid[r + 2][c - 1] = grid[r + 2][c] =
            grid[r + 2][c + 1] = grid[r + 2][c + 2] = '*';
        return;
    }

    
    int nheight = height / 2;
    int width = nheight / 3 * 5 + nheight / 3 - 1;
    int col_diff = width / 2 + 1;
    

    fun(r, c, nheight);
    fun(r + nheight, c - col_diff, nheight);
    fun(r + nheight, c + col_diff, nheight);
    return;
}
