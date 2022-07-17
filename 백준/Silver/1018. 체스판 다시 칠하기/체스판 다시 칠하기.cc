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

string grid[50];

int fun(int r, int c);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> grid[i];
    int ans = INF;
    for (int i = 0; i + 8 <= n; ++i) {
        for (int j = 0; j + 8 <= m; ++j) {
            ans = min(ans, fun(i, j));
        }
    }


    cout << ans << endl;
}

int fun(int r, int c)
{
    // : 짝수(W) && 홀수(B)
    int a = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
        {
            char letter = ((r+c+i + j) % 2 == 0) ? 'W' : 'B';
            if (grid[r+i][c+j] != letter)
                a++;

        }
    }

    int b = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
        {
            char letter = ((r+c+i + j) % 2 == 1) ? 'W' : 'B';
            if (grid[r+i][c+j] != letter)
                b++;
        }
    }

    return min(a, b);
}