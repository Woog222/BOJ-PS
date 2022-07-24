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
const double MAX = 500000000000.0;

string s;
int cache[2500][2500];
int cache2[2500][2501];
int fun(int idx, int start);

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    cin >> s;
    cout << fun(0, -1) << el;
}

int isPalindrome(int lo, int hi)
{
    if (lo >= hi)
        return 1;

    int& ret = cache[lo][hi];
    if (ret != -1)
        return ret;

    if (s[lo] == s[hi])
        return ret = isPalindrome(lo + 1, hi - 1);
    else
        return ret = 0;
}

//0,-1
int fun(int idx, int start)
{
    if (idx == s.length()) {
        if (start == -1)
            return 0;
        else
            return INF;
    }
    
    int& ret = cache2[idx][(start == -1) ? 2500 : start];
    if (ret != -1)
        return ret;

    ret = INF;
    if (start == -1) {
        ret = min(fun(idx + 1, -1) + 1, fun(idx + 1, idx));
    }
    else {
        if (isPalindrome(start, idx)) 
            ret = min(ret, fun(idx + 1, -1) + 1);
        ret = min(ret, fun(idx + 1, start));
    }

    return ret;
}