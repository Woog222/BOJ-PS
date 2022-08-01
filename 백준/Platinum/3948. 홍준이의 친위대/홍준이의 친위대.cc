#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> pii;
const int INF = 1000000001;
const int MOD = 1000000007;

ll dp[21][2]; // 0 : up, 1 : down
ll bc[21][21];

void cal_bc()
{
    bc[1][0] = bc[1][1] = 1;
    for (int i = 2; i <= 20; ++i) {
        bc[i][0] = bc[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            bc[i][j] = bc[i - 1][j - 1] + bc[i - 1][j];
        }
    }
}   

int main()
{
    cal_bc();
    // 0 : up, 1 : down
    dp[0][1] = dp[0][0] = 1;
    dp[1][1] = dp[1][0] = 1;

    for (int i = 2; i <= 20; ++i) {
        
        for (int k = 1; k <= i; ++k) {
            int left = k - 1;
            int right = i - k;

            if (k & 1) { // up
                dp[i][0] += bc[i - 1][left] * dp[left][0] * dp[right][1];
            }
            else { // down
                dp[i][1] += bc[i - 1][left] * dp[left][1] * dp[right][1];
            }
        } // k : 1의 위치
    }
    dp[1][1] = 0;





    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << dp[n][0] + dp[n][1] << '\n';
    }
}