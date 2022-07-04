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
const int MOD = 10000000;


int N, M;
string grid[500];
int state[500][500]; 

// 0 : not covered
// 1 : ok, can out
// 2 : on the way, soon determined
// -1 : cycle,, 

int dfs(int r, int c);
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> grid[i];
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (state[i][j] == 0)
                dfs(i, j);

    int ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (state[i][j] == 1)
                ans++;

    cout << ans << endl;
               

}

inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

pii go(int r, int c) 
{
    char letter = grid[r][c];
    if (letter == 'D')
        return pii(r + 1, c);
    else if (letter == 'R')
        return pii(r, c + 1);
    else if (letter == 'L')
        return pii(r, c - 1);
    else
        return pii(r - 1, c);
}

int dfs(int r, int c)
{
    state[r][c] = 2;

    int nr, nc;
    tie(nr, nc) = go(r, c);

    // can go out
    if (!valid(nr, nc) || state[nr][nc] == 1) 
        return state[r][c] = 1;
    // cycle
    if (state[nr][nc] == 2 || state[nr][nc] == -1)
        return state[r][c] = -1;
    
    return state[r][c] = dfs(nr, nc);
        
}