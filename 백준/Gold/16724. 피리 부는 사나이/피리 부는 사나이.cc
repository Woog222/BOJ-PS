#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;


string grid[1000];
int N, M;
int cache[1000][1000];

int fun(int r, int c);
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> grid[i];
    memset(cache, -1, sizeof(cache));

    set<int> ans;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            ans.insert(fun(i, j));
    cout << ans.size() << el;
}


int fun(int r, int c) 
{
    int& ret = cache[r][c];
    if (ret >= 0) return ret;
    if (ret == -2) return ret = r * M + c;


    ret = -2;

    char dir = grid[r][c];
    int nr = r, nc = c;
    if (dir == 'D') nr++;
    else if (dir == 'U') nr--;
    else if (dir == 'L') nc--;
    else nc++;

    return ret = fun(nr, nc);
}