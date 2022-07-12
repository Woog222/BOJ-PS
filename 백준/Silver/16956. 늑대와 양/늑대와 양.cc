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
const int MOD = 1000000007;

int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };

string grid[500];
int N, M;
bool fun();
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> grid[i];

    if (fun()) {
        cout << "1\n";
        for (int i = 0; i < N; ++i) {
            cout << grid[i] << '\n';
        }
    }
    else
        cout << 0 << endl;
}
inline bool valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}
bool fun()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) 
        {
            if (grid[i][j] != 'S') continue;

            for (int k = 0; k < 4; ++k) {
                int nr = i + dr[k];
                int nc = j + dc[k];
                if (!valid(nr, nc)) continue;
                if (grid[nr][nc] == 'W')
                    return false;
                else if (grid[nr][nc] == '.')
                    grid[nr][nc] = 'D';
            }
        }
    }
    return true;
}