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
#define el '\n';
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000000;
const int ALL = (1 << 10) - 1;

int N;
int cache[100][10][1<<10];

int fun(int idx, int prev, int selected);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N; 
    cout << fun(0, 0, 0) << el;
}

// 1, 1~9, 1~9따라
int fun(int idx, int prev, int selected)
{
    if (idx == N) {
        if (selected == ALL)
            return 1;
        else
            return 0;
    }
 
    int& ret = cache[idx][prev][selected];
    if (ret != -1)
        return ret;

    ret = 0;
    if (idx == 0) {
        for (int now = 1; now <= 9; ++now)
            ret = (ret+ fun(idx + 1, now, 1 << now)) %MOD;
        return ret;
    }

    int now = prev - 1;
    if (0 <= now && now <= 9)
        ret = (ret + fun(idx + 1, now, selected | (1 << now))) % MOD;
    now = prev + 1;
    if (0 <= now && now <= 9)
        ret = (ret + fun(idx + 1, now, selected | (1 << now))) % MOD;
    return ret;
}