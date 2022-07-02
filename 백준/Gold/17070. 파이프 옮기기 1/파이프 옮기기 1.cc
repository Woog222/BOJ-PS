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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;


int N; 
int grid[17][17];
int cache[17][17][3];

int fun(int r, int c, int s);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> grid[i][j];

    memset(cache, -1, sizeof(cache));
    cout << fun(N, N, 0) + fun(N,N,1) + fun(N,N,2) << endl;
    /*
    for (int s = 0; s < 3; ++s) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                cout << cache[i][j][s] << " ";
            }
            cout << endl;
        }
        cout << "\n\n";
    }
    */
}

int fun(int r, int c, int s)
{
    if (c <= 1 || r < 1 || grid[r][c] == 1)
        return 0;
    if (r == 1 && c == 2 && s == 0)
        return 1;

    int& ret = cache[r][c][s];
    if (ret != -1)
        return ret;

    ret = 0;
    if (s == 0) // horizontal
    {
        ret = fun(r, c - 1, 0) + fun(r, c - 1, 2);
    }
    else if (s == 1) //vertical
    {
        ret = fun(r - 1, c, 1) + fun(r - 1, c, 2);
    }
    else //diagonal
    {
        if (grid[r][c - 1] == 0 && grid[r - 1][c] == 0)
            ret = fun(r - 1, c - 1, 0) + fun(r - 1, c - 1, 1) + fun(r - 1, c - 1, 2);
    }
    
    return ret;
}