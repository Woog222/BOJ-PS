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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int INF = 987654321;

int N;
int E[10];
bool USE[10];

int fun(int left);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> E[i];

    cout << fun(N) << endl;
}

int fun(int now)
{
    if (now == 2)
        return 0;

    int ret = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (USE[i]) continue;

        int left=i-1, right=i+1;
        while (left >=0 && USE[left] ) left--;
        while (right < N && USE[right]) right++;

        if (left<0 || right>=N) continue;

        USE[i] = true;
        ret = max(ret, E[left] * E[right] + fun(now - 1));
        USE[i] = false;
    }

    return ret;
}
