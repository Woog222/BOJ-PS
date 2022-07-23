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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
const int INF = 987654321;
const int MOD = 10007;

int n, m;
string a, b;
int cache[41][41];

int fun(int i, int j);
string fun2(int i, int j);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    cin >> a >> b;
    a = "x" + a;
    b = "x" + b;
    n = a.size(); m = b.size();

    memset(cache, -1, sizeof(cache));
    cout << fun2(0, 0)<< '\n';

}

string fun2(int i, int j) 
{
    int cnt = 0;
    pii next = { -1,-1 };
    for (int ni = i + 1; ni < n; ++ni) {
        for (int nj = j + 1; nj < m; ++nj) {
            if (a[ni] == b[nj]) {
                if (fun(ni, nj) > cnt) {
                    cnt = fun(ni, nj);
                    next = pii(ni, nj);
                }
            }    
        }
    }
    if (next == pii{-1, -1})
        return string(1,a[i]);

    if (i == 0 && j == 0)
        return fun2(next.first, next.second);
    else
        return a[i] + fun2(next.first, next.second);
}
// 0,0
int fun(int i, int j)
{

    int& ret = cache[i][j];
    if (ret != -1)
        return ret;

    ret = 1;
    for (int ni = i + 1; ni < n; ++ni) {
        for (int nj = j + 1; nj < m; ++nj) {
            if (a[ni] == b[nj])
                ret = max(ret, fun(ni, nj) + 1);
        }
    }

    return ret;
}