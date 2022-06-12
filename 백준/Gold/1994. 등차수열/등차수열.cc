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
const ll MOD = 1000000007;

int n;
int arr[2000];
int dp[2000][2000]; // i, j를 포함하는 등차수열 최대 길이

int bi_search(int from, int to, int target) // from 부터 to까지 target 찾아서 idx, 없으면 -1
{
    int left = from;
    int right = to;

    int lower_bound_idx = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] > target) {
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            lower_bound_idx = mid;
            right = mid - 1;
        }
    }

    return lower_bound_idx;
}

int fun(int prev_idx, int idx, int len)
{
    int& ret = dp[prev_idx][idx];
    if (ret > 0)
        return ret;

    int next_target = arr[idx] + (arr[idx] - arr[prev_idx]);
    int next_idx = bi_search(idx + 1, n - 1, next_target);

    // 더 이상 이어지는 등차수열 멤버를 찾을 수 없음
    if (next_idx == -1) {
        return ret = len;
    }

    // 찾았다면 재귀
    return ret = fun(idx, next_idx, len + 1);
}


int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    sort(arr, arr + n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans = max(ans, fun(i, j, 2));
        }
    }


    cout << ans << endl;
}