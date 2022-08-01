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

struct Element {
    int r, c, h;

    bool operator < (const Element& b) {
        return h < b.h;
    }
};

int dr[] = { 0,0,-1,1 };
int dc[] = { 1,-1,0,0 };
int N, M;
int grid[500][500], dp[500][500];
vector <Element> elements;

inline bool valid(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}
int main()
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
            elements.push_back(Element{ i,j,grid[i][j]});
        }
    sort(elements.begin(), elements.end());

    dp[N - 1][M - 1] = 1;
    for (int i = 0; i < (int)elements.size(); ++i) {
        int r = elements[i].r;
        int c = elements[i].c;
        int h = elements[i].h;

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (valid(nr, nc) && grid[nr][nc] < h)
                dp[r][c] += dp[nr][nc];
        }
    }
    cout << dp[0][0] << el;
}