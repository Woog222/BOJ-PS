#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <cmath>
#include <list>
#include <stack>
#include <assert.h>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <climits>
#include <cstdio>
#define el '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 1000000007;

int cache[1000001];
int fun(int num);
void fun2(int num, int left);
int main() 
{
    int n; cin >> n;
    memset(cache, -1, sizeof(cache));
    cout << fun(n) << el;
    fun2(n, fun(n));
}

int fun(int num) {
    if (num == 1)
        return 0;

    int& ret = cache[num];
    if (ret != -1)
        return ret;

    ret = fun(num - 1) + 1;
    if (num % 3 == 0)
        ret = min(ret, fun(num / 3) + 1);
    if (num % 2 == 0)
        ret = min(ret, fun(num / 2) + 1);
    return ret;
}

void fun2(int num, int left) {
    if (num == 1) {
        cout << 1 << el;
        return;
    }
    cout << num << " ";

    if (fun(num - 1) == left - 1)
        fun2(num - 1, left-1);
    else if (num % 3 == 0 && fun(num / 3) == left - 1)
        fun2(num / 3, left-1);
    else if (num % 2 == 0 && fun(num / 2) == left - 1)
        fun2(num / 2, left - 1);

}