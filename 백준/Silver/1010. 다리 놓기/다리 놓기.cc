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
const ll INF = numeric_limits<ll>::min();
const int MAX = 1000;


ll cache[50][50];

ll bc(int n, int k) {
    if (k == 0 || n==k ) return 1;

    ll& ret = cache[n][k];
    if (ret != -1) return ret;

    ret = 0;
    ret += bc(n - 1, k);
    ret += bc(n - 1, k - 1);
    return ret;
}
int main() {
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        cout << bc(b, a) << el;
    }

}
