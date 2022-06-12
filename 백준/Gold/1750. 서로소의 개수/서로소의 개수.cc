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
const int INF = 987654321;
const int MOD = 10000003;

int n;
int arr[51];
int dp[51][100001]; // n까지 고려, 최대공약수, 고른적 있는지

int GCD(int a, int b) 
{
    // a > b
    if (a < b)
        swap(a, b);

    int mod;
    while (b != 0) {
        mod = a % b;
        a = b;
        b = mod;
    }

    return a;
}

int fun(int nth, int gcd) // nth고려할 차례
{
    if (nth > n) {
        if (gcd == 1 )
            return 1;
        else
            return 0;
    }
        

    int& ret = dp[nth][gcd];
    if (ret != -1)
        return ret;

    ret = 0;
    // not pick
    ret = (ret + fun(nth + 1, gcd)) % MOD;
    // pick
    ret = (ret + fun(nth + 1, (gcd == 0) ? arr[nth] : GCD(arr[nth], gcd))) % MOD;

    return ret;
}

int main()
{   
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));
    cout << fun(1, 0) << endl;
}
