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


int n;
int dp[401][401][401];


int main()
{
    cin >> n;
    vi a, b;
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        if (temp != 0)
            a.push_back(temp);
    }
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        if (temp != 0)
            b.push_back(temp);
    }

    int a_len = a.size();
    int b_len = b.size();
    if (a_len == 0 || b_len == 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = 0;

    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a_len; ++j) {
            for (int k = 1; k <= b_len; ++k) {
                if (j > i || k > i) continue;

                int temp = dp[i - 1][j - 1][k - 1] + a[j - 1] * b[k - 1];
                if (j <= i-1) {
                    temp = max(temp, dp[i - 1][j][k - 1]);
                }
                if (k <=  i-1) {
                    temp = max(temp, dp[i - 1][j - 1][k]);
                }
                if (j<=i-1 && k<=i-1) {
                    temp = max(temp, dp[i - 1][j][k]);
                }
                
                dp[i][j][k] = temp;
            }
        }
    }

    cout << dp[n][a_len][b_len] << endl;
}