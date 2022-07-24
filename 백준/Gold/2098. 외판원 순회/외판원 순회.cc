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

int N;
int w[16][16];
int cache[16][1 << 16];
int ALLVISIT;
int fun(int here, int visited);

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N;
    ALLVISIT = (1 << N) - 1;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            cin >> w[i][j];

    memset(cache, -1, sizeof(cache));
    cout << fun(0, 1) << el;

}

int fun(int here, int visited)
{
    if (visited == ALLVISIT) {
        if (w[here][0] > 0)
            return w[here][0];
        else
            return INF;
    }
    int& ret = cache[here][visited];
    if (ret != -1)
        return ret;

    ret = INF;
    for (int next = 0; next < N; ++next) {
        if (visited & (1 << next) || w[here][next] == 0) continue;
        ret = min(ret, fun(next, visited | (1 << next)) + w[here][next]);
    }

    return ret;
}