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
int grid[33][33];
ll cache[33][33][3];

ll fun(int r, int c, int s);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> grid[i][j];

    memset(cache, -1, sizeof(cache));
    cout << fun(1, 2, 0) << endl;
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


inline bool valid(int r, int c)
{
    return r >= 1 && r <= N&& c >= 1 && c <= N;
}

ll fun(int r, int c, int s)
{
    if (!valid(r, c) || grid[r][c] == 1 )
        return 0;
    if (r == N && c == N)
        return 1;

    ll& ret = cache[r][c][s];
    if (ret != -1)
        return ret;

    ret = 0;
    if (s == 0) // horizontal
    {
        ret = fun(r, c + 1, 0);
        if (valid(r + 1, c + 1) && grid[r + 1][c] == 0 && grid[r][c + 1] == 0)
            ret += fun(r + 1, c + 1, 2);
    }
    else if (s == 1) // vertical
    {
        ret = fun(r + 1, c, 1);
        if (valid(r + 1, c + 1) && grid[r + 1][c] == 0 && grid[r][c + 1] == 0)
            ret += fun(r + 1, c + 1, 2);
    }
    else // diagonal
    {
        ret = fun(r + 1, c, 1) + fun(r, c + 1, 0);
        if (valid(r + 1, c + 1) && grid[r + 1][c] == 0 && grid[r][c + 1] == 0)
            ret += fun(r + 1, c + 1, 2);
    }

    return ret;
}