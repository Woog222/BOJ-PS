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

int pre[10000];
int post[10000];

void fun(int lo, int hi);
int main()
{   
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    
    int idx = 0;
    while (cin >> pre[idx++]);

    fun(0, idx - 2);
    
}

void fun(int lo, int hi)
{
    if (lo > hi)
        return;

    int root = pre[lo];
    int left = lo + 1;
    int right = lo+1;
    for (int i = lo + 1; i <= hi; ++i) {
        if (pre[i] > root) {
            right = i;
            break;
        }
    }

    fun(left, right-1);
    fun(right, hi);
    cout << root << '\n';
}