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
const int FAIL = -987654321;

int n;
int h[51];
int dp[51][500001];

int fun(int nth, int diff) 
{
    // use all 
    if (nth > n) {
        if (diff == 0)
            return 0;
        else
            return FAIL;
    }

    int& ret = dp[nth][diff];
    if (ret != -1)
        return ret;

    int temp_ret = FAIL;
    int temp;
    // no use
    temp = fun(nth + 1, diff);
    if (temp != FAIL)
        temp_ret = max(temp_ret, temp);
    // on to the taller block
    temp = fun(nth + 1, diff + h[nth]);
    if (temp != FAIL)
        temp_ret = max(temp_ret, temp);
    // on to the smaller_block
    if (diff >0 && h[nth] >= diff) {
        temp = fun(nth + 1, h[nth] - diff);
        if (temp!= FAIL)
        temp_ret = max(temp_ret, temp + diff);
    }
    else if (diff > 0) {
        temp = fun(nth + 1, diff - h[nth]);
        if (temp != FAIL)
            temp_ret = max(temp_ret, temp + h[nth]);
    }

    return ret = temp_ret;
}

int main()
{   
    cin >> n; 
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    memset(dp, -1, sizeof(dp));

    int ans = fun(1, 0);
    if (ans == 0) 
        ans = -1;
    cout << ans << endl;
    /*
    for (int i = 1; i <= 3; ++i) {
        for (int j = 0; j <= 21; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
}