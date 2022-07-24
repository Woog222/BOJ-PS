#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
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
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

int grid[100001][3];
int N;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> grid[i][0] >> grid[i][1] >> grid[i][2];
    }

    int dp[2][3];

    // max
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        dp[i % 2][0] = grid[i][0] + max(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
        dp[i % 2][1] = grid[i][1] + max({ dp[(i + 1) % 2][0], dp[(i + 1) % 2][1], dp[(i + 1) % 2][2] });
        dp[i % 2][2] = grid[i][2] + max(dp[(i + 1) % 2][2], dp[(i + 1) % 2][1]);
    }

    int i = N % 2;
    cout << max({ dp[i][0], dp[i][1], dp[i][2] }) << " ";

    //min
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        dp[i % 2][0] = grid[i][0] + min(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1]);
        dp[i % 2][1] = grid[i][1] + min({ dp[(i + 1) % 2][0], dp[(i + 1) % 2][1], dp[(i + 1) % 2][2] });
        dp[i % 2][2] = grid[i][2] + min(dp[(i + 1) % 2][2], dp[(i + 1) % 2][1]);
    }

    cout << min({ dp[i][0], dp[i][1], dp[i][2] }) << '\n';
}