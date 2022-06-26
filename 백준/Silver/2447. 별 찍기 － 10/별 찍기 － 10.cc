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
char grid[6562][6562];
void fun(int r, int c, int size);

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            grid[i][j] = ' ';
        }
        grid[i][n] = '\0';
    }    
    fun(0, 0, n);

    for (int i = 0; i < n; ++i) {
        printf("%s\n", grid[i]);
    }
   
}

void fun(int r, int c, int size)
{
    if (size == 1) {
        grid[r][c] = '*';
        return;
    }

    int nsize = size / 3;
    for (int k = 0; k < 8; ++k) {
        int nr = r + dr[k] * nsize;
        int nc = c + dc[k] * nsize;
        fun(nr, nc, nsize);
    }
}
