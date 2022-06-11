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
const int INF = -987654321;
const int NO_RESULT = -987654322;


int n, m;
int cache[101][51];
int arr[101];
int ps[101];

void cal_ps()
{
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + arr[i];
    }
}



// include now or not
int fun(int now, int nth)
{
    if (now > n ) {
        if (nth == m )
            return 0;
        else
            return NO_RESULT; // INF > NO_RESULT, 갱신안됨
    }
    if (nth == m )
        return 0;

    int& ret = cache[now][nth];
    if (ret != INF)
        return ret;

    ret = -40000000;
    // no include
    ret = max(ret, fun(now + 1, nth));
    // include from now to end
    for (int end = now; end <= n; ++end) {
        int temp = fun(end + 2, nth + 1);
        if (temp != NO_RESULT) {
            ret = max(ret, temp + ps[end] - ps[now - 1]);
        }
    }


    return ret;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cache[i][j] = INF;
        }
    }
    cal_ps();

    cout << fun(1, 0) << endl;

}