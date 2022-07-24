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
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;

vi order;

int cache[100000][5][5];
int cost[5][5];
int fun(int idx, int left, int right);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    
    while (true) {
        int num; cin >> num;
        if (num == 0) break;
        order.push_back(num);
    }

    cost[0][1] = cost[0][2] = cost[0][3] = cost[0][4] = 2;
    cost[1][2] = cost[2][3] = cost[3][4] = cost[4][1] = 3;
    cost[2][1] = cost[3][2] = cost[4][3] = cost[1][4] = 3;
    cost[1][3] = cost[3][1] = cost[2][4] = cost[4][2] = 4;
    cost[1][1] = cost[2][2] = cost[3][3] = cost[4][4] = 1;

    memset(cache, -1, sizeof(cache));
    cout << fun(0, 0, 0) << el;
}

int fun(int idx, int left, int right)
{
    if (idx == order.size()) 
        return 0;

    int& ret = cache[idx][left][right];
    if (ret != -1)
        return ret;

    int next = order[idx];
    ret = min(fun(idx + 1, next, right) + cost[left][next],
              fun(idx + 1, left, next)  + cost[right][next]
        );
    return ret;
}