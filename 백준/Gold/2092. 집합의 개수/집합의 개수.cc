#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1000000;

int t, n, s, b;
int dp[4001][201]; // n, k/ k이하 숫자들로 이루어진 집합의 수
int arr[4000];
int cnt[201]; // i의 등장 횟수, 순서는 중요하지 않고 몇개 있냐가 중요



int main()
{
    cin >> t >> n >> s >> b;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }
        
    dp[0][0] = 1;
    for (int i = 1; i <= t; ++i) {
        dp[1][i] = dp[1][i-1] + ( (cnt[i]>0) ? 1 : 0 );
        dp[0][i] = 1;
    }

    for (int i = 2; i <= b; ++i) {
        for (int k = 1; k <= t; ++k) {
            // no k
            dp[i][k] = dp[i][k - 1];
            // has k
            int last_idx = min(cnt[k], i);
            // j : how many k included
            for (int j = 1; j <= last_idx; ++j) {
                dp[i][k] = ( dp[i][k] + dp[i - j][k - 1] ) % MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = s; i <= b; ++i) {
        ans += dp[i][t];
    }
    cout << ans % MOD << endl;
}