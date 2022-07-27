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
const ll MOD = 100000;

int N;
vi beer;
int cache[1000][1000];
vi member[101];


int fun(int lo, int hi);
int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> N; beer.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> beer[i];
        member[beer[i]].push_back(i);
    }
    memset(cache, -1, sizeof(cache));
    cout << fun(0, N - 1) << el;
}
inline bool inBoundary(int lo, int hi, int i) {
    return lo < i&& i <= hi;
}
int fun(int lo, int hi)
{
    //int num = (lo <= hi) ? (hi - lo + 1) : (hi + N - lo+1);
    int num = hi - lo + 1;
    if (num <= 1) return 0;
    
    int& ret = cache[lo][hi];
    if (ret != -1) return ret;
    // pass
    ret = fun(lo + 1, hi);
    //choose
    for (int i : member[beer[lo]]) {
        if (inBoundary(lo,hi,i)) ret = max(ret,
            fun(lo + 1, i- 1 ) + fun(i + 1 , hi)+1);
    }


    return ret;
}